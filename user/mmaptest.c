#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
  int fd;
  uint64 addr;

  fd = open("README", O_RDONLY);  // Pick any existing file
  if (fd < 0) {
    printf("open failed\n");
    exit(1);
  }

  // Request a 1-page mapping
  addr = mmap(fd, 4096);
  printf("mmap returned address: %p\n", (void *)addr);
  if (addr == (uint64)-1) {
    printf("mmap failed\n");
    close(fd);
    exit(1);
  }

  printf("mmap succeeded. First byte: %c\n", ((char*)addr)[0]);

  // Optional: print more bytes
  for (int i = 0; i < 32; i++) {
    write(1, (char*)(addr + i), 1);
  }
  printf("\n");

  close(fd);
  exit(0);
}
