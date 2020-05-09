#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <string.h>

char alphabet[] = {"ABCDEFGHIJKLMNOP"};
double pontos1, pontos2;

// setando todos os valores do tabuleiro como vazios
int zerandoTabuleiro(char ***tabuleiro1, char ***tabuleiro2, char ***tabaux1, char ***tabaux2)
{
	for(int i = 0; i < 16; i++) 
	{
		for(int j = 0; j < 16; j++) 
		{
			tabuleiro1[i][j] = "   ";
			tabuleiro2[i][j] = "   ";
			tabaux1[i][j] = "   ";
			tabaux2[i][j] = "   ";
			pontos1 = 0.0;
			pontos2 = 0.0;
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
	z = rand() % 2;
	if(z==0)
	{
		int x=0, y=0;
		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(x < 4 || y < 1 || y==15 || y==0);
		if(tabaux1[y][x]=="   "){
			tabaux1[y][x] = "P2 ";
			tabaux1[y-1][x-1] = "P2 ", tabaux1[y][x-1] = "P2 ", tabaux1[y+1][x-1] = "P2 "; 
			tabaux1[y-1][x-2] = "P2 ", tabaux1[y][x-2] = "P2 ", tabaux1[y+1][x-2] = "P2 "; 
			tabaux1[y-1][x-3] = "P2 ", tabaux1[y][x-3] = "P2 ", tabaux1[y+1][x-3] = "P2 "; 
			tabaux1[y][x-4] = "P2 ";
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
		if(tabaux1[y][x]=="   "){
			tabaux1[y][x] = "P2 ";
			tabaux1[y-1][x] = "P2 ", tabaux1[y-1][x-1] = "P2 ", tabaux1[y-1][x+1] = "P2 "; 
			tabaux1[y-2][x] = "P2 ", tabaux1[y-2][x-1] = "P2 ", tabaux1[y-2][x+1] = "P2 "; 
			tabaux1[y-3][x] = "P2 ", tabaux1[y-3][x-1] = "P2 ", tabaux1[y-3][x+1] = "P2 "; 
			tabaux1[y-4][x] = "P2 ";
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
			} while(x > 12 || y > 12 || tabaux1[y][x]!="   " || tabaux1[y+1][x]!="   " || tabaux1[y+2][x]!="   " || tabaux1[y+3][x]!="   " || tabaux1[y+1][x+1]!="   " || tabaux1[y+1][x+2]!="   " || tabaux1[y][x+3]!="   " || tabaux1[y+1][x+3]!="   " ||  tabaux1[y+2][x+3]!="   " ||tabaux1[y+3][x+3]!="   ");

			tabaux1[y][x] = "C2 ";
			tabaux1[y+1][x] = "C2 ", tabaux1[y+2][x] = "C2 ", tabaux1[y+3][x] = "C2 ", tabaux1[y+1][x+1] = "C2 ";
			tabaux1[y+1][x+2] = "C2 ", tabaux1[y][x+3] = "C2 ", tabaux1[y+1][x+3] = "C2 ", tabaux1[y+2][x+3] = "C2 ", tabaux1[y+3][x+3] = "C2 ";

		}
		else if(z==1)
		{
			int x = 0, y = 0;
			do
			{
				x = rand() % 15;
				y = rand() % 15;	
			} while(x > 12 || y < 3 || tabaux1[y][x]!="   " || tabaux1[y][x+1]!="   " || tabaux1[y][x+2]!="   " || tabaux1[y][x+3]!="   " || tabaux1[y-1][x+1]!="   " || tabaux1[y-2][x+1]!="   " || tabaux1[y-3][x]!="   " || tabaux1[y-3][x+1]!="   " || tabaux1[y-3][x+2]!="   " || tabaux1[y-3][x+3]!="   ");
			tabaux1[y][x] = "C2 ";
			tabaux1[y][x+1] = "C2 ", tabaux1[y][x+2] = "C2 ", tabaux1[y][x+3] = "C2 ", tabaux1[y-1][x+1] = "C2 ";
			tabaux1[y-2][x+1] = "C2 ", tabaux1[y-3][x] = "C2 ", tabaux1[y-3][x+1] = "C2 ", tabaux1[y-3][x+2] = "C2 ", tabaux1[y-3][x+3] = "C2 ";
		} 
		else if(z==2)
		{
			int x = 0, y = 0;
			do
			{
				x = rand() % 15;
				y = rand() % 15;	
			} while(x > 13 || y > 13 || y==0 || x < 2 || tabaux1[y][x] != "   " || tabaux1[y+1][x] != "   " || tabaux1[y-1][x-1] != "   " || tabaux1[y][x-1] != "   " || tabaux1[y+1][x-1] != "   " || tabaux1[y+2][x-1] != "   " || tabaux1[y-1][x-2] != "   " || tabaux1[y][x-2] != "   " || tabaux1[y+1][x-2] != "   " || tabaux1[y+2][x-2] != "   ");

			tabaux1[y][x] = "C2 ", tabaux1[y+1][x] = "C2 ", tabaux1[y-1][x-1] = "C2 ", tabaux1[y][x-1] = "C2 ", tabaux1[y+1][x-1] = "C2 ", tabaux1[y+2][x-1] = "C2 ", tabaux1[y-1][x-2] = "C2 ", tabaux1[y][x-2] = "C2 ", tabaux1[y+1][x-2] = "C2 ", tabaux1[y+2][x-2] = "C2 ";
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
			} while(y==15 || y==0 || x==15 || x==0 || tabaux1[y][x] != "   " || tabaux1[y-1][x-1] != "   " || tabaux1[y-1][x] != "   " || tabaux1[y-1][x+1] != "   " || tabaux1[y+1][x-1] != "   " || tabaux1[y+1][x] != "   " ||  tabaux1[y+1][x+1] != "   " );
				
			tabaux1[y][x] = "T2 ", tabaux1[y-1][x-1] = "T2 ", tabaux1[y-1][x] = "T2 ", tabaux1[y-1][x+1] = "T2 ", tabaux1[y+1][x-1] = "T2 ", tabaux1[y+1][x] = "T2 ", tabaux1[y+1][x+1] = "T2 ";
		}
		if(z==1)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x > 13 || y > 13 || y==0 || x < 2 || tabaux1[y][x] != "   " || tabaux1[y-1][x-1] != "   " || tabaux1[y][x-1] != "   " || tabaux1[y+1][x-1] != "   " || tabaux1[y-1][x+1] != "   " || tabaux1[y][x+1] != "   "  || tabaux1[y+1][x+1] != "   ");
				
			tabaux1[y][x] = "T2 ", tabaux1[y-1][x-1] = "T2 ", tabaux1[y][x-1] = "T2 ", tabaux1[y+1][x-1] = "T2 ", tabaux1[y-1][x+1] = "T2 ", tabaux1[y][x+1] = "T2 ", tabaux1[y+1][x+1] = "T2 ";
		}
	 	if(z==2)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x > 13 || y > 14 || y==0  || tabaux1[y][x] != "   " || tabaux1[y-1][x+1] != "   " || tabaux1[y][x+1] != "   " || tabaux1[y+1][x+1] != "   " || tabaux1[y-1][x+2] != "   " || tabaux1[y][x+2] != "   "  || tabaux1[y+1][x+2] != "   ");

			tabaux1[y][x] = "T2 ", tabaux1[y-1][x+1] = "T2 ", tabaux1[y][x+1] = "T2 ", tabaux1[y+1][x+1] = "T2 ", tabaux1[y-1][x+2] = "T2 ", tabaux1[y][x+2] = "T2 ", tabaux1[y+1][x+2] = "T2 ";

		}
		if(z==3)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x == 0 || y > 13 || x == 15  || tabaux1[y][x] != "   " || tabaux1[y+1][x-1] != "   " || tabaux1[y+1][x] != "   " || tabaux1[y+1][x+1] != "   " || tabaux1[y+2][x-1] != "   " || tabaux1[y+2][x] != "   "  || tabaux1[y+2][x+1] != "   ");

			tabaux1[y][x] = "T2 ", tabaux1[y+1][x-1] = "T2 ", tabaux1[y+1][x] = "T2 ", tabaux1[y+1][x+1] = "T2 ", tabaux1[y+2][x-1] = "T2 ", tabaux1[y+2][x] = "T2 ", tabaux1[y+2][x+1] = "T2 ";
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
		} while(x > 12 || y == 15 || tabaux1[y][x] != "   " || tabaux1[y][x+1] != "   " || tabaux1[y][x+2] != "   " || tabaux1[y][x+3] != "   " || tabaux1[y+1][x] != "   " || tabaux1[y+1][x+1] != "   " || tabaux1[y+1][x+2] != "   " || tabaux1[y+1][x+3] != "   ");

		tabaux1[y][x] = "H2 ", tabaux1[y][x+1] = "H2 ", tabaux1[y][x+2] = "H2 ", tabaux1[y][x+3] = "H2 ";
		tabaux1[y+1][x] = "H2 ", tabaux1[y+1][x+1] = "H2 ", tabaux1[y+1][x+2] = "H2 ", tabaux1[y+1][x+3] = "H2 ";

		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(y > 12 || x == 15 || tabaux1[y][x] != "   " || tabaux1[y+1][x] != "   " || tabaux1[y+2][x] != "   " || tabaux1[y+3][x] != "   " || tabaux1[y][x+1] != "   " || tabaux1[y+1][x+1] != "   " || tabaux1[y+2][x+1] != "   " || tabaux1[y+3][x+1] != "   ");

		tabaux1[y][x] = "H2 ", tabaux1[y+1][x] = "H2 ", tabaux1[y+2][x] = "H2 ", tabaux1[y+3][x] = "H2 ", tabaux1[y][x+1] = "H2 ", tabaux1[y+1][x+1] = "H2 ", tabaux1[y+2][x+1] = "H2 ", tabaux1[y+3][x+1] = "H2 ";
		

	}  
	// fazendo com que as casas sem nenhuma embarcação sejam agua

	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			if(tabaux1[i][j]=="   ")
				tabaux1[i][j] = " * ";
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
	z = rand() % 2;
	if(z==0)
	{
		int x=0, y=0;
		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(x < 4 || y < 1 || y==15 || y==0);
		if(tabaux2[y][x]=="   "){
			tabaux2[y][x] = "P1 ";
			tabaux2[y-1][x-1] = "P1 ", tabaux2[y][x-1] = "P1 ", tabaux2[y+1][x-1] = "P1 "; 
			tabaux2[y-1][x-2] = "P1 ", tabaux2[y][x-2] = "P1 ", tabaux2[y+1][x-2] = "P1 "; 
			tabaux2[y-1][x-3] = "P1 ", tabaux2[y][x-3] = "P1 ", tabaux2[y+1][x-3] = "P1 "; 
			tabaux2[y][x-4] = "P1 ";
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
		if(tabaux2[y][x]=="   "){
			tabaux2[y][x] = "P1 ";
			tabaux2[y-1][x] = "P1 ", tabaux2[y-1][x-1] = "P1 ", tabaux2[y-1][x+1] = "P1 "; 
			tabaux2[y-2][x] = "P1 ", tabaux2[y-2][x-1] = "P1 ", tabaux2[y-2][x+1] = "P1 "; 
			tabaux2[y-3][x] = "P1 ", tabaux2[y-3][x-1] = "P1 ", tabaux2[y-3][x+1] = "P1 "; 
			tabaux2[y-4][x] = "P1 ";
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
			} while(x > 12 || y > 12 || tabaux2[y][x]!="   " || tabaux2[y+1][x]!="   " || tabaux2[y+2][x]!="   " || tabaux2[y+3][x]!="   " || tabaux2[y+1][x+1]!="   " || tabaux2[y+1][x+2]!="   " || tabaux2[y][x+3]!="   " || tabaux2[y+1][x+3]!="   " ||  tabaux2[y+2][x+3]!="   " ||tabaux2[y+3][x+3]!="   ");

			tabaux2[y][x] = "C1 ";
			tabaux2[y+1][x] = "C1 ", tabaux2[y+2][x] = "C1 ", tabaux2[y+3][x] = "C1 ", tabaux2[y+1][x+1] = "C1 ";
			tabaux2[y+1][x+2] = "C1 ", tabaux2[y][x+3] = "C1 ", tabaux2[y+1][x+3] = "C1 ", tabaux2[y+2][x+3] = "C1 ", tabaux2[y+3][x+3] = "C1 ";

		}
		else if(z==1)
		{
			int x = 0, y = 0;
			do
			{
				x = rand() % 15;
				y = rand() % 15;	
			} while(x > 12 || y < 3 || tabaux2[y][x]!="   " || tabaux2[y][x+1]!="   " || tabaux2[y][x+2]!="   " || tabaux2[y][x+3]!="   " || tabaux2[y-1][x+1]!="   " || tabaux2[y-2][x+1]!="   " || tabaux2[y-3][x]!="   " || tabaux2[y-3][x+1]!="   " || tabaux2[y-3][x+2]!="   " || tabaux2[y-3][x+3]!="   ");
			tabaux2[y][x] = "C1 ";
			tabaux2[y][x+1] = "C1 ", tabaux2[y][x+2] = "C1 ", tabaux2[y][x+3] = "C1 ", tabaux2[y-1][x+1] = "C1 ";
			tabaux2[y-2][x+1] = "C1 ", tabaux2[y-3][x] = "C1 ", tabaux2[y-3][x+1] = "C1 ", tabaux2[y-3][x+2] = "C1 ", tabaux2[y-3][x+3] = "C1 ";
		} 
		else if(z==2)
		{
			int x = 0, y = 0;
			do
			{
				x = rand() % 15;
				y = rand() % 15;	
			} while(x > 13 || y > 13 || y==0 || x < 2 || tabaux2[y][x] != "   " || tabaux2[y+1][x] != "   " || tabaux2[y-1][x-1] != "   " || tabaux2[y][x-1] != "   " || tabaux2[y+1][x-1] != "   " || tabaux2[y+2][x-1] != "   " || tabaux2[y-1][x-2] != "   " || tabaux2[y][x-2] != "   " || tabaux2[y+1][x-2] != "   " || tabaux2[y+2][x-2] != "   ");

			tabaux2[y][x] = "C1 ", tabaux2[y+1][x] = "C1 ", tabaux2[y-1][x-1] = "C1 ", tabaux2[y][x-1] = "C1 ", tabaux2[y+1][x-1] = "C1 ", tabaux2[y+2][x-1] = "C1 ", tabaux2[y-1][x-2] = "C1 ", tabaux2[y][x-2] = "C1 ", tabaux2[y+1][x-2] = "C1 ", tabaux2[y+2][x-2] = "C1 ";
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
			} while(y==15 || y==0 || x==15 || x==0 || tabaux2[y][x] != "   " || tabaux2[y-1][x-1] != "   " || tabaux2[y-1][x] != "   " || tabaux2[y-1][x+1] != "   " || tabaux2[y+1][x-1] != "   " || tabaux2[y+1][x] != "   " ||  tabaux2[y+1][x+1] != "   " );
				
			tabaux2[y][x] = "T1 ", tabaux2[y-1][x-1] = "T1 ", tabaux2[y-1][x] = "T1 ", tabaux2[y-1][x+1] = "T1 ", tabaux2[y+1][x-1] = "T1 ", tabaux2[y+1][x] = "T1 ", tabaux2[y+1][x+1] = "T1 ";
		}
		if(z==1)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x > 13 || y > 13 || y==0 || x < 2 || tabaux2[y][x] != "   " || tabaux2[y-1][x-1] != "   " || tabaux2[y][x-1] != "   " || tabaux2[y+1][x-1] != "   " || tabaux2[y-1][x+1] != "   " || tabaux2[y][x+1] != "   "  || tabaux2[y+1][x+1] != "   ");
				
			tabaux2[y][x] = "T1 ", tabaux2[y-1][x-1] = "T1 ", tabaux2[y][x-1] = "T1 ", tabaux2[y+1][x-1] = "T1 ", tabaux2[y-1][x+1] = "T1 ", tabaux2[y][x+1] = "T1 ", tabaux2[y+1][x+1] = "T1 ";
		}
	 	if(z==2)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x > 13 || y > 14 || y==0  || tabaux2[y][x] != "   " || tabaux2[y-1][x+1] != "   " || tabaux2[y][x+1] != "   " || tabaux2[y+1][x+1] != "   " || tabaux2[y-1][x+2] != "   " || tabaux2[y][x+2] != "   "  || tabaux2[y+1][x+2] != "   ");

			tabaux2[y][x] = "T1 ", tabaux2[y-1][x+1] = "T1 ", tabaux2[y][x+1] = "T1 ", tabaux2[y+1][x+1] = "T1 ", tabaux2[y-1][x+2] = "T1 ", tabaux2[y][x+2] = "T1 ", tabaux2[y+1][x+2] = "T1 ";

		}
		if(z==3)
		{
			do
			{
				x = rand() % 15;
				y = rand() % 15;
			} while(x == 0 || y > 13 || x == 15  || tabaux2[y][x] != "   " || tabaux2[y+1][x-1] != "   " || tabaux2[y+1][x] != "   " || tabaux2[y+1][x+1] != "   " || tabaux2[y+2][x-1] != "   " || tabaux2[y+2][x] != "   "  || tabaux2[y+2][x+1] != "   ");

			tabaux2[y][x] = "T1 ", tabaux2[y+1][x-1] = "T1 ", tabaux2[y+1][x] = "T1 ", tabaux2[y+1][x+1] = "T1 ", tabaux2[y+2][x-1] = "T1 ", tabaux2[y+2][x] = "T1 ", tabaux2[y+2][x+1] = "T1 ";
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
		} while(x > 12 || y == 15 || tabaux2[y][x] != "   " || tabaux2[y][x+1] != "   " || tabaux2[y][x+2] != "   " || tabaux2[y][x+3] != "   " || tabaux2[y+1][x] != "   " || tabaux2[y+1][x+1] != "   " || tabaux2[y+1][x+2] != "   " || tabaux2[y+1][x+3] != "   ");

		tabaux2[y][x] = "H1 ", tabaux2[y][x+1] = "H1 ", tabaux2[y][x+2] = "H1 ", tabaux2[y][x+3] = "H1 ";
		tabaux2[y+1][x] = "H1 ", tabaux2[y+1][x+1] = "H1 ", tabaux2[y+1][x+2] = "H1 ", tabaux2[y+1][x+3] = "H1 ";

		do
		{
			x = rand() % 15;
			y = rand() % 15;
		} while(y > 12 || x == 15 || tabaux2[y][x] != "   " || tabaux2[y+1][x] != "   " || tabaux2[y+2][x] != "   " || tabaux2[y+3][x] != "   " || tabaux2[y][x+1] != "   " || tabaux2[y+1][x+1] != "   " || tabaux2[y+2][x+1] != "   " || tabaux2[y+3][x+1] != "   ");

		tabaux2[y][x] = "H1 ", tabaux2[y+1][x] = "H1 ", tabaux2[y+2][x] = "H1 ", tabaux2[y+3][x] = "H1 ", tabaux2[y][x+1] = "H1 ", tabaux2[y+1][x+1] = "H1 ", tabaux2[y+2][x+1] = "H1 ", tabaux2[y+3][x+1] = "H1 ";
		

	}  
	// fazendo com que as casas sem nenhuma embarcação sejam agua

	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			if(tabaux2[i][j]=="   ")
				tabaux2[i][j] = " * ";
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
    printf("     |       _____/  .===.===.===.   |  BATALHA  NAVAL  |  .===.===.===.===. |____       |\n");
    printf("     | ~ ~ ~|________________________|__________________|_________________________/~ ~ ~ |\n");
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

