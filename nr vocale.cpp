// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
//Determinati numarul de vocale dintr-un sir de caractere
int lungime(char *)
{
	_asm{
		mov esi, [ebp+8]
		xor ecx,ecx

_while :
		cmp [esi], 0
		je _final

		cmp[esi], 'a'
		je _eVocala
		cmp[esi], 'e'
		je _eVocala
		cmp[esi], 'i'
		je _eVocala
		cmp[esi], 'o'
		je _eVocala
		cmp[esi], 'u'
		je _eVocala

		add esi, 1
jmp _while

_eVocala :
			add ecx,1
			add esi, 1
jmp _while
_final:

			mov eax,ecx
	}
}

void main()
{
	char *sir = "Numarul de vocale";
	int l;

	_asm{
		push sir
		call lungime
		add esp,4
		mov l,eax
	}

	printf("Numarul de vocale este: %d\n", l);
}
