; in prima bucla am pus cifrele pe stiva
; in a doua bucla am citit stiva ca pe o coada
; dupa care curat stiva, adug 8*numarul de numere

extern printf:proc

.data
	nu db "[ASM] numarul %d nu este palindrom",10,0
	da db "[ASM] numarul %d  este palindrom",10,0
	contor dq ?
	numar dq ?
	copie dq 0
.code
palindromASM proc
	mov [numar],rcx
	mov rax,rcx	
	mov rcx,10

	mov rbx,0		;joaca rod de contor
_bucla:
	inc rbx
	xor rdx,rdx
	div rcx
	push rdx
	cmp rax,0
jne _bucla

	mov[contor],rbx

_bucla2:
	mov rax,[copie]
	mov rcx,10
	mul rcx
	
	dec rbx
	mov rcx,[rsp+8*rbx]
	add rax,rcx
	mov [copie],rax
	
	cmp rbx,0
jne _bucla2
	
	mov rax,[contor]
	mov rbx,8
	mul rbx
	add rsp,rax


	mov rax,[copie]
	mov rbx,[numar]
	cmp rax,rbx
	jne _nuEstePalindrom


jmp _final
_nuEstePalindrom:
	lea rcx, qword ptr[nu]
	mov rdx,[numar]
	sub rsp,32
	call printf
	add rsp , 32

jmp _iesire

_final:	
	lea rcx, qword ptr[da]
	mov rdx,[numar]
	sub rsp,32
	call printf
	add rsp , 32

_iesire:
	ret
palindromASM endp
end