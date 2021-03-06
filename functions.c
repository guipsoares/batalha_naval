#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

char alphabet[] = {"ABCDEFGHIJKLMNOP"};
double pontos1, pontos2;
int contador_destruido=0;  
int contador_destruido2=0; 



// setando todos os valores do tabuleiro como vazios
int zerandoTabuleiro(char ***tabuleiro1, char ***tabuleiro2, char ***tabaux1, char ***tabaux2)
{
	char ww[] = "   ";
	for(int i = 0; i < 16; i++) 
	{
		for(int j = 0; j < 16; j++) 
		{
			strcpy(tabuleiro1[i][j], ww);
			strcpy(tabuleiro2[i][j], ww);
			strcpy(tabaux1[i][j], ww);
			strcpy(tabaux2[i][j], ww); 
			pontos1 = 0.0;
			pontos2 = 0.0;
			contador_destruido = 0;
			contador_destruido2 = 0;
		}
    }
}

int printTabuleiro1(char ***tabuleiro1)
{
	if(!tabuleiro1) return -1;
	printf("\n\n      ___________________________________________________________________________________\n");
 	printf("     |                                                                                   |\n");
 	printf("     |                             P L A Y E R   1          PONTOS: %.2lf                |\n", pontos1);
 	printf("     |___________________________________________________________________________________|\n"); 
 	printf("\n\n\n"); 

	int z;
	printf("        ");
	for(int i = 0; i < 16; i++)
	{

		printf("|%c  ", alphabet[i]);
		 z = i+1;
		if(z==16)
		{
			printf("|\n");
			printf("     ===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|\n");
		}
	}
	for(int i = 0; i < 16; i++)
	{	

		int z = i+1;
		if(z>=10)
			printf("     |%i|", z);
		else
		printf("     |%i |", z);

		for(int j = 0; j < 16; j++) 
		{
			printf("%s|", tabuleiro1[i][j]);
		}
		printf("\n");
		printf("     ===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|\n");
	}
	printf("\n\n\n");
	return 0;
}

int printTabuleiro2(char ***tabuleiro2)
{
	if(!tabuleiro2) return -1;
	printf("\n\n      ___________________________________________________________________________________\n");
 	printf("     |                                                                                   |\n");
 	printf("     |                             P L A Y E R   2           PONTOS: %.2lf                |\n", pontos2);
 	printf("     |___________________________________________________________________________________|\n"); 
 	printf("\n\n\n"); 
	int z;
	printf("        ");
	for(int i = 0; i < 16; i++)
	{
		printf("|%c  ", alphabet[i]);
		 z = i+1;
		if(z==16)
		{
			printf("|\n");
			printf("     ===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|\n");
		}
	}
	for(int i = 0; i < 16; i++)
	{	

		int z = i+1;
		if(z>=10)
			printf("     |%i|", z);
		else
		printf("     |%i |", z);

		for(int j = 0; j < 16; j++) 
		{
			printf("%s|", tabuleiro2[i][j]);
		}
		printf("\n");
		printf("     ===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|\n");
	}
	printf("\n\n\n");
	return 0;
}

