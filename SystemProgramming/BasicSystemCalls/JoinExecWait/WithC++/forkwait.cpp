#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int agc, char *argv[]) {
  printf("Hello world (pid:%d)\n", (int)getpid());
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "failed fork\n");
    exit(1);
  }
  else if (rc == 0) {
     printf("Im the child my return should be 0: %d and I should have my own (pid:%d)\n", rc, (int) getpid());

  }
  else {
    int rc_wait = wait(NULL);
    printf("Im the parent of %d and im waiting for it to finish %d (pid:%d)\n", rc, rc_wait, (int) getpid());
  }
  return 0;
}
