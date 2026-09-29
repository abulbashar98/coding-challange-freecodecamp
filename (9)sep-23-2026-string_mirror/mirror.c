#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isMirror(char *str1, char *str2){

    char final_str1[50] = "";
    char final_str2[50] = "";

    int index1 = 0;
    int index2 = 0;

    // check and remove all the characters from str1 except alphabets
    for(int i = 0; str1[i] != '\0';i++){

        char ch = str1[i];

        if(isalpha(ch)){
            final_str1[index1] = ch;
            index1++;
        }

    }
    final_str1[index1] = '\0';

    // check and remove all the characters from str2 except alphabets
    for(int i = 0; str2[i] != '\0'; i++){

        char ch = str2[i];

        if(isalpha(ch)){
            final_str2[index2] = ch;
            index2++;
        }

    }
    final_str2[index2] = '\0';


    // reverse final_str1 to compare with final str2
    int length_of_final_str1 = strlen(final_str1);

    for(int i = 0; i < length_of_final_str1 / 2; i++){
        char temp = final_str1[i];

        final_str1[i] = final_str1[length_of_final_str1 - 1 - i];

        final_str1[length_of_final_str1 - 1 - i] = temp;
    }

    // finally return the boolean value of reversed final_str1 and final_str2

    return strcmp(final_str1, final_str2) == 0;

}


int main(void){

    char str1[] = "!dlroW !olleH";
    char str2[] = "Hello World";

    bool result = isMirror(str1, str2);

    printf("%s", result ? "true" : "false");

    return 0;
}