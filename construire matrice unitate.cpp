// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
//Construiti matricea unitate (1 pe diagonala, 0 in rest)
void matrice_unitate(int **, int)
{
	__asm
	{
		mov esi, [ebp+8]  // aci avem vectorukl
		xor ecx,ecx

_while1:
		cmp ecx, [ebp+12]
		jge _final
		mov edi, [esi]
		add esi,4


		xor eax,eax
			_while2:
						cmp eax, [ebp+12]
					   jge _final1

					   cmp eax,ecx
					   jne _sari1
							   mov dword ptr[edi], 1
							   add edi, 4
							   inc eax
							   jmp _while2
					   _sari1:

					   mov dword ptr[edi],0
					   add edi, 4
					inc eax
			jmp _while2
		_final1:

		inc ecx

jmp _while1
		_final:


	}
}

void main()
{
	int n = 5, i;
	int **mat;
	mat = (int**)malloc(n*sizeof(int*));
	for (i = 0; i<n; i++){
		mat[i] = (int*)malloc(n*sizeof(int));
	}

	_asm
	{
		push n
			push mat
			call matrice_unitate
			add esp, 8
	}

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

