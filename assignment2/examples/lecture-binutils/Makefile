
.PHONY: all clean hello-c empty empty-disasm hello hello-exec main1 main2 

all:
	@echo "Checkout the Makefile for different commands."

hello-c:
	gcc hello-c.c -o hello-c 		# Compile, generate a.out
	@echo --------------------------------------
	size hello-c
	@echo --------------------------------------
	objdump -d hello-c | grep "<main>:" -A10   # "-A10"means to show 10 more lines after the line where "<main>:" shows up

empty:
	gcc empty.c -o empty           
	@echo --------------------------------------
	size empty
	@echo --------------------------------------
	objdump -d empty | grep "<main>:" -A10

# Show direct disasm of a C file
empty-disasm:
	gcc empty.c -S
	cat empty.S   # typo? should be small s
	@echo --------------------------------------
	cat empty.S | grep -v ".cfi_"   # typo? should be small s

# Show how do object dump an assemble file. Difference between gcc asm.
hello:         
	nasm -felf64 hello.asm
	@echo --------------------------------------
	cat hello.asm
	@echo --------------------------------------
	objdump -D hello.o    #dump all sections
	@echo --------------------------------------
	hexdump hello.o -C
	@echo --------------------------------------
	size hello.o
	@echo --------------------------------------
	nm hello.o         # list symbols

# Same as hello, but perform it on the executable instead
hello-exec:         
	nasm -felf64 hello.asm
	ld hello.o -o hello
	@echo --------------------------------------
	cat hello.asm
	@echo --------------------------------------
	objdump -D hello    
	@echo --------------------------------------
	hexdump hello -C
	@echo --------------------------------------
	size hello
	@echo --------------------------------------
	nm hello         
	@echo --------------------------------------
	readelf hello -a


# Simple main, compiled with different flags
main1:
	gcc main1.c -O3 -c -o main1.o                  # Compile but do not link
	gcc main1.c -O3 -S
	@echo --------------------------------------
	cat main1.S | grep -v ".cfi_" | grep -v ".LF"
	@echo -------------------------------------- # Show difference betwen opt level
	gcc main1.c -O0 -S
	cat main1.S | grep -v ".cfi_" | grep -v ".LF"
	@echo --------------------------------------
	objdump -d main1.o

# Separate compilation units
main2:
	@echo --------------------------------------
	gcc main2.c -O3 -c -o main2.o               
	gcc other.c -O3 -c -o other.o
	@echo --------------------------------------
	objdump -d other.o
	@echo --------------------------------------
	ld main2.o other.o -o main2
	objdump -d main2.o
	@echo --------------------------------------
	gcc -O3 main2.c other.c -o main2
	objdump -d main2.o

# Show disasm of a file with misc operations
misc-disasm:
	gcc -O3 misc.c -S
	cat misc.S
	@echo --------------------------------------
	cat misc.S | grep -v ".cfi_"
	gcc -O3 misc.c
	./a.out
	echo $? 


clean:
	rm -f *~ a.out hello-c *.S *.o *.s hello main1 main2 empty 



