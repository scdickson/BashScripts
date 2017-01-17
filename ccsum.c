#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		exit(0);
	}
	
	char cc[20];
	int check, len, prod, j;
	strcpy(cc, argv[1]);

	if((cc[0] != '3')&&(cc[0] != '4')&&(cc[0] != '5'))
	{
		printf("Not valid. Must begin with a 3, 4, or 5.\n");
		exit(0);
	}
	else if((cc[0] == '5')&&(strlen(cc) != 16))
	{
		printf("Not valid. Mastercard must have 16 digits.\n");
		exit(0);
	}
	else if((cc[0] == '4')&&(strlen(cc) != 13)&&(strlen(cc) != 16))
	{
		printf("Not valid. Visa must have 13 or 16 digits.\n");
		exit(0);
	}
	else if((cc[0] == '3')&&(strlen(cc) != 15))
	{
		printf("Not valid. American Express must have 15 digits\n");
		exit(0);
	}

	check = 0;
	len = strlen(cc);

	for(j = 1; j <= len; j++)
	{
		prod = cc[j-1]-'0';
		if((len-j) % 2)	prod = prod * 2;
		if(prod >= 10)	prod = prod - 9;
		check = check + prod;
	}

	if((check % 10) == 0)
	{
		printf("Valid. Card passed checksum test.\n");
	}
	else
	{
		printf("Not valid. Card did not pass checksum test.\n");
	}
	
}
