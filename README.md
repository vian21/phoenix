# Phoenix

This repository contains the level files for https://exploit.education/phoenix/

## gdb

- `break FUNCTION`: set break point at function. can be line, address or function
- `break *addr`: set break point at addres addr.

- `clear BREAKPOINT`: remove break point

- `set disassembly-flavor intel`: change `asm` flavor/syntax
- `disassemble FUNCTION` usually mean

- `shell COMMAND`: run COMMAND in shelll
- `CTRL + L` : clear screen

- `run`: execute program. can be done multiple time
- `exit/quit`
- `lay next` - see source code and assembly
- `next` - next line in c
- `nexti` - next intstruction
- `ref` - refresh gdb
- `list` - print source code if it was not stripped by compiler
- `info line @line` - get start and end address of line
- `info address @line` 
- `x @function/addr` - examine
-  `p &variable_name`
## r2

- `aa` - analyze all functions
- `afl`: list functions in program
- `pdf function_name | pdf @function_name`: show function disassembly

- `v` - visual mode
- `VV @function` - Enter Graph View at function
- `iz` - Show strings (only data section)
- `izz` - Show strings (all sections)

## Stack

<center>
<img src="https://textbook.cs161.org/assets/images/memory-safety/x86/memory-sections.png">
</center>
- sources:

- https://courses.engr.illinois.edu/cs225/fa2022/resources/stack-heap/#:~:text=Every%20time%20a%20function%20is,make%20the%20stack%20grow%20downwards.
- https://textbook.cs161.org/memory-safety/x86.html

- `esp`(extended stack pointer): points at last element in stack
- `ebp`(extended base pointer)
- `eip`(extended Instruction Pointer/program count): determines which instruction to execute next after
- `eax`: contains return value of function. Used as working register

- `stack frame`: memory between `esp` and `ebp` (included). WHen function call returns, leave is called which moves
- The stack stores local variables and other information associated with function calls. The stack starts at higher addresses and “grows down” as more functions are called.
- variable are accesed as offsets to the `ebp`

- Instruction are pushed on the stack

```sh
mov destination, source
movl source, destination

sub right, left
sub $0x10,%rsp #$0x10 is 10.
```

| `main()  ` |
| ---------- | ---------------------------- |
| local_a    |
| ---------  |
| local_b    |
| ---------  |
| `eip `     | where to resume execution to |
| ---------  |
| `ebp `     | start of stack frame         |
| ---------  |
| local_c    |
| ---------  |
| local_d    |
| ---------  |
| `esp `     | end of stack frame           |
| ---------  |

- data is written using little endian system. LSB is written first meaning that data will be written in the reverse order with the danger of overwriting values higher on the stack
- `buffer overflow`: writing past a buffer's capacity to its surrounding neighbours/memory chunck
- `stack smashing`: overwriting ebp and eip pointer to point to where we want them to point to.


- you want to overwrite the saved rip

- `checksec file`
- `NX` - determines whether you can execute code on the stac
- PIE stands for Position Independent Executable, which means that every time you run the file it gets loaded into a different memory address. This means you cannot hardcode values such as function addresses and gadget locations without finding out where they are.