import random
import string
import os
import sys

header = '''
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
    printf("Oh you found my Flag!!!\\n");
    if (fp) {
        while ((i = getc(fp)) != EOF)
            putchar(i);
        fclose(fp);
    }
}

int funny_function(){
'''
end='''
int main() {
    init();
    alarm(20);
    funny_function();
    return 0;
}
'''
mem='''
  char input1[9] = {0};

  char input2[9] = {0};

  char input3[9] = {0};
'''

lastone1 = '''  printf("Alright, and now the last one:\\n");
  read(0, buffer, '''
lastone2 = ''');
  printf("Wow, you got the correct input!\\n");
  return 0;

}
'''


def randomString(stringLength=7):
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(stringLength))
def genChecks(amount):
    checks=""
    for x in range(1,amount+1):
        checks += '  printf("Please enter secret '+str(x)+'''\\n");\n'''
        checks += "  read(0, input"+str(x)+", 8);\n"
        checks +='''  if(strcmp(secret'''+str(x)+''', input'''+str(x)+''')){
      puts("Oh no!\\n");
      return 1;
  }
'''
    return checks


def gensecret(amount):
    secrets=''
    for x in range(1,amount+1):
        secrets += "  char* secret"+str(x)+" = "+'"'+ randomString() +'''\\n";'''+"\n"
    return secrets
def genRanFiles(name,amount,remove=False):
    for x in range(1,amount+1):
        bufsize = 100 + random.randint(10,200)
        readsize = bufsize + random.randint(30,100)
        if not name:
            fname="binary"+str(x)+".c"
        else:
            fname="binary"+str(name)+".c"

        code = header +"  char buffer["+str(bufsize)+"] = {0};" + mem + gensecret(3)  + genChecks(3) + lastone1+str(readsize)+lastone2+end
        fil = open(fname,"w")
        fil.write(code)
        fil.close()
        cmd = "gcc "+ fname+" -O0 -no-pie -fno-stack-protector -masm=intel -o "+fname.split(".")[0]
        os.system(cmd)
        if remove:
            os.system("rm "+fname)



def main():
    if len(sys.argv)>1:
        name=sys.argv[1]
        genRanFiles(name, 1, True)
    else:
        name=None
        genRanFiles(name, 2, True)





if __name__ == '__main__':
    main()
