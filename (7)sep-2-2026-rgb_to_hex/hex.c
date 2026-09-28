#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert_to_hex(char *rgb_string, char *result){

    char copy[50];
    
    strcpy(copy,rgb_string);

    // use memmove to remove rgb( from the beginning of the string
    memmove(copy, copy + 4, strlen(copy) - 3);

    // remove ) from the end of the string
    copy[strlen(copy) - 1] = '\0';

    // printf("%s", copy);
    // ==> 243, 177, 24

    // split the remaining string using , separators

    char *r_string = strtok(copy, ",");
    char *g_string = strtok(NULL, ",");
    char *b_string = strtok(NULL, ",");


    // convert splitted string values into integer values

    int r = atoi(r_string);
    int g = atoi(g_string);
    int b = atoi(b_string);

    //Insert hex values of this integer numbers in result array
    sprintf(result, "%02x%02x%02x", r,g,b);

}


int main(void){

    char rgb_string[] = "rgb(243, 177, 24)";
    
    // # + 6 hex characters and '\0'
    char result[8];

    convert_to_hex(rgb_string, result);

    printf("%s", result);

    return 0;
}