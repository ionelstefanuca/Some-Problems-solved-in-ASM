.data
	suma dq 0
	numarul dq ?
.code
cifraDeControlASM proc
	mov [numarul], rcx
	mov rax,rcx

_while1:
		mov rbx,0
		_while2:
			xor rdx,rdx
			mov rcx,10
			div rcx
			
			add rbx,rdx
			cmp rax,0
		jne _while2

		xchg rax,rbx

	cmp rax,9
jg _while1

	ret
cifraDeControlASM endp
end