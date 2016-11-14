extern printf:proc

.data
	format1 db "[ASM] Anul %d nu este bisect",10,0 
	format2 db "[ASM]Anul %d este bisect",10,0 
	anul dq ?

.code
anBisectASM proc
	mov [anul],rcx


	xor rdx,rdx
	mov rax,[anul]
	mov rcx,4
	div rcx
cmp rdx,0
jne _anulNuEsteBisect
	xor rdx,rdx
	mov rax,[anul]
	mov rcx,100
	div rcx
cmp rdx,0
jne _end
	xor rdx,rdx
	mov rax,[anul]
	mov rcx,400
	div rcx
cmp rdx,0
je _end

jmp _end

_anulNuEsteBisect:
	lea rcx, qword ptr [format1]
	mov rdx,[anul]
	sub rsp,32
	call printf
	add rsp,32
jmp _final

_end:	
	lea rcx, qword ptr [format2]
	mov rdx,[anul]
	sub rsp,32
	call printf
	add rsp,32

_final:
	ret
anBisectASM endp
end