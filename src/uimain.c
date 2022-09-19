#include <stdio.h>

int main(int argc, char **argv)
{
  printf("Welcome!\n");
  while(1){
    char str[32];
    printf("> ");
    scanf("%[^\n]%*c", str);
    
    //while((str = getchar()) == '\n');
    //if (str == EOF)
    //  goto done;
    
    if(str[0] == 'q')
      goto done;
    printf("You put: %s\n",str);
    
  }
  done:
    return 0;
}