int acaoP1(char ***tabuleiro1, char ***tabaux1)
{
	char atk[4], vazio[4] = "   ", estrela[4] = " * ", port_av[4] = "P2 ", cour[4] = "C2 ", torp[4] = "T2 ", hidro[4] = "H2 ";
	char letra;
	int numero, coord, len;
	//qdouble pontos, erro;
	//printf("%.3lf\n", pontos1);

	printf("\nJogador 1, realize sua ação!\n");
	scanf("%s %i%c", &atk, &numero, &letra);

	if(strcmp(atk, "pow\0") == 0)
	{
		int number = numero - 1;
		len = strlen(alphabet);

		for(int i = 0; i < len; i++)
		{
			if(alphabet[i] == letra) {

				coord = i;
				break;
			}
		}

		if(strcmp(tabaux1[number][coord], vazio) != 0) {
			tabuleiro1[number][coord] = tabaux1[number][coord];

			if(strcmp(tabuleiro1[number][coord], port_av) == 0)
			{
				pontos1 += 42.968;
			}
			else if(strcmp(tabuleiro1[number][coord], cour) == 0)
			{
				
				pontos1 += 78.125;
			}
			else if(strcmp(tabuleiro1[number][coord], torp) == 0)
			{
				
				pontos1 += 82.031;
			}
			else if(strcmp(tabuleiro1[number][coord], hidro) == 0)
			{
				pontos1 += 125.000;
			}
			
			

		}
		else {
			strcpy(tabuleiro1[number][coord], estrela);
			if(pontos1 - 3.75 <= 0.0)
			{
				pontos1 = 0.0;
			}
			else
			{
				pontos1 -= 3.75;
			}

		}
	}


	return 0;
}

