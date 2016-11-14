#include "stdafx.h"
#include<math.h>
//ex1
extern "C" int sumaCifreNumarASM(int numar);
//ex2
extern "C" void anBisectASM(int an);
//ex3
extern "C" void palindromASM(int nr);
//ex5
extern "C" int cifraDeControlASM(int cifra);
//ex7
extern "C" bool numarPrimASM(int nr);
//ex8
extern "C" void numerePrimeGemeneASM(int nr);
//ne jucam cu scanf
extern "C" void citesteCeva();
//suma recursiva
extern "C" int sumaRecursivaASM(int x);
//ex9
extern "C" void difMaxInModulDintre2NRdinVectorASM();


int sumaCifreNumar(int i)
{
	int suma = 0;
	int c;
	i = abs(i);
	
	while (i != 0)
	{
		c = i % 10;
		i = i / 10;
		suma += c;
	}

	return suma;
}

void anBisect(int an)
{
	if (((an % 4 == 0) && (an % 100 != 0)) || (an % 400 == 0))
	{
		printf("Anul %d este bisect\n", an);
	}
	else
		printf("Anul %d nu este bisect\n", an);
}

void palindrom(int nr)
{
	int invers = 0;
	int copie = nr;

	while (nr != 0)
	{
		int c = nr % 10;
		nr /= 10;
		invers = invers * 10 + c;
	}
	
	if (copie == invers)
	{
		printf("Numarul %d este palindrom\n", copie);
	}
	else
	{
		printf("Numarul %d nu este palindrom\n", copie);
	}
}

int cifraDeControl(int nr)
{
	int s = 0;
	while (nr > 9)
	{
		s = 0;
		while (nr!= 0)
		{
			int c = nr % 10;
			nr /= 10;
			s += c;
		}
		nr = s;
	}
	return s;
}

bool numarPrim(int nr)
{
	int jumatate = nr / 2;
	bool estePrim = true;
	for (int i = 2; i <= jumatate; i ++)
	{
		if (nr%i == 0)
		{
			estePrim = false;
			break;
		}
	}

	/*if (estePrim)
		printf("Numarul %d este prim\n", nr);
	else
		printf("Numarul %d nu este prim\n", nr);  */
	return estePrim;
}


void numerePrimeGemene(int nrPerechi)
{
	int i = 3;
	//(3, 5), (5, 7) și (7, 11)
	while (nrPerechi > 0)
	{
		int a = i;
		int b = i + 2;

		if (numarPrim(a))
		if (numarPrim(b))
		{
			if ((nrPerechi - 1) != 0)
				printf("(%d, %d) , ",a, b);
			else
				printf("(%d, %d)\n", a, b);

			nrPerechi--;
		}

		i++;
	}
}

int sumaRecursiv(int x)
{
	if (x == 0)
		return 0;
	return (x+ sumaRecursiv(x - 1));
}

void diferentaMaximaInModulDintreDouaNumere()
{
	int nr;
	printf("Introduceti numarul de numere pe care le cititi: ");
	scanf_s("%d", &nr);
	int minim = 999999999;
	int maxim = 0;
	int nrCitit;

	for (int i = 0; i < nr; i++)
	{
		printf("Introdu numarul %d: ",(i+1));
		scanf_s("%d", &nrCitit);

		if (minim > nrCitit)
			minim = nrCitit;

		if (nrCitit>maxim)
			maxim = nrCitit;
	}
	
	int diferenta = maxim - minim;
	printf("Minimul este %d, maximul este %d si diferenta este %d\n", minim, maxim, diferenta);
}


int _tmain(int argc, _TCHAR* argv[])
{
	int numar = -132234;
	printf("suma cifrelor numarului %d este %d\n", numar, sumaCifreNumar(numar));
	printf("[ASM] suma cifrelor numarului %d este %d\n", numar, sumaCifreNumarASM(numar));

	printf("\n\n\n");
	int anbisect = 2324;
	anBisect(anbisect);
	anBisectASM(23242);

	printf("\n\n\n");
	int palinNr = 132343231;
	palindrom(palinNr);
	palindromASM(palinNr);

	printf("\n\n\n");
	int cifracontrol = 54345364;
	printf("Crifra de control a numarului %d este %d\n", cifracontrol, cifraDeControl(cifracontrol));
	printf("[ASM] Crifra de control a numarului %d este %d\n", cifracontrol, cifraDeControlASM(cifracontrol));

	printf("\n\n\n");
	int nrprim = 55;
	numarPrim(nrprim);
	bool testPrim = numarPrimASM(nrprim);
	if (testPrim)
		printf("numarul %d este prim", nrprim);
	else
		printf("numarul %d nu este prim", nrprim);


	printf("\n\n\n");
	int numarperechiNrPrime = 3;
	printf("Primele %d perechi de numere prime gemene sunt: ", numarperechiNrPrime);
	numerePrimeGemene(numarperechiNrPrime);
	printf("\n[ASM] Primele %d perechi de numere prime gemene sunt: ", numarperechiNrPrime);
	numerePrimeGemeneASM(numarperechiNrPrime);


	//printf("\n\n[ASM]citeste un numar: ");
	//citesteCeva();

	int numarSumarecursiva = 5;
	printf("\n\nSuma recursiva a primelor %d numere este: %d\n", numarSumarecursiva, sumaRecursiv(numarSumarecursiva));
	printf("[ASm]Suma recursiva a primelor %d numere este: %d\n", numarSumarecursiva, sumaRecursivaASM(numarSumarecursiva));

	printf("\n\nDiferenta maxima dintre doua numere dintr-un vector:\n");
	//diferentaMaximaInModulDintreDouaNumere();
	difMaxInModulDintre2NRdinVectorASM();
	return 0;
}

