




header = '''
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
'''
end='''
int main() {
    funny_function();
    return 0;
}
'''





def main():
    print(header)



if __name__ == '__main__':
    main()
