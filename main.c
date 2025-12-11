#include <stdio.h>
#define IMPROVING 1
#define DECLINING 2
#define STABLE 0

#define DIFFICULTY 0
#define SUCCESS 1
#define TIME 2

/*Function Definitions*/
int check(int[][3], int);
int trend(int, int);
void printResult(int);

/*main function*/
int main(void) {
    /*Variable Definition*/
    int n = 0;


    /*Inputting*/
    scanf("%d", &n);
    int records[n][3];

    for (int i = 0; i < n; i++) {
        /*[difficulty] [success] [time]*/
        scanf("%d %d %d", &records[i][DIFFICULTY], &records[i][SUCCESS], &records[i][TIME]);
    }

    printResult(check(records, n));


    return 0;
}

/*Function Declaration*/

/*check: return the status of the athlete*/
int check(int records[][3], int counter) {
    /*calculating*/
    int avg_difficulty = records[0][DIFFICULTY];
    int running_time_rate = 0, success_rate = 0;
    for (int i = 1; i < counter; i++) {
        running_time_rate = trend(records[i-1][TIME], records[i][TIME]);
        success_rate = trend(records[i-1][SUCCESS], records[i][SUCCESS]);

        avg_difficulty += records[i][DIFFICULTY];
    }
    avg_difficulty = (avg_difficulty / counter);

    /*defining the situations*/
    int time_improvement = (running_time_rate == SUCCESS || running_time_rate == STABLE);
    int time_decline = (running_time_rate == DECLINING || running_time_rate == STABLE);

    int succes_improvement = (success_rate == SUCCESS || success_rate == STABLE);
    int succes_decline = (success_rate == DECLINING || success_rate == STABLE);

    /*validating and returning*/
    if (time_improvement && succes_improvement && avg_difficulty >= 5) {
        return IMPROVING;
    }
    if (time_decline && succes_decline && avg_difficulty < 5) {
        return DECLINING;
    }
    return STABLE;
}

/*trend
 value a: previous value , value b: new value
 returns the trend status.
 */
int trend(int valueA, int valueB) {
    if (valueB > valueA) return IMPROVING;
    if (valueB < valueA) return DECLINING;
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
