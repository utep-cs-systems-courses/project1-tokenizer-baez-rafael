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
    /*
    int numChars = 0;
    for(int i = 0; str[i] != 0; i++){
      if(non_space_char(str[i])){
	numChars++;
      }
    }
    //printf("I think there are %d nonspace chars\n", numChars);
    char *term_str = copy_str(p, numChars);
    */
  }
  done:
    return 0;
}
