#include <string.h>
#include <unistd.h>

#include "../utils.h"

#define BUFFER_SIZE 128

#define PI 3
//PI nije 3.14 zato sto se za zadatak radi samo sa celim brojevima.

static int obim;
static int povrsina;

static int r = 0;

void unos_krug()
{
	write(1, "Unesite poluprecnik kruga:\n", strlen("Unesite poluprecnik kruga:\n"));

	char buffer[BUFFER_SIZE];

	read(0, buffer, BUFFER_SIZE);

	r = atoi(buffer);

	char rC[10];
	int len = itoa(r, rC);

	write(1, "\n\nUspesan unos! Vas unos je: \n", strlen("\n\nUspesan unos! Vas unos je: \n"));
	write(1, rC, len);	

	write(1, "\n\n\n", strlen("\n\n\n"));
}



int obim_krug()
{
	if(r == 0)
	{
	write(1, "Poluprecnik nije validan, ponoviti unos.\n", strlen("Poluprecnik nije validan, ponoviti unos.\n"));
	return 0;
	}

	__asm__(
		"imull %%ebx, %%eax;"
		"imull %%ecx, %%eax;"
		:"=a" (obim)
		:"a" (r), "b" (PI), "c" (2)	
	);

	return obim;
}



int povrsina_krug()
{
	if(r == 0)
	{
	write(1, "Poluprecnik nije validan, ponoviti unos.\n", strlen("Poluprecnik nije validan, ponoviti unos.\n"));
	return 0;
	}

	__asm__(
		"imull %%eax, %%eax;"
		"imull %%ebx, %%eax;"
		:"=a" (povrsina)
		:"a" (r), "b" (PI)	
	);

	return povrsina;
}



