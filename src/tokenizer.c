#include <stdio.h>
#include <stdlib.h>
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
    numWords++;
    if(*str == 0)
      goto done;
  }
  done:
   return numWords;
}

char *copy_str(char *inStr, short len){
  int numWords = count_words(inStr);
  //char newStr[len+numWords];
  char *newStr = (char*)malloc((len+numWords)*sizeof(char));
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
  return newStr;
}

char **tokenize(char* str){
  int numChars = 0;
  for(int i = 0; str[i] != 0; i++){
    if(non_space_char(str[i]))
      numChars++;
  }
  char *term_str = copy_str(str, numChars);
  int numWords = count_words(str);
  char **tokens = (char**)malloc((numWords+1)*sizeof(char*));
  for(int i = 0; i < numWords; i++){
    tokens[i] = term_str;
    term_str = word_terminator(term_str)+1;
  }
  tokens[numWords] = 0;
  return tokens;
}

void print_tokens(char **tokens){
  int i;
  for(i = 0; tokens[i] != 0; i++){
    printf("Tokens[%d] = %s\n", i, tokens[i]);
  }
  printf("Tokens[%d] = 0\n", i);
}

void free_tokens(char **tokens){
  free(tokens);
  //printf("Memory has been successfully freed\n");
}
