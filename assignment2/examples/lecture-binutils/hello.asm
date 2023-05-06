        global  _start          ; make the start symbol external

        section .data
msg:    db      "Hello!",10     ; Declares a string, including hello world
                                ; Ends with new line (code 10, line feed)
        
        section .text           ; section .text states that
                                ; the following is code
_start:                         ; label indicating the start of
                                ; the program
        mov     rax, 1          ; system call number for writing
        mov     rdi, 1          ; value 1 is file handle for standard output
        mov     rsi, msg        ; writes the address to the text 
        mov     rdx, 7          ; number of bytes that we want output
        syscall                 ; system call to OS (prints the string)
        
        mov     rax, 60         ; code for exit using system call
        mov     rdi, 3          ; program exit code
        syscall                 ; system call to the OS (exits program)

