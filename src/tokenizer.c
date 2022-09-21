#include <stdio.h>
#include "tokenizer.h"

int space_char(char c){
  return ((c == ' ' || c == '\t' || c == EOF || c == '\n') ? 1:0);
}

int non_space_char(char c){
  return ((c != ' ' && c != '\t' && c!= EOF && c != '\n') ? 1:0);
}

char *word_start(char *str){
  while(space_char(*str)){
    str++;
  }
  return str;
}

char *word_terminator(char *word){
  
  while(non_space_char(*word)){
    //printf("I'm at char %c\n",*word);
    word++;
  }
  return word;
}

int count_words(char *str){
  int numWords = 0;
  while(1){
    str = word_start(str);
    //printf("current start is %c\n",*str);
    str = word_terminator(str);
    //printf("current end is %c\n",*str);
    ++numWords;
    
    if(*str == EOF || *str == '\n'){
      str++;
      //printf("next after end is %c\n",*str);
      goto done;
    }
  }
  done:
   return numWords;
}

char *copy_str(char *inStr, short len){
  //return EOF;
}

char **tokenize(char* str){
  //return EOF;
}

void print_tokens(char **tokens){
  
}

void free_tokens(char **tokens){

}
