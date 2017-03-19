assume cs:code

code segment

start:
	mov ax,cs
	mov ds,ax
	mov si,offset do0

	mov ax,0	
	mov es,ax
	mov di,200h

	mov cx,offset do0end-offset do0
	cld
	rep movsb	

	;…Ë÷√œÚ¡ø
	mov ax,0
	mov es,ax
	mov word ptr es:[0*4],200h
	mov word ptr es:[0*4+2],0

	mov ax,4c00h
	int 21h

do0:
	jmp short do0start
        db "OVERFLOW:NO!"


do0start:
	mov ax,0
	mov ds,ax
	mov di,202h

	mov ax,0b800h
	mov es,ax
	mov si,10*160+27*2

        mov cx,12

    s:	mov al,[di]
	mov es:[si],al
	inc di
	add si,2
	loop s

	mov ax,4c00h
	int 21h


do0end:nop

code ends
end start
