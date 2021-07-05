#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(int a, int b)
{
    char *day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int reday = 0;
    for (int i = 1; i <= a - 1; i++)
    {
        if (i == 4 || i == 6 || i == 9 || i == 11)
            reday += 30;
        else if (i == 2)
            reday += 29;
        else
            reday += 31;
    }
    reday += b;
    int result = (reday + 4) % 7;
    char *answer = (char *)malloc(sizeof(day));
    answer = day[result];
    return answer;
}

int main()
{
    int month, day;
    scanf("%d %d", &month, &day);

    char *date = solution(month, day);

    printf("date: %s\n", date);
    free(date);
    return 0;
}