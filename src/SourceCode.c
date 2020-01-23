
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
void init() {
  /* this disabled stream buffering.
   * You can safely ignore this function as there is no vuln in here */
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
}

void print_secret(){
    int i;
    FILE *fp;
    fp = fopen("flag.txt", "r");
    printf("Oh you found my Flag!!!\n");
    if (fp) {
        while ((i = getc(fp)) != EOF)
            putchar(i);
        fclose(fp);
    }
}

int funny_function(){
  char buffer[???] = {0};
  char input1[9] = {0};

  char input2[9] = {0};

  char input3[9] = {0};
  char* secret1 = "???????\n";
  char* secret2 = "???????\n";
  char* secret3 = "???????\n";
  printf("Please enter Solution No1\n");
  read(0, input1, 8);
  if(strcmp(secret1, input1)){
      puts("Oh no!\n");
      return 1;
  }
  printf("Please enter Solution No2\n");
  read(0, input2, 8);
  if(strcmp(secret2, input2)){
      puts("Oh no!\n");
      return 1;
  }
  printf("Please enter Solution No3\n");
  read(0, input3, 8);
  if(strcmp(secret3, input3)){
      puts("Oh no!\n");
      return 1;
  }
  printf("Alright, and now the last one:\n");
  read(0, buffer, ???);
  printf("Wow, you got the correct input!\n");
  return 0;

}

int main() {
    init();
    alarm(20);
    funny_function();
    return 0;
}
