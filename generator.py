import random
import string
import os

header = '''
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

void funny_function(){
'''
end='''
int main() {
    funny_function();
    return 0;
}
'''
mem='''
  char input1[8] = {0};

  char input2[8] = {0};

  char input3[8] = {0};
'''
initmsg='''  printf("Hello There, how about some Puzzles?\\n");\n'''

lastone1 = '''  printf("Alright, and now the last one:\\n");
  read(0, buffer, '''
lastone2 = ''');
  printf("Wow, you got the corrrect input!\\n");
  return;

}
'''


def randomString(stringLength=7):#TODO 7 or 8??? cause of \n
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(stringLength))
def genChecks(amount):
    checks=""
    for x in range(1,amount+1):
        checks += '  printf("Please enter Solution No'+str(x)+'''\\n");\n'''
        checks += "  read(0, input"+str(x)+", 8);\n"
        checks +='''  if(strcmp(secret'''+str(x)+''', input'''+str(x)+''')){
      puts("Oh no!\\n");
      exit(0);
  }
'''
    return checks


def gensecret(amount):
    secrets=''
    for x in range(1,amount+1):
        secrets += "  char* secret"+str(x)+" = "+'"'+ randomString() +'''\\n";'''+"\n"
    return secrets
def genRanFiles(amount):
    for x in range(1,amount+1):
        bufsize = 100 + random.randint(10,200)
        readsize = bufsize + random.randint(30,100)

        fname="binary"+str(x)+".c"
        code = header +"  char buffer["+str(bufsize)+"] = {0};" + mem + gensecret(3) + initmsg + genChecks(3) + lastone1+str(readsize)+lastone2+end
        fil = open(fname,"w")
        fil.write(code)
        fil.close()
        cmd = "gcc "+ fname+" -O0 -no-pie -fno-stack-protector -masm=intel -o "+fname.split(".")[0]
        os.system(cmd)



def main():
    genRanFiles(2)




if __name__ == '__main__':
    main()
