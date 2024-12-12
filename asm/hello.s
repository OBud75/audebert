.global _start
.intel_syntax noprefix

_start:
 
  mov rax, 1
  mov rdi, 1
  lea rsi, [hello_ptr] 
  mov rdx, [hello_size]
  syscall


  mov rax, 0
  syscall


  mov rax, 60
  mov rdi, 0
  syscall

hello_ptr:
  .asciz "Hello world\n"

hello_size:
  .int 13 
