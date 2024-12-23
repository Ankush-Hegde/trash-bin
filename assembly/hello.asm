CPU 8086
.MODEL small
.STACK 100h
.DATA
.CODE
main PROC

	mov dl,'H'
	mov ah,2
	int 21h

	mov dl,'E'
	mov ah,2
	int 21h

	mov dl,'L'
	mov ah,2
	int 21h

	mov dl,'L'
	mov ah,2
	int 21h

	mov dl,'O'
	mov ah,2
	int 21h

	mov dl,'i'
	mov ah,2
	int 21h

	mov dl,'W'
	mov ah,2
	int 21h

	mov dl,'O'
	mov ah,2
	int 21h

	mov dl,'R'
	mov ah,2
	int 21h

	mov dl,'L'
	mov ah,2
	int 21h

	mov dl,'D'
	mov ah,2
	int 21h

	mov ah,4ch
	int 21h

MAIN ENDP
END MAIN