int setArmada1(char ***tabaux1)
{
	// ------------------------- PORTA-AVIOES(1) ------------------------------
	int z;
	//z=0 ->horizontal
	//z=1 ->vertical
	srand(time(NULL));
	z = rand() % 2;
	if(z==0)
	{
		int x=0, y=0;
		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(x < 4 || y < 1 || y==15 || y==0);
		if(strcmp(tabaux1[y][x], "   ") == 0){
			strcpy(tabaux1[y][x], "P2 ");
			strcpy(tabaux1[y-1][x-1], "P2 "), strcpy(tabaux1[y][x-1], "P2 "), strcpy(tabaux1[y+1][x-1], "P2 "); 
			strcpy(tabaux1[y-1][x-2], "P2 "), strcpy(tabaux1[y][x-2], "P2 "), strcpy(tabaux1[y+1][x-2], "P2 "); 
			strcpy(tabaux1[y-1][x-3], "P2 "), strcpy(tabaux1[y][x-3], "P2 "), strcpy(tabaux1[y+1][x-3], "P2 "); 
			strcpy(tabaux1[y][x-4], "P2 ");


		}
	}
	else 
	{
		int x=0, y=0;
		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(x==0 || x==15 || y < 4);
		if(strcmp(tabaux1[y][x], "   ") == 0){
			strcpy(tabaux1[y][x], "P2 ");
			strcpy(tabaux1[y-1][x], "P2 "), strcpy(tabaux1[y-1][x-1], "P2 "), strcpy(tabaux1[y-1][x+1], "P2 "); 
			strcpy(tabaux1[y-2][x], "P2 "), strcpy(tabaux1[y-2][x-1], "P2 "), strcpy(tabaux1[y-2][x+1], "P2 "); 
			strcpy(tabaux1[y-3][x], "P2 "), strcpy(tabaux1[y-3][x-1], "P2 "), strcpy(tabaux1[y-3][x+1], "P2 "); 
			strcpy(tabaux1[y-4][x], "P2 ");

		}
	} 

	//------------------- COURACADOS(2) ------------------

	for(int i = 0; i < 2; i++)
	{
		z = rand() % 3;
		if(z==0)
		{
			int x = 0, y = 0;
			do
			{
				x = rand() % 15;
				y = rand() % 15;	
			} while(x > 12 || y > 12 || strcmp(tabaux1[y][x], "   ") != 0 || strcmp(tabaux1[y+1][x], "   ") != 0 || strcmp(tabaux1[y+2][x], "   ") != 0 || strcmp(tabaux1[y+3][x], "   ") != 0 || strcmp(tabaux1[y+1][x+1], "   ") != 0 || strcmp(tabaux1[y+1][x+2], "   ") != 0 || strcmp(tabaux1[y][x+3], "   ") != 0 || strcmp(tabaux1[y+1][x+3], "   ") != 0 ||  strcmp(tabaux1[y+2][x+3], "   ") != 0 || strcmp(tabaux1[y+3][x+3], "   ") != 0);

			strcpy(tabaux1[y][x], "C2 ");
			strcpy(tabaux1[y+1][x], "C2 "), strcpy(tabaux1[y+2][x], "C2 "), strcpy(tabaux1[y+3][x], "C2 "), strcpy(tabaux1[y+1][x+1], "C2 ");
			strcpy(tabaux1[y+1][x+2], "C2 "), strcpy(tabaux1[y][x+3], "C2 "), strcpy(tabaux1[y+1][x+3], "C2 "), strcpy(tabaux1[y+2][x+3], "C2 "), strcpy(tabaux1[y+3][x+3], "C2 ");

		}
		else if(z==1)
		{
			int x = 0, y = 0;
			do
			{
				x = rand() % 15;
				y = rand() % 15;	
			} while(x > 12 || y < 3 || strcmp(tabaux1[y][x], "   ") != 0 || strcmp(tabaux1[y][x+1], "   ") != 0 || strcmp(tabaux1[y][x+2], "   ") != 0 || strcmp(tabaux1[y][x+3], "   ") != 0 || strcmp(tabaux1[y-1][x+1], "   ") != 0 || strcmp(tabaux1[y-2][x+1], "   ") != 0 || strcmp(tabaux1[y-3][x], "   ") != 0 || strcmp(tabaux1[y-3][x+1], "   ") != 0 || strcmp(tabaux1[y-3][x+2], "   ") != 0 || strcmp(tabaux1[y-3][x+3], "   ") != 0);
			strcpy(tabaux1[y][x], "C2 ");
			strcpy(tabaux1[y][x+1], "C2 "), strcpy(tabaux1[y][x+2], "C2 "), strcpy(tabaux1[y][x+3], "C2 "), strcpy(tabaux1[y-1][x+1], "C2 ");
			strcpy(tabaux1[y-2][x+1], "C2 "), strcpy(tabaux1[y-3][x], "C2 "), strcpy(tabaux1[y-3][x+1], "C2 "), strcpy(tabaux1[y-3][x+2], "C2 "), strcpy(tabaux1[y-3][x+3], "C2 ");

		} 
		else if(z==2)
		{
			int x = 0, y = 0;
			do
			{
				x = rand() % 15;
				y = rand() % 15;	
			} while(x > 13 || y > 13 || y==0 || x < 2 || strcmp(tabaux1[y][x], "   ") != 0 || strcmp(tabaux1[y+1][x], "   ") != 0 || strcmp(tabaux1[y-1][x-1], "   ") != 0 || strcmp(tabaux1[y][x-1], "   ") != 0 || strcmp(tabaux1[y+1][x-1], "   ") != 0 || strcmp(tabaux1[y+2][x-1], "   ") != 0 || strcmp(tabaux1[y-1][x-2], "   ") != 0 || strcmp(tabaux1[y][x-2], "   ") != 0 || strcmp(tabaux1[y+1][x-2], "   ") != 0 || strcmp(tabaux1[y+2][x-2], "   ") != 0);

			strcpy(tabaux1[y][x], "C2 "), strcpy(tabaux1[y+1][x], "C2 "), strcpy(tabaux1[y-1][x-1], "C2 "), strcpy(tabaux1[y][x-1], "C2 "), strcpy(tabaux1[y+1][x-1], "C2 "), strcpy(tabaux1[y+2][x-1], "C2 "), strcpy(tabaux1[y-1][x-2], "C2 "), strcpy(tabaux1[y][x-2], "C2 "), strcpy(tabaux1[y+1][x-2], "C2 "), strcpy(tabaux1[y+2][x-2], "C2 ");
		}
	}

		//-----------------------------TORPEDEIROS(3)-------------------
	for(int i = 0; i < 3; i++)
	{ 	int x=0, y=0;
		z = rand() % 4;
		if(z==0)
		{

			do
			{ 
				x = rand() % 15;
				y = rand() % 15;	
			} while(y==15 || y==0 || x==15 || x==0 || strcmp(tabaux1[y][x], "   ") != 0 || strcmp(tabaux1[y-1][x-1], "   ") != 0 || strcmp(tabaux1[y-1][x], "   ") != 0 || strcmp(tabaux1[y-1][x+1], "   ") != 0 || strcmp(tabaux1[y+1][x-1], "   ") != 0 || strcmp(tabaux1[y+1][x], "   ") != 0 ||  strcmp(tabaux1[y+1][x+1], "   ") != 0 );
				
			strcpy(tabaux1[y][x], "T2 "), strcpy(tabaux1[y-1][x-1], "T2 "), strcpy(tabaux1[y-1][x], "T2 "), strcpy(tabaux1[y-1][x+1], "T2 "), strcpy(tabaux1[y+1][x-1], "T2 "), strcpy(tabaux1[y+1][x], "T2 "), strcpy(tabaux1[y+1][x+1], "T2 ");
		}
		if(z==1)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x > 13 || y > 13 || y==0 || x < 2 || strcmp(tabaux1[y][x], "   ") != 0 || strcmp(tabaux1[y-1][x-1], "   ") != 0 || strcmp(tabaux1[y][x-1], "   ") != 0 || strcmp(tabaux1[y+1][x-1], "   ") != 0 || strcmp(tabaux1[y-1][x+1], "   ") != 0 || strcmp(tabaux1[y][x+1], "   ") != 0  || strcmp(tabaux1[y+1][x+1], "   ") != 0);
				
			strcpy(tabaux1[y][x], "T2 "), strcpy(tabaux1[y-1][x-1], "T2 "), strcpy(tabaux1[y][x-1], "T2 "), strcpy(tabaux1[y+1][x-1], "T2 "), strcpy(tabaux1[y-1][x+1], "T2 "), strcpy(tabaux1[y][x+1], "T2 "), strcpy(tabaux1[y+1][x+1], "T2 ");
		}
	 	if(z==2)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x > 13 || y > 14 || y==0  || strcmp(tabaux1[y][x], "   ") != 0 || strcmp(tabaux1[y-1][x+1], "   ") != 0 || strcmp(tabaux1[y][x+1], "   ") != 0 || strcmp(tabaux1[y+1][x+1], "   ") != 0 || strcmp(tabaux1[y-1][x+2], "   ") != 0 || strcmp(tabaux1[y][x+2], "   ") != 0  || strcmp(tabaux1[y+1][x+2], "   ") != 0);

			strcpy(tabaux1[y][x], "T2 "), strcpy(tabaux1[y-1][x+1], "T2 "), strcpy(tabaux1[y][x+1], "T2 "), strcpy(tabaux1[y+1][x+1], "T2 "), strcpy(tabaux1[y-1][x+2], "T2 "), strcpy(tabaux1[y][x+2], "T2 "), strcpy(tabaux1[y+1][x+2], "T2 ");

		}
		if(z==3)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x == 0 || y > 13 || x == 15  || strcmp(tabaux1[y][x], "   ") != 0 || strcmp(tabaux1[y+1][x-1], "   ") != 0 || strcmp(tabaux1[y+1][x], "   ") != 0 || strcmp(tabaux1[y+1][x+1], "   ") != 0 || strcmp(tabaux1[y+2][x-1], "   ") != 0 || strcmp(tabaux1[y+2][x], "   ") != 0  || strcmp(tabaux1[y+2][x+1], "   ") != 0);

			strcpy(tabaux1[y][x], "T2 "), strcpy(tabaux1[y+1][x-1], "T2 "), strcpy(tabaux1[y+1][x], "T2 "), strcpy(tabaux1[y+1][x+1], "T2 "), strcpy(tabaux1[y+2][x-1], "T2 "), strcpy(tabaux1[y+2][x], "T2 "), strcpy(tabaux1[y+2][x+1], "T2 ");
		}
	}
	// ---------------------------------------- HIDROAVIOES ------------

	for (int i = 0; i < 2; i++)
	{
		int x=0, y=0;
		z = rand() % 4;
		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(x > 12 || y == 15 || strcmp(tabaux1[y][x], "   ") != 0 || strcmp(tabaux1[y][x+1], "   ") != 0 || strcmp(tabaux1[y][x+2], "   ") != 0 || strcmp(tabaux1[y][x+3], "   ") != 0 || strcmp(tabaux1[y+1][x], "   ") != 0 || strcmp(tabaux1[y+1][x+1], "   ") != 0 || strcmp(tabaux1[y+1][x+2], "   ") != 0 || strcmp(tabaux1[y+1][x+3], "   ") != 0);

		strcpy(tabaux1[y][x], "H2 "), strcpy(tabaux1[y][x+1], "H2 "), strcpy(tabaux1[y][x+2], "H2 "), strcpy(tabaux1[y][x+3], "H2 ");
		strcpy(tabaux1[y+1][x], "H2 "), strcpy(tabaux1[y+1][x+1], "H2 "), strcpy(tabaux1[y+1][x+2], "H2 "), strcpy(tabaux1[y+1][x+3], "H2 ");

		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(y > 12 || x == 15 || strcmp(tabaux1[y][x], "   ") != 0 || strcmp(tabaux1[y+1][x], "   ") != 0 || strcmp(tabaux1[y+2][x], "   ") != 0 || strcmp(tabaux1[y+3][x], "   ") != 0 || strcmp(tabaux1[y][x+1], "   ") != 0 || strcmp(tabaux1[y+1][x+1], "   ") != 0 || strcmp(tabaux1[y+2][x+1], "   ") != 0 || strcmp(tabaux1[y+3][x+1], "   ") != 0);

		strcpy(tabaux1[y][x], "H2 "), strcpy(tabaux1[y+1][x], "H2 "), strcpy(tabaux1[y+2][x], "H2 "), strcpy(tabaux1[y+3][x], "H2 "), strcpy(tabaux1[y][x+1], "H2 "), strcpy(tabaux1[y+1][x+1], "H2 "), strcpy(tabaux1[y+2][x+1], "H2 "), strcpy(tabaux1[y+3][x+1], "H2 ");
		
	}  
	// fazendo com que as casas sem nenhuma embarcação sejam agua

	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			if(strcmp(tabaux1[i][j], "   ") == 0)
				strcpy(tabaux1[i][j], " * ");
		}
	}
}
// para o player 2
int setArmada2(char ***tabaux2)
{
	// ------------------------- PORTA-AVIOES(1) ------------------------------
	int z;
	//z=0 ->horizontal
	//z=1 ->vertical
	srand(time(NULL));
	z = rand() % 2;
	if(z==0)
	{
		int x=0, y=0;
		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(x < 4 || y < 1 || y==15 || y==0);
		if(strcmp(tabaux2[y][x], "   ") == 0)
		{
			strcpy(tabaux2[y][x], "P1 ");
			strcpy(tabaux2[y-1][x-1], "P1 "), strcpy(tabaux2[y][x-1], "P1 "), strcpy(tabaux2[y+1][x-1], "P1 "); 
			strcpy(tabaux2[y-1][x-2], "P1 "), strcpy(tabaux2[y][x-2], "P1 "), strcpy(tabaux2[y+1][x-2], "P1 "); 
			strcpy(tabaux2[y-1][x-3], "P1 "), strcpy(tabaux2[y][x-3], "P1 "), strcpy(tabaux2[y+1][x-3], "P1 "); 
			strcpy(tabaux2[y][x-4], "P1 ");
		}
	}
	else 
	{
		int x=0, y=0;
		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(x==0 || x==15 || y < 4);
		if(strcmp(tabaux2[y][x], "   ") == 0)
		{
			strcpy(tabaux2[y][x], "P1 ");
			strcpy(tabaux2[y-1][x], "P1 "), strcpy(tabaux2[y-1][x-1], "P1 "), strcpy(tabaux2[y-1][x+1], "P1 "); 
			strcpy(tabaux2[y-2][x], "P1 "), strcpy(tabaux2[y-2][x-1], "P1 "), strcpy(tabaux2[y-2][x+1], "P1 "); 
			strcpy(tabaux2[y-3][x], "P1 "), strcpy(tabaux2[y-3][x-1], "P1 "), strcpy(tabaux2[y-3][x+1], "P1 "); 
			strcpy(tabaux2[y-4][x], "P1 ");
		}
	} 

	//------------------- COURACADOS(2) ------------------

	for(int i = 0; i < 2; i++)
	{
		z = rand() % 3;
		if(z==0)
		{
			int x = 0, y = 0;
			do
			{
				x = rand() % 15;
				y = rand() % 15;	
			} while(x > 12 || y > 12 || strcmp(tabaux2[y][x], "   ") != 0 || strcmp(tabaux2[y+1][x], "   ") != 0 || strcmp(tabaux2[y+2][x], "   ") != 0 || strcmp(tabaux2[y+3][x], "   ") != 0 || strcmp(tabaux2[y+1][x+1], "   ") != 0 || strcmp(tabaux2[y+1][x+2], "   ") != 0 || strcmp(tabaux2[y][x+3], "   ") != 0 || strcmp(tabaux2[y+1][x+3], "   ") != 0 ||  strcmp(tabaux2[y+2][x+3], "   ") != 0 || strcmp(tabaux2[y+3][x+3], "   ") != 0);

			strcpy(tabaux2[y][x], "C1 ");
			strcpy(tabaux2[y+1][x], "C1 "), strcpy(tabaux2[y+2][x], "C1 "), strcpy(tabaux2[y+3][x], "C1 "), strcpy(tabaux2[y+1][x+1], "C1 ");
			strcpy(tabaux2[y+1][x+2], "C1 "), strcpy(tabaux2[y][x+3], "C1 "), strcpy(tabaux2[y+1][x+3], "C1 "), strcpy(tabaux2[y+2][x+3], "C1 "), strcpy(tabaux2[y+3][x+3], "C1 ");

		}
		else if(z==1)
		{
			int x = 0, y = 0;
			do
			{
				x = rand() % 15;
				y = rand() % 15;	
			} while(x > 12 || y < 3 || strcmp(tabaux2[y][x], "   ") != 0 || strcmp(tabaux2[y][x+1], "   ") != 0 || strcmp(tabaux2[y][x+2], "   ") != 0 || strcmp(tabaux2[y][x+3], "   ") != 0 || strcmp(tabaux2[y-1][x+1], "   ") != 0 || strcmp(tabaux2[y-2][x+1], "   ") !=  0 || strcmp(tabaux2[y-3][x], "   ") != 0 || strcmp(tabaux2[y-3][x+1], "   ") != 0 || strcmp(tabaux2[y-3][x+2], "   ") != 0 || strcmp(tabaux2[y-3][x+3], "   ") != 0);
			strcpy(tabaux2[y][x], "C1 ");
			strcpy(tabaux2[y][x+1], "C1 "), strcpy(tabaux2[y][x+2], "C1 "), strcpy(tabaux2[y][x+3], "C1 "), strcpy(tabaux2[y-1][x+1], "C1 ");
			strcpy(tabaux2[y-2][x+1], "C1 "), strcpy(tabaux2[y-3][x], "C1 "), strcpy(tabaux2[y-3][x+1], "C1 "), strcpy(tabaux2[y-3][x+2], "C1 "), strcpy(tabaux2[y-3][x+3], "C1 ");
		} 
		else if(z==2)
		{
			int x = 0, y = 0;
			do
			{
				x = rand() % 15;
				y = rand() % 15;	
			} while(x > 13 || y > 13 || y==0 || x < 2 || strcmp(tabaux2[y][x], "   ") != 0 || strcmp(tabaux2[y+1][x], "   ") != 0 || strcmp(tabaux2[y-1][x-1], "   ") != 0 || strcmp(tabaux2[y][x-1], "   ") != 0 || strcmp(tabaux2[y+1][x-1], "   ") != 0 || strcmp(tabaux2[y+2][x-1], "   ") != 0 || strcmp(tabaux2[y-1][x-2], "   ") != 0 || strcmp(tabaux2[y][x-2], "   ") != 0 || strcmp(tabaux2[y+1][x-2], "   ") != 0 || strcmp(tabaux2[y+2][x-2], "   ") != 0);

			strcpy(tabaux2[y][x], "C1 "), strcpy(tabaux2[y+1][x], "C1 "), strcpy(tabaux2[y-1][x-1], "C1 "), strcpy(tabaux2[y][x-1], "C1 "), strcpy(tabaux2[y+1][x-1], "C1 "), strcpy(tabaux2[y+2][x-1], "C1 "), strcpy(tabaux2[y-1][x-2], "C1 "), strcpy(tabaux2[y][x-2], "C1 "), strcpy(tabaux2[y+1][x-2], "C1 "), strcpy(tabaux2[y+2][x-2], "C1 ");
		}
	}

		//-----------------------------TORPEDEIROS(3)-------------------
	for(int i = 0; i < 3; i++)
	{ 	int x=0, y=0;
		z = rand() % 4;
		if(z==0)
		{

			do
			{ 
				x = rand() % 15;
				y = rand() % 15;	
			} while(y==15 || y==0 || x==15 || x==0 || strcmp(tabaux2[y][x], "   ") != 0 || strcmp(tabaux2[y-1][x-1], "   ") != 0 || strcmp(tabaux2[y-1][x], "   ") != 0 || strcmp(tabaux2[y-1][x+1], "   ") != 0 || strcmp(tabaux2[y+1][x-1], "   ") != 0 || strcmp(tabaux2[y+1][x], "   ") != 0 ||  strcmp(tabaux2[y+1][x+1], "   ") != 0);
				
			strcpy(tabaux2[y][x], "T1 "), strcpy(tabaux2[y-1][x-1], "T1 "), strcpy(tabaux2[y-1][x], "T1 "), strcpy(tabaux2[y-1][x+1], "T1 "), strcpy(tabaux2[y+1][x-1], "T1 "), strcpy(tabaux2[y+1][x], "T1 "), strcpy(tabaux2[y+1][x+1], "T1 ");
		}
		if(z==1)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x > 13 || y > 13 || y==0 || x < 2 || strcmp(tabaux2[y][x], "   ") != 0 || strcmp(tabaux2[y-1][x-1], "   ") != 0 || strcmp(tabaux2[y][x-1], "   ") != 0 || strcmp(tabaux2[y+1][x-1], "   ") != 0 || strcmp(tabaux2[y-1][x+1], "   ") != 0 || strcmp(tabaux2[y][x+1], "   ") != 0 || strcmp(tabaux2[y+1][x+1], "   ") != 0);
				
			strcpy(tabaux2[y][x], "T1 "), strcpy(tabaux2[y-1][x-1], "T1 "), strcpy(tabaux2[y][x-1], "T1 "), strcpy(tabaux2[y+1][x-1], "T1 "), strcpy(tabaux2[y-1][x+1], "T1 "), strcpy(tabaux2[y][x+1], "T1 "), strcpy(tabaux2[y+1][x+1], "T1 ");
		}
	 	if(z==2)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x > 13 || y > 14 || y==0  || strcmp(tabaux2[y][x], "   ") != 0 || strcmp(tabaux2[y-1][x+1], "   ") != 0 || strcmp(tabaux2[y][x+1], "   ") != 0 || strcmp(tabaux2[y+1][x+1], "   ") != 0 || strcmp(tabaux2[y-1][x+2], "   ") != 0 || strcmp(tabaux2[y][x+2], "   ") != 0  || strcmp(tabaux2[y+1][x+2], "   ") != 0);

			strcpy(tabaux2[y][x], "T1 "), strcpy(tabaux2[y-1][x+1], "T1 "), strcpy(tabaux2[y][x+1], "T1 "), strcpy(tabaux2[y+1][x+1], "T1 "), strcpy(tabaux2[y-1][x+2], "T1 "), strcpy(tabaux2[y][x+2], "T1 "), strcpy(tabaux2[y+1][x+2], "T1 ");

		}
		if(z==3)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x == 0 || y > 13 || x == 15  || strcmp(tabaux2[y][x], "   ") != 0 || strcmp(tabaux2[y+1][x-1], "   ") != 0 || strcmp(tabaux2[y+1][x], "   ") != 0 || strcmp(tabaux2[y+1][x+1], "   ") != 0 || strcmp(tabaux2[y+2][x-1], "   ") != 0 || strcmp(tabaux2[y+2][x], "   ") != 0 || strcmp(tabaux2[y+2][x+1], "   ") != 0);

			strcpy(tabaux2[y][x], "T1 "), strcpy(tabaux2[y+1][x-1], "T1 "), strcpy(tabaux2[y+1][x], "T1 "), strcpy(tabaux2[y+1][x+1], "T1 "), strcpy(tabaux2[y+2][x-1], "T1 "), strcpy(tabaux2[y+2][x], "T1 "), strcpy(tabaux2[y+2][x+1], "T1 ");
		}
	}
	// ---------------------------------------- HIDROAVIOES ------------

	for (int i = 0; i < 2; i++)
	{
		int x=0, y=0;
		z = rand() % 4;
		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(x > 12 || y == 15 || strcmp(tabaux2[y][x], "   ") != 0 || strcmp(tabaux2[y][x+1], "   ") != 0 || strcmp(tabaux2[y][x+2], "   ") != 0 || strcmp(tabaux2[y][x+3], "   ") != 0 || strcmp(tabaux2[y+1][x], "   ") != 0 || strcmp(tabaux2[y+1][x+1], "   ") != 0 || strcmp(tabaux2[y+1][x+2], "   ") != 0 || strcmp(tabaux2[y+1][x+3], "   ") != 0);

		strcpy(tabaux2[y][x], "H1 "), strcpy(tabaux2[y][x+1], "H1 "), strcpy(tabaux2[y][x+2], "H1 "), strcpy(tabaux2[y][x+3], "H1 ");
		strcpy(tabaux2[y+1][x], "H1 "), strcpy(tabaux2[y+1][x+1], "H1 "), strcpy(tabaux2[y+1][x+2], "H1 "), strcpy(tabaux2[y+1][x+3], "H1 ");

		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(y > 12 || x == 15 || strcmp(tabaux2[y][x], "   ") != 0 || strcmp(tabaux2[y+1][x], "   ") != 0 || strcmp(tabaux2[y+2][x], "   ") != 0 || strcmp(tabaux2[y+3][x], "   ") != 0 || strcmp(tabaux2[y][x+1], "   ") != 0 || strcmp(tabaux2[y+1][x+1], "   ") != 0 || strcmp(tabaux2[y+2][x+1], "   ") != 0 || strcmp(tabaux2[y+3][x+1], "   ") != 0);

		strcpy(tabaux2[y][x], "H1 "), strcpy(tabaux2[y+1][x], "H1 "), strcpy(tabaux2[y+2][x], "H1 "), strcpy(tabaux2[y+3][x], "H1 "), strcpy(tabaux2[y][x+1], "H1 "), strcpy(tabaux2[y+1][x+1], "H1 "), strcpy(tabaux2[y+2][x+1], "H1 "), strcpy(tabaux2[y+3][x+1], "H1 ");
		

	}  
	// fazendo com que as casas sem nenhuma embarcação sejam agua

	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			if(strcmp(tabaux2[i][j], "   ") == 0)
				strcpy(tabaux2[i][j], " * ");
		}
	}
	
	

}

