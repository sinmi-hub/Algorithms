#include "collatz.h"

int steps(int start){
    int step = (start <= 0) ? -1 : 0;

    if (start > 0){
        if (!(start & (start - 1))) {return log2(start);}

        else{
            while(start > 1){
                start = (start % 2 == 0) ? start / 2 : ((start * 3) + 1);
                step++;
            }
        }
    }
    
    return step;
}
