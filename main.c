#include <stdio.h>
#define IMPROVING 1
#define DECLINING 2
#define STABLE 0

#define DIFFICULTY 0
#define SUCCESS 1
#define TIME 2

int check(int[][3], int);
void printResult(int);

int main(void) {
    /*Variable Definition*/
    int n = 0;


    /*Inputting*/
    scanf("%d", &n);
    int records[n][3];

    scanf("%d %d %d", &records[0][DIFFICULTY], &records[0][SUCCESS], &records[0][TIME]);

    for (int i = 1; i < n; i++) {
        /*[difficulty] [success] [time]*/
        scanf("%d %d %d", &records[i][DIFFICULTY], &records[i][SUCCESS], &records[i][TIME]);
    }

    printResult(check(records, n));


    return 0;
}

/*check: return the status of the athlete*/
int check(int records[][3], int counter) {
    int avg_difficulty = 0;
    int running_time_rate = 0, success_rate = 0;

    for (int i = 0; i < counter; i++) {
        if (records[i][TIME] > records[i-1][TIME]) {
            running_time_rate = IMPROVING;
        }
        else if (records[i][TIME] < records[i-1][TIME]) {
            running_time_rate = DECLINING;
        }
        else {
            running_time_rate = STABLE;
        }

        if (records[i][SUCCESS] > records[i-1][SUCCESS]) {
            success_rate = IMPROVING;
        }
        else if (records[i][SUCCESS] < records[i-1][SUCCESS]) {
            success_rate = DECLINING;
        }
        else {
            success_rate = STABLE;
        }

        avg_difficulty += records[i][DIFFICULTY];
    }
    avg_difficulty = (avg_difficulty / counter);

    if ((running_time_rate == SUCCESS || running_time_rate == STABLE) && (success_rate == SUCCESS || success_rate == STABLE) && avg_difficulty >= 5) {
        return IMPROVING;
    }
    if ((running_time_rate == DECLINING || running_time_rate == STABLE) && (success_rate == DECLINING || success_rate == STABLE) && avg_difficulty < 5) {
        return DECLINING;
    }
    return STABLE;

}

/*printResult does the print job*/
void printResult(int status) {
    if (status == IMPROVING) {
        printf("Athlete Status: Improving\n");
    }
    else if (status == DECLINING) {
        printf("Athlete Status: Declining\n");
    }
    else if (status == STABLE) {
        printf("Athlete Status: Stable\n");
    }
}