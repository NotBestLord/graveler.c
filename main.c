#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sysinfoapi.h>
#include <stdbool.h>


// Returns time difference in miliseconds.
int getDiff(SYSTEMTIME start, SYSTEMTIME end){
    int milis = end.wMilliseconds - start.wMilliseconds;
    int secs = 1000 * (end.wSecond - start.wSecond);
    int mins = 60000 * (end.wMinute - start.wMinute);
    return milis + secs + mins;
}


int getSuccessfullRolls(){
    int rolls = 0;
    int iterations = 231;
    int base = rand();
    int baseShifts = 0;
    int r;
    while(iterations > 0){
        if(baseShifts == 7){
            baseShifts = 0;
            base = rand();
        }
        r = base & 3;
        base = (unsigned)base >> 2;
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
    const int loops = 100000;
    const int iterations = 231;
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
    printf("Time Taken %dms\n", getDiff(start, end));

    return;
}