#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

void funny_function(){
  char buffer[100] = {0};

  char input1[8] = {0};

  char input2[8] = {0};

  char input3[8] = {0};

  char* secret1 = "hello\n";
  char* secret2 = "there\n";
  char* secret3 = "kenobi\n";

  printf("Hello There, how about some Puzzles?\n");
  printf("Please enter Solution No1\n")
  read(0, input1, 8);
  if(strcmp(secret1, input1)){
      puts("Oh no!\n");
      exit(0);
  }


  printf("Thank you, now the second:\n");
  read(0, input2, 8);
  if(strcmp(secret2, input2)){
      puts("Oh no!\n");
      exit(0);
  }
  printf("Thanks, now the third:\n");
  read(0, input3, 8);
  if(strcmp(secret3, input3)){
      puts("Oh no!\n");
      exit(0);
  }
  printf("Alright, and now the last one:\n");
  read(0, buffer, 300);
  printf("Wow, you got the corrrect input!\n");
  return;

}

int main() {
    funny_function();
    return 0;
}
