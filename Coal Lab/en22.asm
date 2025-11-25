.model small
.stack 100h
.data 
 table db 32 dup (00)
        db 32
        db 32 dup (00)
        db 'DEFGHIJKLMNOPQRSTUVWXYZABC'
        db 6 dup (00)
        db 'defghijklmnopqrstuvwxyzabc'
ta2ble db 32 dup (00)
       db 32
       db 32 dup (00)
       db 'XYZABCDEFGHIJKLMNOPQRSTUVW'    
       db 6 dup (00)
       db 'xyzabcdefghijklmnopqrstuvw'  
msg1 db 'Output: $'
msg2 db 'Next Output: $'
  msg db 'Enter: $'
  dalwana db 30 dup (00)

  
.code
main proc
mov ax, @data
mov ds, ax
mov dx, offset msg
mov ah, 09
int 21h	
mov si, offset dalwana
mov cl, 0
aa:
mov ah, 01
int 21h
cmp al, '.'
je exit_loop1
mov [si], al
inc cl
inc si
jmp aa
exit_loop1:
mov si, offset dalwana
mov bx, offset table
bb:
mov al, [si]
cmp al, 0
je exit_loop2
XLAT
mov [si],al
inc si
jmp bb
exit_loop2:
mov dx, offset msg1
mov ah, 09
int 21h	
mov ch, cl
mov si, offset dalwana
cc:
mov dl, [si]
mov ah, 02
int 21h
inc si
dec ch
jnz cc
abc:
mov si, offset dalwana
mov bx, offset ta2ble
mov ch, cl
zz:
mov al, [si]
XLAT
mov [si],al
inc si
dec ch
jnz zz
yy:
mov dx, offset msg2
mov ah, 09
int 21h	
mov si, offset dalwana
mov ch, cl
gg:
mov dl, [si]
mov ah, 02
int 21h
inc si
dec ch
jnz gg
exit:
mov ah, 4ch
int 21h
main endp
end main


