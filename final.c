#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sysinfoapi.h>
#include <stdbool.h>


// Returns time difference in miliseconds.
unsigned long getDiff(SYSTEMTIME start, SYSTEMTIME end){
    unsigned long milis = end.wMilliseconds - start.wMilliseconds;
    unsigned long secs = 1000 * (end.wSecond - start.wSecond);
    unsigned long mins = 60000 * (end.wMinute - start.wMinute);
    unsigned long hours = 60000 * 60 * (end.wHour - start.wHour);
    unsigned long days = 60000 * 60 * 24 * (end.wDay - start.wDay);
    return milis + secs + mins + hours + days;
}


int getSuccessfullRolls(){
    int rolls = 0;
    int iterations = 231;
    int base = rand();
    int baseShifts = 0;
    int r;
    while(iterations > 0){ //This Could be replaced with a for loop of 33 iterations (231 = 33 * 7)
        if(baseShifts == 7){
            baseShifts = 0;
            base = rand();
        }
        r = base & 3;
        base = (unsigned int)base >> 2;
        baseShifts++;
        if(r == 0){
            rolls++;
        }
        iterations--;
    }
    return rolls;
}


void main(){
    // Setup Time
    SYSTEMTIME start, end;
    srand(time(NULL));

    // Variables
    const int loops = 1000000000;
    int max = 0;
    int current;

    // Time Before
    GetSystemTime(&start);
    for(int i=0;i<loops;i++){
        current = getSuccessfullRolls();
        if(current > max){
            max = current;
            if(max >= 177){
                break;
            }
        }
    }

    // Time After
    GetSystemTime(&end);
    // Outputs
    printf("Highest Number of Ones: %d\n", max);
    printf("Time Taken %lums\n", getDiff(start, end));

    return;
}
