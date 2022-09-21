#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

int main(int argc, char **argv)
{
  printf("Welcome! Enter a string to get started.\n");
  while(1){
    char str[64];
    printf("> ");
    fgets(str, 64, stdin);
    if (str[0] == 'q')
      goto done;
    printf("The string is: %s", str);
    char *p = &str[0];
    int numWords = count_words(p);
    printf("I think there are %d words\n",numWords);
  }
  done:
    return 0;
}
