// 使用queue.c接口
// 与17.7_queue.c 一起编译

#include <stdio.h>
#include <stdlib.h>         // 提供rand()和srand()的函数原型
#include <time.h>           // 提供time()的原型
#include "17.12_4_queue.h"

#define MIN_PER_HOUR  60.0

bool newcustomer(double x);         // 是否有新顾客到来?
Item customertime(long when);       // 设置顾客参数

int main() {
    Queue line;
    Queue line2;
    Item temp;                  // 新的顾客数据
    int hours;                  // 模拟的小时数
    int perhour;                // 每小时平均多少位客人
    long cycle, cyclelimit;     // 循环计数器, 计数器的上限
    long turnaways = 0;         // 因队列已满被拒的顾客数量
    long customers = 0;         // 加入队列的顾客数量
    long customers2 = 0;        // 加入队列2的顾客数量
    long served = 0;            // 在模拟期间咨询过Sigmund的顾客数量
    long served2 = 0;
    long sum_line = 0;          // 累计队伍总长
    long sum_line2 = 0;
    int wait_time = 0;          // 从当前到Sigmund空闲所需的时间
    int wait_time2 = 0;
    double min_per_cust;        // 顾客到来的平均时间
    long line_wait = 0;         // 队列累计的等待时间
    long line_wait2 = 0;

    InitializeQueue(&line);
    InitializeQueue(&line2);
    srand((unsigned int)time(0));           // rand() 随机初始化
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HOUR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HOUR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (QueueIsFull(&line) && QueueIsFull(&line2)) {
                turnaways++;
            } else {
                if (QueueItemCount(&line) <= QueueItemCount(&line2)) {
                    customers++;
                    temp = customertime(cycle);
                    Enqueue(temp, &line);
                } else {
                    customers2++;
                    temp = customertime(cycle);
                    Enqueue(temp, &line2);
                }
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line)) {
            Dequeue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time > 0) {
            wait_time--;
        }

        if (wait_time2 <= 0 && !QueueIsEmpty(&line2)) {
            Dequeue(&temp, &line2);
            wait_time2 = temp.processtime;
            line_wait2 += cycle - temp.arrive;
            served2++;
        }
        if (wait_time2 > 0) {
            wait_time2--;
        }
        sum_line += QueueItemCount(&line);
        sum_line2 += QueueItemCount(&line2);
    }

    if (customers > 0) {
        printf("line1 : customers accepted: %ld\n", customers);
        printf("line1 : customers served: %ld\n", served);
        // printf("turnaways: %ld\n", turnaways);
        printf("line1 : average queue size: %.2f\n", (double)sum_line / cyclelimit);
        printf("line1 : average wait time: %.2f minutes\n", (double)line_wait / served);
    } else {
        puts("No customers");
    }
    putchar('\n');
    if (customers2 > 0) {
        printf("line2 : customers accepted: %ld\n", customers2);
        printf("line2 : customers served: %ld\n", served2);
        // printf("turnaways: %ld\n", turnaways);
        printf("line2 : average queue size: %.2f\n", (double)sum_line2 / cyclelimit);
        printf("line2 : average wait time: %.2f minutes\n", (double)line_wait2 / served2);
    } else {
        puts("No customers");
    }
    printf("turnaways: %ld\n", turnaways);
    EmptyTheQueue(&line);
    EmptyTheQueue(&line2);
    puts("Bye!");

    return 0;
}

// x : 顾客到来的平均时间
//如果1分钟内有顾客到来, 则返回true
bool newcustomer(double x) {
    if (rand() * x / RAND_MAX < 1) {
        return true;
    } else {
        return false;
    }
}

Item customertime(long when) {
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