int acaoP2(char ***tabuleiro2, char ***tabaux2)
{
	char atk[4], vazio[4] = "   ", estrela[4] = " * ", port_av[4] = "P1 ", cour[4] = "C1 ", torp[4] = "T1 ", hidro[4] = "H1 ";
	char letra;
	int numero, coord, len;
	//int ba, qa, N = 256, pt = 64;
	//double pontos, erro;

	printf("\n Jogador 2, realize sua ação!\n");
	scanf("%s %i%c", &atk, &numero, &letra);

	if(strcmp(atk, "pow\0") == 0)
	{
		int number = numero - 1;
		len = strlen(alphabet);

		for(int i = 0; i < len; i++)
		{
			if(alphabet[i] == letra) {

				coord = i;
				break;
			}
		}

		if(strcmp(tabaux2[number][coord], vazio) != 0) {
			tabuleiro2[number][coord] = tabaux2[number][coord];

			if(strcmp(tabaux2[number][coord], port_av) == 0)
			{
				pontos2 += 42.968;
			}
			else if(strcmp(tabaux2[number][coord], cour) == 0)
			{
				pontos2 += 78.125;
			}
			else if(strcmp(tabaux2[number][coord], torp) == 0)
			{

				pontos2 += 82.031;
			}
			else if(strcmp(tabaux2[number][coord], hidro) == 0)
			{

				pontos2 += 125.000;
			}

		}
		else {
			strcpy(tabuleiro2[number][coord], estrela);
			
			if(pontos2 - 3.75 <= 0.0)
			{
				pontos2 = 0.0;
			}
			else 
			{
				pontos2 -= 3.75;
			}
		}

	}

	return 0;
}
