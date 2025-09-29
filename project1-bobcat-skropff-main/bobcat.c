#include <err.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void run1(int fd1);

void run1(int fd1) {
  char char1;
  while (read(fd1, &char1, 1) == 1) {
    write(1, &char1, 1);
  }
}

int main(int argc, char *argv[]) {
  int fd;
  if (argc == 1) {
    fd = 0;
    run1(fd);
  }
  else {
    for (int i = 1; i < argc; i = i + 1) {
      if (strcmp(argv[i], "-") == 0) {
        fd = 0;
      }
      else {
        fd = open(argv[i], O_RDONLY);
      }
      if (fd != -1)  {  
        run1(fd);
      }
      else {
        fprintf(stderr, "bobcat: %s: No such file or directory\n", argv[i]);
      }
  }
}
      