void comoJogar(void)
{
  	printf("\n\n      ___________________________________________________________________________________\n");
    printf("     |                                                                                   |\n");
   	printf("     |                                 COMO JOGAR:                                       |\n");
    printf("     |                                                                                   |\n"); 
    printf("     | Batalha naval eh um jogo de tabuleiro de dois jogadores, no qual os jogadores tem |\n");
	printf("     |o objetivo de descobrir e eliminar as embarcacoes inimigas.                        |\n");
    printf("     |                                                                                   |\n");
    printf("     |    Para atacar uma embarcação, digite pow NumeroLetra, como pow 12A           	 |\n");
	printf("     |                                                                                   |\n");
    printf("     |->O vencedor eh aquele que consegue destruir todas as embarcacoes de seu adversario|\n");
    printf("     |->As pontuacoes dos jogadores sao contabilizadas indivualmente                     |\n");
    printf("     |->Acesse a aba 'Comandos' para ver as ferramentas necessarias para jogar           |\n");
    printf("     |                                                                                   |\n");
    printf("     |-------------------- Tenham um otimo jogo e que venca o melhor! -------------------|\n");
    printf("     |___________________________________________________________________________________|\n");  
 
}

void comandos(void)
{
    printf("\n      ___________________________________________________________________________________\n");
      printf("     |                                                                                   |\n");
      printf("     |                                  COMANDOS:                                        |\n");
      printf("     |                                                                                   |\n");
      printf("     |-> reset - inicia uma nova partida e volta ao estado inicial                       |\n");
      printf("     |-> sair - abandona o jogo                                                          |\n");
      printf("     |-> ajuda - exibe os possiveis comandos do jogo                                     |\n");
      printf("     |-> acaso - inicia um novo tabuleiro aleatorio, conserva seus pontos e o tempo      |\n");
      printf("     |->'gravar {nome do arquivo' - salva o jogo em um arquivo com o nome da forma       |\n");
      printf("     |tabuleiro-{timestamp}.txt (timestamp eh um numero inteiro que indica a data, hora e|\n");
      printf("     |hora, minuto e segundo de um sistema computacional)                                |\n");
      printf("     |->'carregar {nome do arquivo}' - carrega o estado do tabuleiro nas condicoes salvas|\n");
      printf("     |___________________________________________________________________________________|\n");
}


