FlAGS:=-O0 -fno-stack-protector  -z execstack -g
compile: 
	@echo "Disabling ASLR"
	@sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'

	gcc ${FlAGS}  ${file}.c -o ${file}

clean:
	@echo "Re-enabling ASLR"
	@sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'

	@echo "Deleting executables"
	find . -maxdepth 1 -type f -executable -delete
