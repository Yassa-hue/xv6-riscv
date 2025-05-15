// user/memtest.c
#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  printf("Initial free memory: %d bytes\n", freemem());

  void *a = malloc(4096 * 10); // allocate 10 pages (10 * 4096 bytes)

  if (a == 0)
    printf("Allocation failed!\n");
  else
    printf("Allocated 10 pages.\n");

  printf("Free memory after malloc: %d bytes\n", freemem());

  free(a);

  printf("Free memory after free: %d bytes\n", freemem());

  exit(0);
}
