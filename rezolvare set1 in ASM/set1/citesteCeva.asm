extern scanf:proc
extern printf:proc

.data
	format db "%d\n",10,0
	afisare db "Ai citit %d",10,0
	numar dq   ?
.code

citesteCeva proc
	push rbp
	mov rbp,rsp
	lea rcx, qword ptr [format]
	lea rdx,numar
	sub rsp,32
	call scanf
	add rsp,32

	lea rcx,qword ptr [afisare]
	mov rdx, [numar]
	sub rsp,32
	call printf
	add rsp,32

	pop rbp
	ret
citesteCeva endp
end