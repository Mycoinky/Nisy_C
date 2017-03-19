assume cs:code,ds:data,ss:stack,es:display

data segment

	db 'Welcome to SEC',0

data ends

;########################################

stack segment

        db  8 dup(0)

stack ends

;########################################

display segment

        db 1024 dup(0)

display ends

;########################################

code segment
start:
        mov ax,data
        mov ds,ax
        mov bp,0

        mov dh,8
        mov dl,3
        mov cl,2

        call show_str
        mov ax,4c00h
        int 21h

show_str:
        push cx
        push bp
        mov ax,0B800h
        mov es,ax
        mov al,0a0h
        dec dh
        mul dh
        mov bx,ax

        mov al,2
        mul dl
        sub dl,2
        add bx,ax

        mov di,0
        mov ch,0
        mov al,cl

    s:  
        mov cl,ds:[bp]
        jcxz next
        mov es:[bx+di],cl
        mov es:[bx+di+1],al
        add di,2
        inc bp
        jmp s

next:
        pop bp
        pop cx
        ret

code ends
end start














