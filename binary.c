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
  char first[8] = {0};
  char second[8] = {0};
  char third[8] = {0};
  char* secret1 = "hello\n";
  char* secret2 = "there\n";
  char* secret3 = "kenobi\n";

  printf("Hello There, please provide your first input:\n");
  read(0, first, 8);
  printf("Thank you, now the second:\n");
  read(0, second, 8);
  printf("Thanks, now the third:\n");
  read(0, third, 8);
  printf("Alright, and now the last one:\n");
  read(0, buffer, 300);

  if (!strcmp(secret1, first) && !strcmp(secret2, second) && !strcmp(secret3, third)){
    printf("Wow, you got the corrrect input!\n");
    return;
  } else {
    printf("Oh no!\n");
    exit(1);
  }
}

int main() {
    funny_function();
    return 0;
}
