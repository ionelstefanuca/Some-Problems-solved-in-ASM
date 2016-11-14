extern printf: proc
extern scanf : proc

.data
	msg1 db "Introduceti numarul de numere pe care le cititi: ",10,0
	msg2 db "%d\n",0  ;folosesc scanf
	msg3 db "Introdu numarul %d: ",0
	msg4 db "Minimul este %d, maximul este %d si diferenta este %d",10,0
	nr			 dq ?
	minim		 dq ?
	maxim		 dq ?
	nrCitit		 dq ?
	diferenta	 dq ?
	contor		 dq ?
.code

difMaxInModulDintre2NRdinVectorASM proc


	push rbp
	mov rbp,rsp

	lea rcx,qword ptr [msg1]
	sub rsp,32
	call printf
	add rsp,32

	lea rcx, qword ptr [msg2]
	lea rdx,nr
	sub rsp,32
	call scanf
	add rsp,32

	;initializam minimul si maximul
	mov rax,4294967295
	mov [minim],rax
	mov rax,-4294967295
	mov [maxim],rax


	mov contor,0
_for:
	cmp [nr],0
	je _dupaBucla
		lea rcx,qword ptr [msg3]
		mov rdx,contor
		inc rdx
		mov [contor], rdx
		sub rsp,32
		call printf
		add rsp,32

		lea rcx, qword ptr[msg2]
		lea rdx,nrCitit
		sub rsp,32
		call scanf
		add rsp, 32

	;transformam numerele negative in nr pozitive
		mov eax, dword ptr[nrCitit]
		cmp eax,0
		jg _eNegativ
		neg eax
		mov dword ptr [nrCitit],eax
		_eNegativ:


		mov rax,[nrCitit]
		cmp rax,minim
		jge _sari
		mov [minim],rax
		_sari:

		cmp rax,maxim
		jle _sari2
		mov[maxim],rax
		_sari2:

	dec [nr]
	jmp _for
_dupaBucla:

	mov rax,[maxim]
	mov rbx,[minim]
	sub rax,rbx

	mov [diferenta],rax					; am calculat difrenta

	lea rcx,qword ptr [msg4]
	mov rdx,[minim]
	mov r8d, dword ptr [maxim]
	mov r9d, dword ptr [diferenta]
	sub rsp,32
	call printf							;afisam mesajul de final	
	add rsp,32


	pop rbp
	ret
difMaxInModulDintre2NRdinVectorASM endp
end