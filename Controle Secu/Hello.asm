section .data
    prompt db "entre ton nom: ", 0      
    prompt_len equ $ - prompt          
    greeting db "bonjour, ", 0         
    buffer db 50                       

section .bss
    input resb 50                      

section .text
    global _start                      

_start:
    ; Afficher le message
    mov eax, 4                         
    mov ebx, 1                         
    mov ecx, prompt                    
    mov edx, prompt_len                
    int 0x80                           

    ; Lire l'entrée utilisateur
    mov eax, 3                         
    mov ebx, 0                         
    mov ecx, input                     
    mov edx, 50                        
    int 0x80                           

    ; Afficher "bonjour, "
    mov eax, 4                         
    mov ebx, 1                         
    mov ecx, greeting                  
    mov edx, 9                         
    int 0x80                           

    ; Afficher le nom saisi
    mov eax, 4                         
    mov ebx, 1                         
    mov ecx, input                     
    mov edx, 50                        
    int 0x80                           

    ; Sortir du Programme
    mov eax, 1                         
    xor ebx, ebx                       
    int 0x80                           
