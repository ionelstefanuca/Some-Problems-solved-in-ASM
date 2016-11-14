.data
	suma dq 0
.code
sumaCifreNumarASM proc
	mov rax,rcx
	cmp eax, 0
	jnl _nuEnegativ
	neg eax
_nuEnegativ:

_bucla:
	mov rcx,10
	xor rdx,rdx
	div rcx
	add [suma],rdx

	cmp rax,0
jne _bucla

	mov rax,[suma]
	ret
sumaCifreNumarASM endp
end