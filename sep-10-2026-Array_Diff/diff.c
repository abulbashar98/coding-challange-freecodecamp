#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define MAX_LENGTH 25

int contains(char arr[][MAX_LENGTH], size_t size, char value[]){
    for(int i = 0; i < size; i++){
        if(strcmp(arr[i], value) == 0){
            return 1; //found
        }
    }
    return 0; // not found
}

int compare_strings(const void *a, const void *b){

    const char *str1 = (const char *)a;
    const char *str2 = (const char *)b;

    return strcmp(str1, str2);

}


void array_diff_in_sorted_order(char arr1[][MAX_LENGTH], size_t size1, char arr2[][MAX_LENGTH], size_t size2){

    char array_with_semantic_diff[MAX_SIZE][MAX_LENGTH];
    int diff_size = 0;

    // equivalent of [...new Set(arr1), ...new Set[arr2]] from JavaScript


    // all the unique elements of arr1 
    for(int i = 0; i < size1; i++){

        if(contains(arr1, size1, arr1[i]) != contains(arr2, size2, arr1[i])){
                
            strcpy(array_with_semantic_diff[diff_size], arr1[i]);

            diff_size++;

           }

    }


    // all the unique values from array 2
    for(int i = 0; i < size2; i++){
        if(contains(arr1, size1, arr2[i]) != contains(arr2, size2, arr2[i])){

            strcpy(array_with_semantic_diff[diff_size], arr2[i]);

            diff_size++;

        }
    }


    // equivalent of .sort((a,b)=>a-b) in js or sorted() in python

    qsort(array_with_semantic_diff, diff_size, sizeof(array_with_semantic_diff[0]), compare_strings);



    // equivalent of console.log() in js and print in python

    printf("\nSemantic diff of two arrays: ");
    printf("[");

    for(int i = 0; i < diff_size; i++){
        if(i == diff_size - 1){
            printf("%s", array_with_semantic_diff[i]);
        }
        else{
            printf("%s,", array_with_semantic_diff[i]);
        }
    }

    printf("]");

}


int main(void){

    char arr1[][MAX_LENGTH] = {"I", "like", "freeCodeCamp"};
    char arr2[][MAX_LENGTH] = {"I", "like", "rocks"};


    size_t size1 = sizeof(arr1)/sizeof(arr1[0]);
    size_t size2 = sizeof(arr2)/sizeof(arr2[0]);

    printf("Size1: %d, Size2: %d", size1, size2);


    array_diff_in_sorted_order(arr1, size1, arr2, size2);


    return 0;
}