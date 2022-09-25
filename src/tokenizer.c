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
  
  while(non_space_char(*word) && *word != 0){
    word++;
  }
  return word;
}

int count_words(char *str){
  int numWords = 0;
  while(*str != 0){
    str = word_start(str);
    if(*str == 0)
      goto done;
    str = word_terminator(str);
    ++numWords;
    if(*str == 0)
      goto done;
  }
  done:
   return numWords;
}

char *copy_str(char *inStr, short len){
  int numWords = count_words(inStr);
  char newStr[len+numWords];
  int newStrCounter = 0;
  char *endWord = word_terminator(word_start(inStr));
  for (int i = 0; i < buff_size && inStr[i] != 0; i++){
    if (!space_char(inStr[i])){
      newStr[newStrCounter] = inStr[i];
      newStrCounter++;
    }
    else if(&inStr[i] == endWord){
      newStr[newStrCounter] = 0;
      newStrCounter++;
      endWord = word_terminator(word_start(endWord));
    }
    else if(inStr[i] == 0){
      break;
    }
  }
  //done:
  //printf("Setting %d to 0\n",newStrCounter);
  //newStr[newStrCounter] = 0;
  // for(int i = 0; i < len+numWords; i++){
  //  printf("Char at %d = %c\n",i,newStr[i]);
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
