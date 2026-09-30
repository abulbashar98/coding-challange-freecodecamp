#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool isSpam(char *number){

    char countryCode[10];
    char areaCode[15];
    char localNumber[20];
    char digits[20];

    // -------------------------
    // 1. Extract Country Code
    // -------------------------

    int index = 0;

    for(int i = 1; number[i] != ' '; i++){
        countryCode[index] = number[i];
        index++;
    }
    countryCode[index] = '\0';


    // -----------------------
    // 2. Extract area code
    // -----------------------

    char *open = strchr(number, '(');
    char *close = strchr(number, ')');

    index = 0;

    for(char *p = open + 1; p < close; p++){
        areaCode[index] = *p;
        index++;
    }

    areaCode[index] = '\0';


    // -------------------------------------------
    // 3. Extract local number excluding the '-'
    // --------------------------------------------
    char *local_start = close + 2;

    index = 0;

    for(int i = 0; local_start[i] != '\0'; i++){
        if(isdigit(local_start[i])){
            localNumber[index] = local_start[i];
            index++;
        }
    }
    localNumber[index] = '\0';


    // --------------------------------
    // 4. Remove formatting characters
    // --------------------------------

    index = 0;

    for(int i = 0; number[i] != '\0'; i++){
        if(isdigit(number[i])){
            digits[index] = number[i];
            index++;
        }
    }
    digits[index] = '\0';


    // --------------------------------
    // check 1st condition
    // --------------------------------

    if(strlen(countryCode) > 2 || countryCode[0] != '0'){
        return true;
    }


    // --------------------------------
    // check 2nd condition
    // --------------------------------

    int area = atoi(areaCode);

    if(area < 200 || area > 900){
        return true;
    }

    // --------------------------------
    // check 3rd condition
    // --------------------------------
  
    int sum_of_first_three_digits_in_local = (
        localNumber[0] - '0' +
        localNumber[1] - '0' +
        localNumber[2] - '0'
    );

    char sumString[5];

    // convert sum into a string to find it or compare it to another str

    sprintf(sumString, "%d", sum_of_first_three_digits_in_local);

    if(strstr(localNumber + 3, sumString) != NULL){
        return true;
    }


    // --------------------------------
    // check 4th condition
    // --------------------------------

    int count = 1;
    index = 0;

    for(int i = 1; digits[i] != '\0'; i++){

        if(digits[i] == digits[i-1]){
            count++;

            if(count >= 4){
                return true;
            }

        }
        else{
            count = 1;
        }

    }    

    return false;
}


int main(void){

    char number[] = "+00 (200) 234-0182";

    if(isSpam(number)){
        printf("The given number is a spam.\n");
    }

    else{
        printf("The number is valid.\n");
    }


    return 0;
}