#include <stdio.h>
#define BUFSIZE 4
void win()
{
    puts("If I am printed, I was hacked! because the program never called me!");
}
void vuln()
{
    puts("Input a string and it will be printed back!");
    char buf[BUFSIZE];
    gets(buf);
    puts(buf);
    fflush(stdout);
}
int main(int argc, char **argv)
{
    vuln();
    return 0;
}