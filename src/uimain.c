#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
int buff_size = 32;
int main(int argc, char **argv)
{
  printf("Welcome! Enter a string to get started.\n");
  while(1){
    char str[buff_size];
    printf("> ");
    fgets(str, buff_size, stdin);
    if (str[0] == 'q')
      goto done;
    printf("The string is: %s", str);
    char *p = &str[0];
    char **tokens = tokenize(p);
    print_tokens(tokens);
    free_tokens(tokens);
    
  }
  done:
    return 0;
}
