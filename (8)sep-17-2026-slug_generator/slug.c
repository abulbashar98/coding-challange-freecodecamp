#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char *slug_generator(char *arbitrary_str,char *slug){

    int slug_index = 0;
    bool previous_was_space = false;

    for(int i = 0; arbitrary_str[i] != '\0'; i++){

        char ch = arbitrary_str[i];

        ch = tolower(ch);

        if(isalnum(ch)){
            slug[slug_index] = ch;
            slug_index++;
            previous_was_space = false;
        }

        else if(ch == ' '){
            if(strlen(slug) > 0 && !previous_was_space){
                slug[slug_index] = '%';
                slug_index++;

                slug[slug_index] = '2';
                slug_index++;

                slug[slug_index] = '0';
                slug_index++;

                previous_was_space = true;
            }
        }

        // ignore all other characters

    }

    if(strlen(slug) > 0 && slug[strlen(slug) - 3] == '%'){
        slug[strlen(slug) - 3] = '\0';
    }


}


int main(void){

    char arbitrary_str[] = "  ?H^3-1*1]0! W[0%R#1]D  ";    

    char slug[50];

    slug_generator(arbitrary_str, slug);

    printf("%s", slug);

    return 0;
}