void desenvolvedores(void)
{
    printf("\n      ___________________________________________________________________________________\n");
    printf("     |                                                                                   |\n");
    printf("     |                                DESENVOLVEDORES:                                   |\n");
    printf("     |                                                                                   |\n");
    printf("     |   Guilherme Pedrilho Soares                             Leonardo Zaniboni Silva   |\n");
    printf("     |   guilherme_soares@usp.br                               leonardozaniboni@usp.br   |\n");
    printf("     |                                                                                   |\n");
    printf("     |                             Agradecimento especial:                               |\n");
    printf("     |                                                                                   |\n");
    printf("     |                           Professor : Jo Ueyiama                                  |\n");
    printf("     |                           Monitora: Ana Luisa Teixeira Costa                      |\n");
    printf("     |                           Monitor: Erikson Julio de Aguiar                        |\n");
    printf("     |___________________________________________________________________________________|\n");

}

int layout(void)
{

    printf("      ___________________________________________________________________________________\n");
    printf("     |                                                                  ~                |\n");
    printf("     |                                                              _ ~                  |\n");
    printf("     |                                               _____         | |                   |\n");
    printf("     |                              ________________|     |        | |                   |\n");
    printf("     |                _____________|______________________|________| |                   |\n");
    printf("     |              /_______________  __________________  |________| |_______            |\n");
    printf("     |             /_________________|                  |_|________|_|_______|           |\n");
    printf("     |      ______/  .===.===.===.   |  BATALHA  NAVAL  |  .===.===.===.===. |____       |\n");
    printf("     | ~ ~ \\________________________|__________________|_________________________/ ~ ~ ~ |\n");
    printf("     | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("     | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("     |___________________________________________________________________________________|\n");
    printf("     |                                                                                   |\n"); //
    printf("     |                                 (1) Iniciar jogo                                  |\n");
    printf("     |                                                                                   |\n");
    printf("     |                                 (2) Como jogar                                    |\n");
    printf("     |                                                                                   |\n");
    printf("     |                                 (3) Desenvolvedores                               |\n");
    printf("     |                                                                                   |\n");
    printf("     |                                 (4) Comandos                                      |\n");
    printf("     |                                                                                   |\n");
    printf("     |                                 (5) Sair                                          |\n");
    printf("     |                                                                                   |\n");
    printf("     |___________________________________________________________________________________|\n\n");

    
  

return 0;



}

int playervenceu(int *playervencedor)
{
	printf("      ___________________________________________________________________________________\n");
	printf("     |                                                                                   |\n");
	printf("     |                                                                                   |\n");
	printf("     |                          ____________________________                             |\n");
	printf("     |                         |____________________________|                            |\n");
	printf("     |                         \\__                        __/                            |\n");
	printf("     |                            \\__                  __/                               |\n");
	printf("     |                                 \\            /                                    |\n");
	printf("     |                                  \\          /                                     |\n");          //esse trofeu ta o crime
	printf("     |                                   \\        /                                      |\n");		  //parece uma caixa dagua
	printf("     |                                    \\      /                                       |\n");		  //vou fazer um decente com o tempo
	printf("     |                                     ||  ||                                        |\n");
	printf("     |                                     ||  ||                                        |\n");
	printf("     |                        _____________||__||______________                          |\n");
	printf("     |                       |   P L A Y E R %d V E N C E U     |                         |\n",*playervencedor);
	printf("     |                       |_________________________________|                         |\n");
	printf("     |___________________________________________________________________________________|\n");
}

int acaoP1(char ***tabuleiro1, char ***tabaux1, int *y, char ***tabuleiro2, char ***tabaux2, int *w)
{
	char atk[42], vazio[4] = "   ", estrela[4] = " * ", port_av[4] = "P2 ", cour[4] = "C2 ", torp[4] = "T2 ", hidro[4] = "H2 ";
	char letra='Z';
	int numero=0, coord, len;
	int i;     
	int playervencedor,o=0;                                           //defini um contador (contador_destruido) pra saber quantas 'partes' de embarcacoes foram destruidas                                                               //hora que o contador chega a 64 temos um vencedor
	//qdouble pontos, erro;											  //'o' serve pra desbugar o hidroaviao
	//printf("%.3lf\n", pontos1);									  //quando acertava outro barco dava como o hidroaviao acertado e acrescentava 2 ao contador

	printf("\n------>Jogador 1, realize sua acao:\n------>");         //coloquei uns print pra eu entender melhor aonde o tiro tava acertando
	setbuf(stdin, NULL);
	fgets(atk, 42, stdin);
	
	if(atk[0] == 'p' && atk[1] == 'o' && atk[2] == 'w')
	{
		if(atk[6] == '\n')
		{
			numero = atk[4] - '0';
			letra = (char) atk[5];
		}
		else if(atk[7] == '\n')
		{
			numero =  atk[5] - '0';
			letra = (char) atk[6];
			numero = numero + 10;
		}

		int number = numero - 1;
		len = strlen(alphabet);

		for(int i = 0; i < len; i++)
		{
			if(alphabet[i] == letra) {

				coord = i;
				break;
			}
		} 
 
		if(strcmp(tabaux1[number][coord], estrela) == 0)
		{
			printf("Voce acertou a agua!");
			if(pontos1 - 3.75 <= 0.0)
			{
				pontos1 = 0.0;
			}
			else
			{
				pontos1 -= 3.75;
			}

		}


		else if(strcmp(tabaux1[number][coord], estrela) != 0) {

			if(strcmp(tabaux1[number][coord], port_av) == 0)
			{
				if(strcmp(tabuleiro1[number][coord], vazio) == 0)
				{
					pontos1 += 42.968;
					if(o==0)contador_destruido++;
					printf("\n\n------>PORTA-AVIOES INIMIGO ATINGIDO\n");
					o=1;       
				}  else printf("Local ja atacado. perdeu a vez!!\n");
			}
			else if(strcmp(tabaux1[number][coord], cour) == 0)
			{
				if(strcmp(tabuleiro1[number][coord], vazio) == 0)
				{
					pontos1 += 78.125;
					if(o==0)contador_destruido++;
					printf("\n\n------>COURACADO INIMIGO ATINGIDO\n");
					o=1;
				} else printf("Local ja atacado. perdeu a vez!!\n");
			}
			else if(strcmp(tabaux1[number][coord], torp) == 0)
			{
				if(strcmp(tabuleiro1[number][coord], vazio) == 0)
				{
					pontos1 += 82.031;
					if(o==0)contador_destruido++;
					printf("\n------>TORPEDEIRO INIMIGO ATINGIDO\n");
					o=1;
				} else printf("Local ja atacado. perdeu a vez!!\n");			
			}
			else if(strcmp(tabaux1[number][coord], hidro) == 0)
			{
				if(strcmp(tabuleiro1[number][coord], vazio) == 0)
				{
					pontos1 += 125.000;
					if(o==0)
					{
						contador_destruido++;
						printf("\n\n------>HIDROAVIAO INIMIGO ATINGIDO\n");
						o=1;
					}
				} else printf("Local ja atacado. perdeu a vez!!\n");
			}
			

		} 
		
			if(contador_destruido==64)
			{
		 	  playervencedor=1;                                                //aqui temos um vencedor
		 	  playervenceu(&playervencedor); 						 			//funcao do trofeuzinho
			   *y=1;                                                  			//y=1 serve para sair do loop na main
			}	
		
		strcpy(tabuleiro1[number][coord], tabaux1[number][coord]);
		
	}

	if(atk[0] == 'r' && atk[1] == 'e' && atk[2] == 's')
	{
		zerandoTabuleiro(tabuleiro1, tabuleiro2, tabaux1, tabaux2);
		setArmada1(tabaux1);  
		setArmada2(tabaux2); 
	}

	if(atk[0] == 's' && atk[1] == 'a' && atk[2] == 'i' && atk[3] == 'r')
	{
		*w = 256;
		*y = 1;
	}

	if(atk[0] == 'a' && atk[1] == 'j' && atk[2] == 'u')
	{
		printf("Os seguintes comandos estao disponiveis para serem utilizados:\n\n");
		printf("---> sair - ira te encaminhar ao menu principal.\n");
		printf("---> reset - ira zerar o tabuleiro e os pontos, armando uma nova armada para cada jogador.\n");
		printf("---> ajuda - eh onde voce esta =)\n");
		printf("---> acaso - inicia um novo tabuleiro aleatorio, conserva seus pontos e tempo no relogio.\n");
		printf("---> gravar {nome do arquivo} - salva o jogo em um arquivo com o nome tabuleiro-{timestamp}.txt (timestamp eh um numero inteiro que indica a data, hora, minuto e segundo de um sistema computacional).\n");
		printf("---> carregar {nome do arquivo}  - carrega o estado do tabuleiro, pontuacao e o tempo no relogio de quando o jogo foi salvo.\n");
		system("sleep 04");
	}

	if(atk[0] == 'a' && atk[1] == 'c' && atk[2] == 'a')
	{
		int aux1 = pontos1;
		int aux2 = pontos2;
		zerandoTabuleiro(tabuleiro1, tabuleiro2, tabaux1, tabaux2);
		setArmada1(tabaux1);  
		setArmada2(tabaux2); 
		pontos1 = aux1;
		pontos2 = aux2;
	}	
 
	if(atk[0] == 'g' && atk[1] == 'r' && atk[2] == 'a')
	{
		char data[42] = "";

		strcat(data, "tabuleiro_");


		char data_seg[16] = "";
		char data_tempo_local[16] = "";
		time_t segundos = time(NULL);
		struct tm *dh = localtime(&segundos);

		sprintf(data_seg, "%ld", segundos);

		sprintf(data_tempo_local, "%i-%i-%i_%i:%i:%i", dh->tm_mday, dh->tm_mon+1, dh->tm_year+1900, dh->tm_hour, dh->tm_min, dh->tm_sec);
   		
		strcat(data, data_tempo_local);
		strcat(data, ".txt");

		FILE *create_arq;

		create_arq = fopen(data, "w");

		fprintf(create_arq, "%.2lf %.2lf\n", pontos1, pontos2);

		
		for(int i = 0; i < 16; i++)
		{
			for(int j = 0; j < 16; j++)
			{
				fprintf(create_arq, "%s,%s,%s,%s,", tabaux1[i][j], tabaux2[i][j], tabuleiro1[i][j], tabuleiro2[i][j]);
				
			}
			//fprintf(create_arq, "\n");
		} 

   		fclose(create_arq);
	}  

	if(atk[0] == 'c' && atk[1] == 'a' && atk[2] == 'r' && atk[3] == 'r')
	{
		char tab[35] = "";
		char data[35] = "";

		// for(int i = 0; i < 32; i++)
		// {
		// 	tab[i] = atk[i+9];
		// } 
		// tab[32] = '\0';
		sscanf(atk, "%s %s", data, tab);

		FILE *open_file;

		open_file = fopen(tab, "r");

	
		fscanf(open_file, "%lf %lf", &pontos1, &pontos2);
		
		for(int i = 0; i < 16; i++)
		{
			for(int j = 0; j < 16; j++)
			{
				fscanf(open_file, "%[^,],%[^,],%[^,],%[^,],", tabaux1[i][j], tabaux2[i][j], tabuleiro1[i][j], tabuleiro2[i][j]);
				
			}
		} 

 
		fclose(open_file);


	} 

	return 0;
} 



int acaoP2(char ***tabuleiro2, char ***tabaux2, int *y, char ***tabuleiro1, char ***tabaux1, int *w)
{
	char atk[42], vazio[4] = "   ", estrela[4] = " * ", port_av[4] = "P1 ", cour[4] = "C1 ", torp[4] = "T1 ", hidro[4] = "H1 ";
	char letra;
	int numero, coord, len;
	int playervencedor, o=0;
	//int ba, qa, N = 256, pt = 64;
	//double pontos, erro;

	printf("\n------>Jogador 2, realize sua acao:\n------>");
	setbuf(stdin, NULL);
	fgets(atk, 42, stdin);
	//if(strcmp(atk,"ajuda\0") == 0)
	//{
	//	comandos();
	//	acaoP2(tabuleiro2, tabaux2);
	//}
	
	if(atk[0] == 'p' && atk[1] == 'o' && atk[2] == 'w') 
	{
		if(atk[6] == '\n')
		{
			numero = atk[4] - '0';
			letra = (char) atk[5];
		}
		else if(atk[7] == '\n')
		{
			numero =  atk[5] - '0';
			letra = (char) atk[6];
			numero = numero + 10;
		}

		int number = numero - 1;
		len = strlen(alphabet);

		for(int i = 0; i < len; i++)
		{
			if(alphabet[i] == letra) {

				coord = i;
				break;
			}
		}

		if(strcmp(tabaux2[number][coord], estrela) == 0)
		{
			printf("\n\n------>Voce acertou a agua!");
			if(pontos2 - 3.75 <= 0.0)
			{
				pontos2 = 0.0;
			}
			else
			{
				pontos2 -= 3.75;
			}

		}


		else if(strcmp(tabaux2[number][coord], estrela) != 0) {

			if(strcmp(tabaux2[number][coord], port_av) == 0)
			{
				if(strcmp(tabuleiro2[number][coord], vazio) == 0)
				{
					pontos2 += 42.968;
					if(o==0)contador_destruido2++;
					printf("\n\n------>PORTA-AVIOES INIMIGO ATINGIDO\n");
					o=1;       
				}  else printf("Local ja atacado. perdeu a vez!!\n");
			}
			else if(strcmp(tabaux2[number][coord], cour) == 0)
			{
				if(strcmp(tabuleiro2[number][coord], vazio) == 0)
				{
					pontos2 += 78.125;
					if(o==0)contador_destruido2++;
					printf("\n\n------>COURACADO INIMIGO ATINGIDO\n");
					o=1;
				} else printf("Local ja atacado. perdeu a vez!!\n");
			}
			else if(strcmp(tabaux2[number][coord], torp) == 0)
			{
				if(strcmp(tabuleiro2[number][coord], vazio) == 0)
				{
					pontos2 += 82.031;
					if(o==0)contador_destruido2++;
					printf("\n------>TORPEDEIRO INIMIGO ATINGIDO\n");
					o=1;
				} else printf("Local ja atacado. perdeu a vez!!\n");			
			}
			else if(strcmp(tabaux2[number][coord], hidro) == 0)
			{
				if(strcmp(tabuleiro2[number][coord], vazio) == 0)
				{
					pontos2 += 125.000;
					if(o==0)
					{
						contador_destruido2++;
						printf("\n\n------>HIDROAVIAO INIMIGO ATINGIDO\n");
						o=1;
					}
				} else printf("Local ja atacado. perdeu a vez!!\n");
			}
			

		} 
		
		strcpy(tabuleiro2[number][coord], tabaux2[number][coord]);
		
		if(contador_destruido2==64)
			{
			playervencedor=2;             
			playervenceu(&playervencedor);               
			*y=1;                           
			}	
	}

	if(atk[0] == 'r' && atk[1] == 'e' && atk[2] == 's')
	{
		zerandoTabuleiro(tabuleiro1, tabuleiro2, tabaux1, tabaux2);
		setArmada1(tabaux1);  
		setArmada2(tabaux2); 
	}

	if(atk[0] == 's' && atk[1] == 'a' && atk[2] == 'i' && atk[3] == 'r')
	{
		*w = 256;
		*y = 1;
	}

	if(atk[0] == 'a' && atk[1] == 'j' && atk[2] == 'u')
	{
		printf("Os seguintes comandos estao disponiveis para serem utilizados:\n\n");
		printf("---> sair - ira te encaminhar ao menu principal.\n");
		printf("---> reset - ira zerar o tabuleiro e os pontos, armando uma nova armada para cada jogador.\n");
		printf("---> ajuda - eh onde voce esta =)\n");
		printf("---> acaso - inicia um novo tabuleiro aleatorio, conserva seus pontos e tempo no relogio.\n");
		printf("---> gravar {nome do arquivo} - salva o jogo em um arquivo com o nome tabuleiro-{timestamp}.txt (timestamp eh um numero inteiro que indica a data, hora, minuto e segundo de um sistema computacional).\n");
		printf("---> carregar {nome do arquivo} - carrega o estado do tabuleiro, pontuacao e o tempo no relogio de quando o jogo foi salvo.\n");
		system("---> sleep 04");
	}

	if(atk[0] == 'a' && atk[1] == 'c' &&  atk[2] == 'a')
	{
		int aux1 = pontos1;
		int aux2 = pontos2;
		zerandoTabuleiro(tabuleiro1, tabuleiro2, tabaux1, tabaux2);
		setArmada1(tabaux1);  
		setArmada2(tabaux2); 
		pontos1 = aux1;
		pontos2 = aux2;
	}	


	// salvando uma partida
	if(atk[0] == 'g' && atk[1] == 'r' && atk[2] == 'a')
	{
		char data[42] = "";

		strcat(data, "tabuleiro_");


		char data_seg[16] = "";
		char data_tempo_local[16] = "";
		time_t segundos = time(NULL);
		struct tm *dh = localtime(&segundos);

		sprintf(data_seg, "%ld", segundos);

		sprintf(data_tempo_local, "%i-%i-%i_%i:%i:%i", dh->tm_mday, dh->tm_mon+1, dh->tm_year+1900, dh->tm_hour, dh->tm_min, dh->tm_sec);
   		
		strcat(data, data_tempo_local);
		strcat(data, ".txt");

		FILE *create_arq;

		create_arq = fopen(data, "w");

		fprintf(create_arq, "%.2lf %.2lf\n", pontos1, pontos2);

		 for(int i = 0; i < 16; i++)
		{
			for(int j = 0; j < 16; j++)
			{
				fprintf(create_arq, "%s,%s,%s,%s,", tabaux1[i][j], tabaux2[i][j], tabuleiro1[i][j], tabuleiro2[i][j]);
			}
		} 


   		fclose(create_arq);
	}  

	//carregando uma partida previamente salva
	if(atk[0] == 'c' && atk[1] == 'a' && atk[2] == 'r' && atk[3] == 'r')
	{
		char tab[35] = "";

		for(int i = 0; i < 32; i++)
		{
			tab[i] = atk[i+9];
		} 


		
		FILE *open_file;

		open_file = fopen(tab, "r");

		fscanf(open_file, "%lf %lf", &pontos1, &pontos2);

		 for(int i = 0; i < 16; i++)
		{
			for(int j = 0; j < 16; j++)
			{
				fscanf(open_file, "%[^,],%[^,],%[^,],%[^,],", tabaux1[i][j], tabaux2[i][j], tabuleiro1[i][j], tabuleiro2[i][j]);
				
			}

		}  
 
		fclose(open_file);
	} 
	

	return 0;
}
