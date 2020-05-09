#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//para compilar: gcc -o main main.c functions.c


int main(int argc, char const *argv[])
{
	int opcao=0, menu=0; //Usado no menu do jogo

	//criacao das matrizes de strings tabuleiro, com uso de alocação dinamica
	char ***tabuleiro1 = malloc(16 * sizeof(char**));

	for(int i = 0; i < 16; i++) 
		tabuleiro1[i] = malloc(16 * sizeof(char*));

	char ***tabuleiro2 = malloc(16 * sizeof(char**));

	for(int i = 0; i < 16; i++) 
		tabuleiro2[i] = malloc(16 * sizeof(char*));

	char ***tabaux1 = malloc(16 * sizeof(char**));

	for(int i = 0; i < 16; i++) 
		tabaux1[i] = malloc(16 * sizeof(char*));

	char ***tabaux2 = malloc(16 * sizeof(char**));

	for(int i = 0; i < 16; i++) 
		tabaux2[i] = malloc(16 * sizeof(char*));
 	//

	

	do{	
			system("clear");
			layout();
		 	scanf("%i", &opcao);
			switch(opcao)
			{
				case 1: 
 					// pre jogo
					zerandoTabuleiro(tabuleiro1, tabuleiro2, tabaux1, tabaux2);
					setArmada1(tabaux1);
					setArmada2(tabaux2);

					for(int i = 0; i < 5; i++)
					{
						acaoP1(tabuleiro1, tabaux1);
						printTabuleiro1(tabuleiro1);
						acaoP2(tabuleiro2, tabaux2);
						printTabuleiro2(tabuleiro2);
					}


					printf("\nDigite 0 e tecle ENTER para retornar ao menu principal.\n");
					scanf("%i", &menu);
					if(menu==0){
						break;
					}
				;

				case 2:
					system("sleep 01");
					comoJogar();
					printf("Digite 0 e tecle ENTER para retornar ao menu principal.\n");
					scanf("%i", &menu);
					if(menu==0){
						break;
					}
					;

				case 3:
					system("sleep 01");
					desenvolvedores();
					printf("Digite 0 e tecle ENTER para retornar ao menu principal.\n");
					scanf("%i", &menu);
					if(menu==0){
						break;
					}

				case 4:
					system("sleep 01");
					comandos();
					printf("Digite 0 e tecle ENTER para retornar ao menu principal.\n");
					scanf("%i", &menu);
					if(menu==0){
						break;
					}
				case 5:
					system("sleep 01");
					printf("Goodbye!\n");
					break;
			}

	} while(opcao!=5 || opcao<=0 || opcao>5);
	
	return 0;
}

