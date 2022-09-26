#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <stdlib.h>

int buff_size = 32;
int main()
{
  printf("Welcome! Enter a string to get started.\n");
  List *userHist = init_history();
  while(1){
    char str[buff_size];
    printf("> ");
    fgets(str, buff_size, stdin);
    if (str[0] == '!'){
      if (str[1] == 'q'){
	free_history(userHist);
	goto done;
      }
      else if(str[1] == 'h'){
	print_history(userHist);
      }
      else{
	char *cutoff = &str[1];
	int idx = atoi(cutoff);
	char *specHist = get_history(userHist, idx);
	if(specHist[0]!= '\n'){
	  printf("User requested history at [%d]: %s",idx,specHist);
	  char **tokens = tokenize(specHist);
	  print_tokens(tokens);
	  free_tokens(tokens);
	}
      }
    }
    else{
      char *p = &str[0];
      add_history(userHist, p);
    }
  }
  done:
  printf("Bye-Bye!\n");
  return 0;
}
