#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isValidIPv4(char *ipv4_address){

    char copy[200];
    strcpy(copy, ipv4_address);

    int element_index = 0;

    char *element = strtok(copy, ".");

    while(element != NULL){

        if(strcmp(element, "") == 0){
            return false;
        }
        else if(strlen(element) > 1 && element[0] == '0'){
            return false;
        }

        for(int i = 0; i < strlen(element); i++){
            if(element[i] < '0' || element[i] > '9'){
                return false;
            }
        }

        int element_int = atoi(element);

        if(element_int < 0 || element_int > 255){
            return false;
        }

        element = strtok(NULL, ".");
        element_index++;

    }

    if(element_index != 4){
        return false;
    }


    return true;
}


int main(void){

    // char ipv4_address[] = "255.01.50.111";
    char ipv4_address[] = "192.168.1.1";
    
    bool result = isValidIPv4(ipv4_address);

    printf("%s\n",result ? "true" : "false");

    return 0;
}