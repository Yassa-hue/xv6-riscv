// user/touch.c
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(2, "Usage: touch filename\n");
    exit(1);
  }

  int fd = open(argv[1], O_CREATE | O_WRONLY);
  if (fd < 0) {
    fprintf(2, "touch: cannot create %s\n", argv[1]);
    exit(1);
  }

  close(fd);
  exit(0);
}
