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
    word++;
  }
  return word;
}

int count_words(char *str){
  int numWords = 0;
  while(1){
    str = word_start(str);
    //printf("Current char is %c\n",*str);
    if(space_char(*str))
      goto done;
    str = word_terminator(str);
    ++numWords;
    if(*str == EOF || *str == '\n')
      goto done;
  }
  done:
   return numWords;
}

char *copy_str(char *inStr, short len){
  printf("There should be %d words\n", len);
  char *start = inStr;
  char *end = 0;
  for(int i = 0; i < len; i++){
    start = word_start(start);
    end = word_terminator(start);
    *end = '0';
  }
  //for(int i = 0; i < 64; i++){
  //  printf("Char at %d = %c\n",i,inStr[i]);
  //}
  return inStr;
}

char **tokenize(char* str){
  //return EOF;
}

void print_tokens(char **tokens){
  
}

void free_tokens(char **tokens){

}
