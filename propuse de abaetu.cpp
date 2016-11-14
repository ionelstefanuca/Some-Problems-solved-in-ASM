// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <malloc.h>
#include<string.h>

unsigned nrBits(int){
	_asm{
		//returneaza numarul de biti setati in reprezentarea interna a numarului primit ca parametru
		mov esi, [ebp+8]
		xor eax,eax

	_while:
		shr esi,1
		jz _final
		jnc _sari
			add eax,1
		_sari:

			 jmp _while
		 _final:

		add eax,1
	}
}

unsigned isPrime(int){
	_asm{
		mov esi, [ebp+8]
		shr esi,1   // avem jumatatea nr
		mov ecx,2

	_for:
		cmp ecx,esi
		je _endFor

		xor edx,edx
		mov eax, [ebp+8]
		div ecx
		cmp edx,0
		je _nuEPrim
		inc ecx

		jmp _for
	_endFor:

		mov eax,1
		jmp _final

	_nuEPrim:
			mov eax,0
_final:

	}
}

int palindrom(unsigned int){
	_asm{

		mov esi, [ebp+8]
		xor edi,edi
_while:
		mov eax,esi
		mov ebx,10
		xor edx,edx
		div ebx

		mov esi,eax

		mov eax,edi
		mov ecx,edx
		mul ebx
		add eax,ecx
		mov edi,eax

		cmp esi,0
		jne _while

		cmp edi, [ebp+8]
		jne _nuEPalindrom
		mov eax,1
		jmp _final
	_nuEPalindrom:
		mov eax,0

	_final:
	}
}

unsigned short powerOf2(int, int*){
	_asm{
		//Se da un vector prin intermediul a doi parametri: primul reprezinta numarul de elemente din vector iar al II-lea este pointer catre primul element din vector.
		//Functia returneaza numarul de elemente din vector - puteri ale lui doi.

		//idee rezolvare: nr multiple de 2 au in compozitia lor un singur bit de 1 in sir si restul 0
		xor edi,edi
		mov esi, [ebp+12]
		
		xor ecx,ecx

_while:
		cmp ecx, [ebp+8]
		je _final
		mov eax, [esi]


		xor edx,edx
	_while2:
		   shr eax,1
		   jnc _nuIncrementa
					inc edx
		   _nuIncrementa:

		   cmp edx, 2
			   je _endWhile2

			cmp eax,0
			je _nrEzero


	jmp _while2
	_nrEzero:
		inc edi 
	_endWhile2:

		inc ecx
		add esi,4
		jmp _while
	_final:

		mov eax,edi
	}
}


int progresie_aritmetica(int, int*){
	_asm{
		//Se da un vector prin intermediul a doi parametri: primul reprezinta numarul de elemente din vector iar al II-lea este pointer catre primul element din vector.
		// Functia retuneaza 1 daca elementele vectorului formeaza o progresie aritmetica, 0 in caz contrar

		mov esi, [ebp + 12]
		mov edi, [ebp + 8]
		sub edi, 2

		cmp edi, 3
		jl _nu

		xor ecx,ecx
_while:
		cmp ecx,edi
		je _da
		
		mov eax, [esi]
		lea ebx, [esi+8]
		mov ebx, [ebx]
		add eax,ebx
		lea ebx, [esi+4]
		mov ebx, [ebx]
		shl ebx,1
		cmp eax,ebx
		jne _nu
		
		
		inc ecx
		add esi,4
		jmp _while

_nu:
		mov eax,0
	jmp _final

_da:
		mov eax,1

_final:
	}
}

int toUpper(char*){
	_asm{
		//Faceti conversia sirului de caractere primit ca parametru, returnand numarul de caractere modificate.
		mov esi, [ebp+8]
		xor eax,eax
		xor ecx,ecx

	_while:
		mov al, [esi]
			cmp al, 97
			jl _literaMare

			cmp al, 122
			jg _literaMare

			inc ecx
			sub al, 32
			;   mov[esi], al //???? eroare accesare memorie 

			_literaMare:

		add esi,1
	cmp al,0
	jne _while

	mov eax,ecx
	}
}

int nrTok(char*){
	_asm{
		//Sa se returneze numarul de cuvinte din textul primit ca parametru. Separatorii sunt: ',',  ' ',   '.'
		xor edi,edi
		mov esi, [ebp+8]
	
		xor eax,eax

_while:
		mov al, [esi]

		cmp al,0
		je _end
		
		cmp al, ','
		je _sari
		cmp al, ' '
		je _sari
		cmp al, '.'
		je _sari

		mov ecx,1
jmp _dupaSari
_sari:
				cmp ecx,1
				jnz _dupaSari
				inc edi
				xor ecx,ecx
_dupaSari:

		add esi,1
		jne _while

	_end:
		mov eax,edi
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i = nrBits(123321);

	printf("%d\n", i);

	if (isPrime(11))
	{
		printf("Numarul este prim\n");
	}
	else
		printf("Numarul nu este prim\n");

	if (palindrom(123321))
	{
		printf("Numarul este palindrom\n");
	}
	else
	{
		printf("Numarul nu este palindrom\n");
	}

	int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,2,2 }; 
	int *p = v;
	short nrElemPuteri2 = powerOf2(12,p);
	printf("In vector sunt %d numere multimple de 2\n", nrElemPuteri2);



	int vv[] = { 1,4,7,10,13,16,19,22,25,28};
	int *pp = v;

	int progresite = progresie_aritmetica(10,pp);
	if (progresite)
	{
		printf("Numerele sunt in progresie aritmetica\n");
	}
	else
		printf("Numerele nu sunt in progresie aritmetica\n");

	char * sir = "Ana are mere";
	printf("Am convertit %d litere\n", toUpper(sir));


	char * test = "Aceasta este o fraza. Astazi, maine si poimaine voi invata assembly.";
	int nrCuvinte = nrTok(test);
	printf("In fraza sunt %d cuvinte\n", nrCuvinte);


	return 0;
}

