#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
  printf("hello world pid(%d)\n", (int)getpid());
  int rc = fork();
  char * memory = malloc(sizeof(char ) * 80);
  free(memory);
  if (rc < 0) {
    fprintf(stderr, "fork failed \n");
    exit(1);
  } else if (rc == 0) {
    printf("Hello i am a child with pid:%d \n", (int)getpid());
    char *myargs[3];
    myargs[0] = strdup("./basicWait");
    myargs[1] = NULL;
    execvp(myargs[0],myargs);
    printf("Me deberia imprimir?\n");
  } else {
    int rc_wait = wait(NULL);
    printf("Holi soy el papa\n");
  }
  return 0;
}
