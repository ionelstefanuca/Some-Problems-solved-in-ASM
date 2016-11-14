// bubble sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void boobleSort(int *, int){
	_asm
	{
		mov esi, [ebp+8] //vectorul
		mov edi, [ebp+12] //nr elemente

		xor ecx,ecx
		xor eax,eax
		xor ebx,ebx

_for1:
		cmp ecx, [ebp+12]
		jge _final

			_for2:
				cmp eax,[ebp + 12]
				jge _endFor2

				lea edx, [esi + 4 * eax] // in edx avem v[j]
				mov edx, [edx]

				lea ebx, [esi + 4 * ecx] // in ebx avem v[i]
				mov ebx, [ebx]


				cmp ebx,edx
				jge _nuSchimba                        //sortare crescatoare; jle pentru sortare descrescatoare
					lea edi, [esi + 4 * ecx]
					mov[edi], edx
					lea edi, [esi + 4 * eax]
					mov[edi], ebx

				_nuSchimba:


				inc eax
			jmp _for2
			_endFor2:

		inc ecx
		xor eax,eax
jmp _for1
_final:
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int v[] = {9,0,8,7,6,1,2,4,5,3};
	int *p = v;

	printf("Sirul inainte de sortare:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");

	boobleSort(p, 10);


	printf("\nSirul dupa sortare:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n\n\n");


	return 0;
}

