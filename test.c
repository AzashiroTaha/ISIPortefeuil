#include <stdio.h>
#include <time.h>
#include<string.h>

int main() {
    time_t current_time;
    time(&current_time);
    char time[20];
    strcpy(time, ctime(&current_time));
    
    printf("Current date and time: %s", time);
    return 0;
}