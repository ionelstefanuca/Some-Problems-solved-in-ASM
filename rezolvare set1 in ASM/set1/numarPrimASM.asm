extern printf: proc

.data
	numarul dq ?
	jumatate dq ?

	nu db "[ASM] numarul %d nu este prim",10,0
	da db "[ASM] numarul %d este prim",10,0
.code

numarPrimASM proc
	mov [numarul],rcx
	shr rcx,1
	mov [jumatate],rcx

	mov rcx,1
_while:
			
			xor rdx,rdx
			inc rcx
			mov rax,[numarul]
			div rcx
		cmp rdx,0
		je _nuEstePrim

	cmp rcx,[jumatate]
jle _while
je _nuEstePrim

	;sub rsp,32
	;lea rcx,qword ptr[da]
	;mov rdx,[numarul]
	;call printf
	;add rsp,32

	mov rax,1
	ret

jmp _final	


_nuEstePrim:
	;sub rsp,32
	;lea rcx,qword ptr[nu]
	;mov rdx,[numarul]
	;call printf
	;add rsp,32

	mov rax,0
	ret
_final:	

ret
numarPrimASM endp
end