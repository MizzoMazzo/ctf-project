#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//generate binary with process_id of current process
void generate_binary(){
  char buffer[40];

  snprintf(buffer, sizeof(buffer), "python3 generator.py %d", getpid());
  system(buffer);
}

void convert_binary(){
  char buffer[40];

  snprintf(buffer, sizeof(buffer), "python3 converter.py binary%d", getpid());
  system(buffer);
}

void print_binary(){
  int i;
  char filename[40];
  FILE *fp;

  snprintf(filename, sizeof(filename), "binary%dencoded", getpid());

  fp = fopen(filename, "r");
  printf("What is this??\n");
  if (fp) {
      while ((i = getc(fp)) != EOF)
          putchar(i);
      fclose(fp);
  }
}

int main(){
  generate_binary();
  convert_binary();
  print_binary();
  return 0;
}
