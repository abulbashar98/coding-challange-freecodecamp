#include <stdio.h>
#include <string.h>
#include <ctype.h>


int is_ignore_word(char *word){

    char ignore_word_list[][15] = {"a", "for", "an", "and", "by", "of"};
    int ignore_word_count = 6;

    for(int i = 0; i < ignore_word_count; i++){
        if(strcmp(ignore_word_list[i], word) == 0){
            return 1; // match found
        }
    }

    return 0; // no match found
}


void build_acronym(char *original_string, char *acronym){

    // copy original string
    char copy[100];
    strcpy(copy, original_string);

    char *word = strtok(copy, " ");

    int word_index = 0;
    int acronym_index = 0;

    while(word != NULL){

        if(word_index == 0 || !is_ignore_word(word)){
            acronym[acronym_index] = toupper(word[0]);
            acronym_index++; 
        }
    
    word = strtok(NULL, " ");
    word_index++;
    
    }

    acronym[acronym_index] = '\0';

}


int main(void){

    char original_string[] = "National Aeronautics and Space Administration";
    char acronym[15];

    build_acronym(original_string, acronym);

    printf("%s", acronym);

    return 0;
}