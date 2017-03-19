assume cs:code,ds:data,ss:stack,es:display

data segment

	db 10 dup(0)
	dd 123456789

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
	;mov ax,12345
	mov bx,data
	mov ds,bx
	mov si,0	;ds:si用于data寻址
	mov ax,ds:[si+10]	;存放倒置，ax存放低位，dx高位	
	mov dx,ds:[si+12]	
	call numtostr
	call show_str1

	mov ax,4c00h
	int 21h

numtostr:
	push ax
	push si
	push dx
	push cx
	push bx
	mov bx,0

    s0:
	mov cx,10d

 divdw: 		;除法溢出解决
	push bx		;bx用于计数，需要先保存在堆栈里面
	push ax	
	mov ax,dx
	mov dx,0
	div cx
	mov bx,ax
	pop ax
	div cx
	mov cx,dx
	mov dx,bx
	pop bx

	cmp ax,0
	jz s1

	;jcxz s1
	add cx,30h
	push cx
	inc bx
	jmp s0

    s1:
	add cx,30h
	push cx
	inc bx
	mov cx,bx
	mov si,0

    s2:
	pop ax
	mov ds:[si],al
	inc si
	loop s2

	pop bx
	pop cx
	pop dx
	pop si
	pop ax
	ret


show_str1:

	mov di,si

	mov ax,0b800h         ;es:[si]寻址显示
	mov es,ax
	mov si,10*160+27*2

	mov cx,9

    m:  mov al,[di]
	mov es:[si],al
	inc di
	add si,2
        loop m

	ret



code ends
end start
