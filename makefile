FlAGS:=-O0 -fno-stack-protector -z execstack -g -no-pie

compile: 
	gcc ${FlAGS}  ${file}.c -o ${file}

init:
	@echo "Disabling ASLR"
	@sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'

clean:
	@echo "Re-enabling ASLR"
	@sudo bash -c 'echo 1 > /proc/sys/kernel/randomize_va_space'

	@echo "Disabling core dumps"
	@ulimit -c 0

	@echo "Deleting executables"
	find . -maxdepth 1 -type f -executable -delete
