#include <stdio.h>
#define MINcoef 60
#define SlEEPintercept 5
#define True 1
#define False 0

/*Function Definitions*/
int calculate_sleep_minutes(const int sleep_time[], const int wake_time[]);
int is_irregular(int sleep_hour, int wake_hour);
int is_low(int sleep_minutes);

/*main function*/
int main(void) {
    /*Variable Definitions*/
    int sleep_time[2] = {00,00};
    int wake_time[2] = {00,00};
    int total_sleep = 0, nights_number =0;
    int low_sleep_count = 0, irregular_sleep_count = 0;

    /*Inputting*/
    scanf("%d", &nights_number);
    for (int i = 0; i < nights_number; i++) {
        scanf("%2d%2d-%2d%2d", &sleep_time[0], &sleep_time[1], &wake_time[0], &wake_time[1]);

        int sleep_min = calculate_sleep_minutes(sleep_time, wake_time);
        total_sleep += sleep_min;
        low_sleep_count += is_low(sleep_min);
        irregular_sleep_count += is_irregular(sleep_time[0], wake_time[0]);
    }
    float avg_sleep = (float) total_sleep / nights_number;

    printf("Total Sleep: %d minutes\n", total_sleep);
    printf("Average Sleep: %.2f minutes\n", avg_sleep);
    printf("Low Sleep Nights: %d\n", low_sleep_count);
    printf("Irregular Nights: %d", irregular_sleep_count);
    return 0;
}

/*Function Declaration*/

/*Calculate Sleep minutes: gets sleep time and wake time array and return the minutes of sleeping*/
int calculate_sleep_minutes(const int sleep_time[], const int wake_time[]) {
    int result = 0;
    int sleep_hour = sleep_time[0], sleep_minute = sleep_time[1];
    int wake_hour = wake_time[0], wake_minute = wake_time[1];

    /*Calculating Part 1*/
    if (sleep_hour <= 24 && sleep_hour >= 8) {
        result += (24 - sleep_hour)*MINcoef - sleep_minute + SlEEPintercept*MINcoef;
    }
    else {
        result += SlEEPintercept*MINcoef - (sleep_hour*MINcoef + sleep_minute);
    }

    /*Calculating Part 2*/
    result += wake_hour*MINcoef + wake_minute - SlEEPintercept*MINcoef;

    return result;
}

/*is_irregular: sleep time and wake time and return if it is irregular or not*/
int is_irregular(int sleep_hour, int wake_hour) {
    if ((0 <sleep_hour && sleep_hour < 5) || (10 <wake_hour)) {
        return True;
    }
    return False;
}

/*is_low: gets sleep minutes and return if it is low or not*/
int is_low(int sleep_min) {
    if (sleep_min < 6*MINcoef) {
        return True;
    }
    return False;
}
