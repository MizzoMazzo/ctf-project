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

//converts the binary using our script
void convert_binary(){
  char buffer[40];

  snprintf(buffer, sizeof(buffer), "python3 converter.py binary%d", getpid());
  system(buffer);
}

//print the binary, but how? ;)
void print_binary(){
  int i;
  char filename[40];
  FILE *fp;

  snprintf(filename, sizeof(filename), "binary%dencoded", getpid());

  fp = fopen(filename, "r");
  printf("\nWhat is this??\n\nThe Evil Villain Urandom tries to Randomize ALL the Programs!!!\nYou, the Knight in the shining Sweatshirt have to save us!\nHe has hidden the master-key in this messy Mystery:\n\n\n");
  sleep(7);
  if (fp) {
      while ((i = getc(fp)) != EOF)
          putchar(i);
      fclose(fp);
  }
  printf("\n==============================================================================\nHelp us save the INTERNETZZZ!!!\n==============================================================================\n\n");
  sleep(1);
  printf("Urandom entered the Room.\n");
  sleep(2);
  printf("Urandom: Hello There...\n");
  sleep(2);
  printf("Urandom: So you think you can determine my randomness?\n");
  sleep(2);
  printf("Urandom: HAH! You Fool!\n");
  sleep(2);
  printf("Urandom: You will never solve my truly RANDOM Puzzles!!!\n");
}

//execute the generated binary
void run_binary(){
  char filename[15];

  snprintf(filename, sizeof(filename), "./binary%d", getpid());
  printf("\n");
  system(filename);
}

//remove all files after connection
void cleanup(){
  char binaryfile[15];
  char encodedfile[30];

  snprintf(binaryfile, sizeof(binaryfile), "binary%d", getpid());
  snprintf(encodedfile, sizeof(encodedfile), "binary%dencoded", getpid());

  remove(binaryfile);
  remove(encodedfile);
}

//1. generate the binary
//2. convert the binary
//3. print the converted
//4. execute the binary
//5. cleanup system
//6. go away!
int main(){
  generate_binary();
  convert_binary();
  print_binary();
  run_binary();
  cleanup();

  return 0;
}
