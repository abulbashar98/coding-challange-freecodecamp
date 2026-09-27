#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10


double *caught_speeding(int *speeds, int limit){

    int overspeeding_count = 0;
    int total_speed_over_speedLimit = 0;

    for(int i = 0; i < MAX_SIZE; i++){
        if(speeds[i] > limit){
            overspeeding_count++;
            total_speed_over_speedLimit += (speeds[i] - limit);
        }
    }

    // allocate dynamic memory for result
    double *result = malloc(2 * sizeof(double));

    if(result == NULL){
        return NULL;
    }

    else if(overspeeding_count == 0){
        result[0] = 0;
        result[1] = 0;

        return result;
    }

    else{
        result[0] = overspeeding_count;
        result[1] = (double)total_speed_over_speedLimit / overspeeding_count;

        return result;
    }
}


int main(void){

    int speeds[10] = {55, 75, 82, 68, 57, 95, 115, 118, 60};    
    int limit = 80;

    double *result = caught_speeding(speeds, limit);

    if(result != NULL){

        printf("[%.f,%.1f]", result[0], result[1]);

        free(result);
    }

    return 0;
}