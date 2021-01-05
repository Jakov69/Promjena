#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	char ime[32];
	char prezime[32];
	int bodovi;

}student;

int BroRed(char*);
int Ispis(char*, int);

int main()
{
	int brr = 0;

	brr = BroRed("lista5.txt");

	Ispis("lista5.txt", brr);

	return 0;
}

int BroRed(char* ImeDat)
{
	FILE* ulz=NULL;
	int br = 0;
	ulz = fopen(ImeDat, "r");

	char *buffer = malloc(1024 * sizeof(char));
	if (buffer == NULL) {
		return -1;
	}

	if (ulz == NULL)
	{
		printf("Greska pri otvaranju datoteke!\n");
		return -1;
	}

	while (1)
	{
		if (fgets(buffer, 100, ulz) == NULL)
			break;
		br++;
	}

	free(buffer);
	fclose(ulz);
	return br;
}

int Ispis(char* ImeDat, int BrojStud)
{
	int i = 0;
	int  maxbr=0;
	double *realbr;
	double temp = 0;
	student* stud = NULL;
	FILE* ulz = NULL;
	ulz = fopen(ImeDat, "r");

	if (ulz == NULL)
	{
		puts("Greska u otvaranju datoteke!\n");
		return 0;
	}

	printf("Unesite maksimalan broj bodova na kolokviju:");
	scanf("%d", &maxbr);

	stud = (student*)malloc(BrojStud * sizeof(student));
	if (stud == NULL) {
		return -1;
	}

	realbr = (double*)malloc(BrojStud * sizeof(double));
	if (realbr == NULL) {
		return -1;
	}
	

	printf("\nIme\tPrezime\t\tAps.br.bodova\t\tRel.br.bodova\n");
	while (!feof(ulz)) {
	
		fscanf(ulz, "%s %s %d", stud[i].ime, stud[i].prezime, &stud[i].bodovi);
		*(realbr+i) = (double)stud[i].bodovi / maxbr*100;
		
		printf("%s\t%s\t\t%d\t\t\t%.2f\n", stud[i].ime, stud[i].prezime, stud[i].bodovi, *(realbr + i));
		
	}

	fclose(ulz);
	free(realbr);
	return 0;
}


