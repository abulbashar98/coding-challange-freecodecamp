#include <stdio.h>

#define SIZE_OF_ARRAY 9  


int distinct_second_largest(int *arr){
        int largest = arr[SIZE_OF_ARRAY - 1];
        
        for(int i = SIZE_OF_ARRAY - 2; i >= 0; i--){
            if(arr[i] != largest){
                return arr[i];
            }
        }

        return -1;
    }

int main(void){

    int arr[SIZE_OF_ARRAY] = {1, 0, -1, 0, 1, 0, -1, 1, 0};

    int sorted_arr[SIZE_OF_ARRAY];

    int i = 0;
    
    // Copy array
    while(i < SIZE_OF_ARRAY){
        sorted_arr[i] = arr[i];
        i++;
    }

    // Sort array using inner and outer loop in ascending order

    int j = 0;

    while(j < SIZE_OF_ARRAY - 1){

        int k = 0;

        while(k < SIZE_OF_ARRAY - 1 - j){
            int temp = 0;
            if(sorted_arr[k+1] < sorted_arr[k]){
                temp = sorted_arr[k+1];
                sorted_arr[k+1] = sorted_arr[k];
                sorted_arr[k] = temp;
            }
            k++;
        }

        j++;
    
    }


    

    

    int result = distinct_second_largest(sorted_arr);

    printf("%d", result);

    return 0;
}