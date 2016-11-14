.data
.code

sumaRecursivaASM proc
	cmp rcx,0
	jne _apelRecursiv
	mov rax,0
	ret

_apelRecursiv:
	dec rcx
	call sumaRecursivaASM
	inc rcx
	add rax,rcx
	
	ret
sumaRecursivaASM endp
end