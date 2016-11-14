extern printf: proc
extern numarPrimASM: proc
.data
	nrPerechi dq ?
	aa dq ?
	bb dq ?
	contor dq 2
	afisare1 db "(%d , %d) ",0

.code

numerePrimeGemeneASM proc
	mov rbx,rcx
_while:
	inc [contor]
	mov rcx,[contor]
	mov [aa],rcx
	call numarPrimASM
	cmp rax,1
	jne _while

	inc [contor]
	inc [contor]
	mov rcx,[contor]
	mov [bb],rcx
	call numarPrimASM
	cmp rax,1
	jne _while


	lea rcx, qword ptr [afisare1]
	mov rdx, qword ptr [aa]
	mov r8d, dword ptr[bb]
	sub rsp,32
	call printf
	add rsp,32


	dec rbx
	cmp rbx,0
	jne _while
	
	ret
numerePrimeGemeneASM endp
end