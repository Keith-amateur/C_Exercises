#include <stdio.h>
#include <string.h>
#define LEN 21

char *s_gets(char *st, int n);
struct month {
	char *month_name;
	char month[LEN];
	int days;
};
char *monthcontainers[12] = {"January", "February", "March", "April", "May", "June", 
					"July", "August", "September", "October", "November", "December"};
struct month months[12] = 
{
	{.month = "Jan", .days = 31},
	{.month = "Feb", .days = 28},
	{.month = "Mar", .days = 31},
	{.month = "Apr", .days = 30},
	{.month = "May", .days = 31},
	{.month = "Jun", .days = 30},
	{.month = "Jul", .days = 31},
	{.month = "Aug", .days = 31},
	{.month = "Sep", .days = 30},
	{.month = "Oct", .days = 31},
	{.month = "Nov", .days = 30},
	{.month = "Dec", .days = 31},
};
int main() {
	int sum;
	int i;
	char name[LEN];
	for (i = 0; i < 12; i++) {
		months[i].month_name = monthcontainers[i];
	}
	puts("Enter the month (empty line to quit)");
	while (s_gets(name, LEN) != NULL && name[0] != '\0') {
		for (i = 0; i < 12; i++) {
			if (strcmp(name, monthcontainers[i]) == 0)
				break;
		}
		if (i == 12) {
			puts("Please enter the right month");
			continue;
		}
		int index;
		for (index = 0, sum = 0; index <= i; index++) {
			// printf("%d ", months[index].days);
			sum += months[index].days;
		}
		printf("From January to %s, there are %d days\n", months[i].month_name, sum);
		puts("Enter anonter month:");
	}

	return 0;
}

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find) {
			*find = '\0';
		} else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}
	return ret_val;
}