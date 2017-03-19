assume cs:code,ds:data

data segment

        db 'heLLoNisy'

data ends


code segment

start:
        mov ax,data
        mov bx,0
        mov ds,ax
        mov cx,9

s:      mov al,[bx]
        and al,11011111B
        mov [bx],al
        inc bx
        loop s     

        mov ax,4c00h
        int 21h

code ends
end start
