#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main (){
	int i, j, k, n, m, difficulty, tmp, sayac, oyuncuTahmin, botTahmin, satir1 ,sutun1, satir2, sutun2, ii, jj;
	int tekrar = 1;
	int exitcounter = 0;
	int difficultyCtrl = 0;
	int memoCounter = 0;
	srand(time(0));
	
	
	/************************ CREATING MATRIX************************/
	while (tekrar == 1)
	{
		oyuncuTahmin = 0;
		botTahmin = 0;
		system("cls");
		int memoCounter = 0;
		int exit = 0;
		int playerScore = 0;
		int CPUscore = 0;
		while (difficultyCtrl == 0 ){
			difficultyCtrl = 0;
			printf("\n\n\n\n\n\n\t\t\t\t\tWELCOME TO CARD MATCHING MEMORY GAME\n\n");
			sleep(1);
			printf("\t\t\t\t\t PRESS 0 to learn how to play.,");
			sleep(1);
			printf("\n\t\t\t\t\t PRESS 1 to play EASY mode,");
			sleep(1);
			printf("\n\t\t\t\t\t PRESS 2 to play NORMAL mode,");
			sleep(1);
			printf("\n\t\t\t\t\t PRESS 3 to play EXTREME mode:");
			sleep(1);
			printf("\n\t\t\t\t\t choose a difficulty:");
			scanf("%d",&difficulty);
			if(difficulty == 1){
				n = 4;
				m = 2;
				difficultyCtrl = 1 ;
			}
			else if (difficulty == 2){
				n = 6;
				m = 6;
				difficultyCtrl = 1;
			}
			else if (difficulty == 3){
				n = 8;
				m = 16;
				difficultyCtrl = 1;
			}
			else if (difficulty == 0){
				system("cls");
				printf("On the game board, there are always two identical numbers");
				sleep(2);
				printf("\n Start the game by choosing a location on matrix. Then try to find another number that has the same number:");
				sleep(2);
				printf("\n When you match a pair, you take another turn, and continue choosing location until you miss. ");
				sleep(2);
				printf("\nThe objective is to collect the most pairs of numbers.");
				sleep(2);
				printf("\n Difficulties");
				sleep(1);
				printf("\n Easy Mod => 4x4 16 Cards");
				sleep(1);
				printf("\n Normal Mod => 6x6 36 Cards");
				sleep(1);
				printf("\n Extreme Mod => 8x8 64 Cards.");
				sleep(2);
				printf("\nYou will play against MemoBot.(A primitive artificial intelligence)\n");
				sleep(2);
				printf("\t\t\t\t\t\t GOOD LUCK!!!\n");
				sleep(3);
				system("cls");
			}
			else
				printf ("YOU ENTERED INCORRECT VALUE!!!");
		}
		difficultyCtrl = 0;
		int matrix[n][n];
		sayac = 0;
		for(i = 0 ; i < n ; i++){
			for(j = 0 ; j < n ; j++){
				if(sayac != n * n / 2){
					matrix[i][j] = sayac;
					sayac++;
				}
				else{
					matrix[i][j] = 0;
					sayac = 1;
				}
			}
		}
		int shuffleOperatory1, shuffleOperatory2, shuffleOperatorx1, shuffleOperatorx2;
		for(i = 0; i < 100 ; i++)
		{
			shuffleOperatorx1=rand()%n;
			shuffleOperatorx2=rand()%n;
			shuffleOperatory1=rand()%n;
			shuffleOperatory2=rand()%n;
			tmp = matrix[shuffleOperatorx1][shuffleOperatory1];
			matrix[shuffleOperatorx1][shuffleOperatory1] = matrix[shuffleOperatorx2][shuffleOperatory2];
			matrix[shuffleOperatorx2][shuffleOperatory2] = tmp;
		}
		tekrar = 0;
/******************I AM CREATING MEMORY ARRAY FOR MEMOBOT************************/
		int memo[3][m];
		for(i = 0 ; i < 3 ; i++){
			for (j = 0 ; j < m ; j++){
				memo[i][j] = -1;
			}
		}
		sleep(2);
		
		
/*********************************PROGRAM ALGORITHM***************************/
		
/*********************************PLAYERS ALGORITHM************************************/ 
		while (exit == 0){
			system("cls");
			int ctrlTurn = 0;
/**********************************PLAYERS TURN*****************************/
			while (ctrlTurn == 0){
				int cardCtrl = 0;
				while (cardCtrl == 0){
					printf("\n CURRENT TABLE:\n\n");
					for(i = 0 ; i < n ; i++){
						for(j = 0 ; j < n ; j++){
							if(matrix[i][j] < (n*n)/2)
								printf("*\t");
							else
								printf("-\t");
					}
					printf("\n\n");
				}	
					printf("First card row:");
					scanf("%d",&satir1);
					satir1--;
					printf("\nFirst card column:");
					scanf("%d" ,&sutun1);
					sutun1--;
					if(satir1 > (n-1)|| sutun1 > (n-1) || matrix[satir1][sutun1]=='-'){
						printf("You entered incorrect value.\nIn this difficulty %d row %d column and %d cards are avaible on the table. The cards which are paired cannot selected. Please check your inputs, and try again .\n",n ,n ,(n*n));
						printf("\n CURRENT TABLE:\n\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if(matrix[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
							}
							printf("\n\n");
						}
					}
				else
					cardCtrl = 1;
				}
				while (cardCtrl == 1){
					printf("\n\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if (i == satir1 && j == sutun1){
									printf("%d\t", matrix[satir1][sutun1]);
									ii = i;
									jj = j;
								}
								else if(matrix[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
					}
					printf("\n\n");
				}	
					printf("First card you choose is:%d",matrix[satir1][sutun1]);
					printf("\nSecond card row:");
					scanf("%d",&satir2);
					satir2--;
					printf("\nSecond card column:");
					scanf("%d",&sutun2);
					sutun2--;
					printf("\n\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if(ii == i && jj == j)
								printf("%d\t",matrix[satir1][sutun1]);
								else if (i == satir2 && j == sutun2)
									printf("%d\t", matrix[satir2][sutun2]);
								else if(matrix[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
					}
					printf("\n\n");
				}
					
					if(satir2 > (n-1) || sutun2 > (n-1) || matrix[satir2][sutun2] == '-'){
						printf("You entered incorrect value.\nIn this difficulty %d row %d column and %d cards are avaible on the table. The cards which are paired cannot selected. Please check your inputs, and try again .\n",n ,n ,(n*n));
						printf("CURRENT TABLE:\n");
							for(i = 0 ; i < n ; i++){
								for(j = 0 ; j < n ; j++){
									if(matrix[i][j] < (n*n)/2)
										printf("*\t");
									else
										printf("-\t");
								}
								printf("\n\n");
							}
					}
					else 
						cardCtrl = 0;
				}
				if((satir1 == satir2 && sutun1 == sutun2) || satir1 > n || satir2 > n || sutun1 > n || sutun2 > n || matrix[satir2][sutun2] == '-'){
					printf("You entered incorrect value.\nIn this difficulty %d row %d column and %d cards are avaible on the table. The cards which are paired cannot selected. Please check your inputs, and try again .\n",n ,n ,(n*n));printf("You entered incorrect value.\nIn this difficulty %d row %d column and %d cards are avaible on the table. The cards which are paired cannot selected. Please check your inputs, and try again .\n",n ,n ,(n*n));
				}
				else if(matrix[satir1][sutun1] == matrix[satir2][sutun2] && exit != 1){
					printf("\nYour choice is:");
					printf("%d, %d \n",matrix[satir1][sutun1], matrix[satir2][sutun2]);
					sleep(2);
					oyuncuTahmin++;
					playerScore++;
					matrix[satir1][sutun1]= '-', matrix[satir2][sutun2] = '-';
					exitcounter = 0;
					for(i = 0 ; i <= (n-1) ; i++){
							for(j = 0 ; j <= (n-1) ; j++){
								if(matrix[i][j] == '-')
									exitcounter++;
							}
					}
				if (exitcounter == 16){
					exit = 1;
					ctrlTurn = 2;
				}
				if(exit != 1){
				printf("Congratulations, you made a pair\n");
				sleep(2);
				
				printf("CURRENT TABLE:\n");
					for(i = 0 ; i < n ; i++){
						for(j = 0 ; j < n ; j++){
							if(matrix[i][j] < (n*n)/2)
								printf("*\t");
							else
								printf("-\t");
						}
							printf("\n\n");
					}
				}
				}
				else {
					ctrlTurn=1;
					printf("\nYour choice is:");
					printf("%d, %d \n",matrix[satir1][sutun1], matrix[satir2][sutun2]);
					sleep(2);
					printf("Your cards doesnt match, Memobots turn:\n\n");
					oyuncuTahmin++;
				}
				if(memoCounter < m){
					memo[0][memoCounter] = satir1;
					memo[1][memoCounter] = sutun1;
					memo[2][memoCounter] = matrix[satir1][sutun1];
					memoCounter++;
					memo[0][memoCounter] = satir2;
					memo[1][memoCounter] = sutun2;
					memo[2][memoCounter] = matrix[satir2][sutun2];
					memoCounter++;
				} 
				else{
					memoCounter = 0;
					memo[0][memoCounter] = satir1;
					memo[1][memoCounter] = sutun1;
					memo[2][memoCounter] = matrix[satir1][sutun1];
					memoCounter++;
					memo[0][memoCounter] = satir2;
					memo[1][memoCounter] = sutun2;
					memo[2][memoCounter] = matrix[satir2][sutun2];
					memoCounter++;
					
				}
				
				exitcounter = 0;
					for(i = 0 ; i <= (n-1) ; i++){
						for(j = 0 ; j <= (n-1) ; j++)
						{
							if(matrix[i][j] == '-')
								exitcounter++;
						}
					}
				system("cls");
				if (exitcounter == (n*n)){
					exit = 1;
					ctrlTurn = 2;
					printf("Congratulations, you made a pair\n");
				}
			}
/*******************************************MEMOBOT TURN******************************/
				for(i = 0 ; i < 3 ; i++){
					for (j = 0 ; j < m ; j++){
						printf("%d\t",memo[i][j]);
					}
					printf("\n");
				}
			while(ctrlTurn == 1){
				int remember = 0;
				int a, b;
				for(i = 0 ; i < m ; i++){
					for(j = 0 ; j < i ; j++){
						a = memo[2][i];
						b = memo[2][j];
						if(a == b && a != -1 && i != j && remember != 2){
							remember = 2; 
							satir1 = memo[0][i];
							sutun2 = memo[1][i];
							satir2 = memo[0][j];
							sutun2 = memo[1][j];
							memo[2][i] = -1;
							memo[2][j] = -1;
						}
					}
				}
				if(remember != 2){
					satir1 = rand()%n;
					sutun1 = rand()%n;
					for(j = 0 ; j < m ; j++){
						if (matrix[satir1][sutun1] == memo[2][j]){
							remember = 1;
							satir2 = memo[0][j];
							sutun2 = memo[1][j];
					}
				}
				if (remember == 0){
					satir2 = rand()%n;
					sutun2 = rand()%n;
				}
				}
				if((satir1 == satir2 && sutun1 == sutun2) || satir1 > n || satir2 > n || sutun1 > n || sutun2 > n || matrix[satir1][sutun1] == '-'|| matrix[satir2][sutun2] == '-')
					ctrlTurn = 1;
				
				else if(matrix[satir1][sutun1]==matrix[satir2][sutun2]){
					printf("\nThe first row that Memobot choose:%d",satir1+1);
					printf("\nThe first column that Memobot choose:%d",sutun1+1);
					printf("\nThe first card that Memobot flips is: %d",matrix[satir1][sutun1]);
					printf("\n\n");
					botTahmin++;
						printf("\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if (i == satir1 && j == sutun1){
									printf("%d\t", matrix[satir1][sutun1]);
									ii = i;
									jj = j;
								}
								else if(matrix[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
							}
							printf("\n\n\n");
						}
					sleep(1);
					printf("\nThe second row that Memobot choose:%d",satir2+1);
					printf("\nThe second column that Memobot choose:%d",sutun2+1);
					printf("\nThe second card that Memobot flipped is: %d",matrix[satir2][sutun2]);
					sleep(1);
					printf("\n\n\n");
							for(i = 0 ; i < n ; i++){
								for(j = 0 ; j < n ; j++){
									if(ii == i && jj == j)
										printf("%d\t",matrix[satir1][sutun1]);
									else if (i == satir2 && j == sutun2)
										printf("%d\t", matrix[satir2][sutun2]);
									else if(matrix[i][j] < (n*n)/2)
										printf("*\t");
									else
										printf("-\t");
								}
					printf("\n\n\n");
							}
					printf("\nThe cards that Memobot flipped are:");
					printf("%d, %d \n",matrix[satir1][sutun1], matrix[satir2][sutun2]);
					sleep(2);
					CPUscore++;
					matrix[satir1][sutun1]='-', matrix[satir2][sutun2] = '-';
					exitcounter = 0;
						for(i = 0 ; i <= (n-1) ; i++){
							for(j = 0 ; j <= (n-1) ; j++)
							{
								if(matrix[i][j] == '-')
									exitcounter++;
							}
						}
					if (exitcounter == (n*n)){
						exit = 1;
						ctrlTurn = 2;
						printf("\nMemoBot paired cards,\nGAME OVER...\n\n");
					}
					if(exit!=1){
						printf("\nMemoBot paired cards,\nMemobot has another turn\n");
						sleep(2);
						system("cls");
					}
				}
				else 
				{
					printf("\nThe first row that Memobot choose:%d",satir1+1);
					printf("\nThe first column that Memobot choose:%d",sutun1+1);
					printf("\nThe first card that Memobot flips is %d",matrix[satir1][sutun1]);
						printf("\n\n\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if (i == satir1 && j == sutun1){
									printf("%d\t", matrix[satir1][sutun1]);
									ii = i;
									jj = j;
								}
								else if(matrix[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
							}
							printf("\n\n");
						}
					sleep(1);
					printf("\nThe second row that Memobot choose:%d",satir2+1);
					printf("\nThe second column that Memobot choose:%d",sutun2+1);
					printf("\nThe second card that Memobot flipped is %d",matrix[satir2][sutun2]);
					sleep(1);
					printf("\n\n\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if(ii == i && jj == j)
									printf("%d\t",matrix[satir1][sutun1]);
								else if (i == satir2 && j == sutun2)
									printf("%d\t", matrix[satir2][sutun2]);
								else if(matrix[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
							}
							printf("\n\n");
						}
					if(memoCounter < m){
						memo[0][memoCounter] = satir1;
						memo[1][memoCounter] = sutun1;
						memo[2][memoCounter] = matrix[satir1][sutun1];
						memoCounter++;
						memo[0][memoCounter] = satir2;
						memo[1][memoCounter] = sutun2;
						memo[2][memoCounter] = matrix[satir2][sutun2];
						memoCounter++;
					} 
					else{
						memoCounter = 0;
						memo[0][memoCounter] = satir1;
						memo[1][memoCounter] = sutun1;
						memo[2][memoCounter] = matrix[satir1][sutun1];
						memoCounter++;
						memo[0][memoCounter] = satir2;
						memo[1][memoCounter] = sutun2;
						memo[2][memoCounter] = matrix[satir2][sutun2];
						memoCounter++;
						
					}
					ctrlTurn=0;
					botTahmin++;
					printf("\nThe cards that Memobot flipped are:");
					printf("%d, %d ",matrix[satir1][sutun1], matrix[satir2][sutun2]);
					sleep(1);
					printf("\nMemoBot failed cards,\nYour turn:\n");
					sleep(2);
					system("cls");
				}
			}
			exitcounter = 0;
				for(i = 0 ; i <= (n-1) ; i++){
					for(j = 0 ; j <= (n-1) ; j++)
					{
						if(matrix[i][j] == '-')
							exitcounter++;
					}
				}
			if (exitcounter == n*n){
				exit = 1;
			}
		}
		if(playerScore > CPUscore)
			printf("CONGRACULATIONS, YOU WON IN %d TRIES!!!\nYOUR SCORE:%d\nMEMOBOTS SCORE:%d\n",oyuncuTahmin, playerScore, CPUscore);
		else if(CPUscore > playerScore)
			printf("MEMOBOT WON IN %d TRIES, TRY AGAIN!!!.\n\n YOUR SCORE:%d\n MEMOBOTS SCORE:%d\n\n",botTahmin, playerScore, CPUscore);
		else
			printf("ENDED UP IN A DRAW. TRY AGAIN!!!.\n\n YOUR SCORE:%d\n MEMOBOTS SCORE:%d\n\n",playerScore, CPUscore);
		tekrar--;
			
		printf("PRESS 1: PLAY AGAIN:");
		scanf("%d",&tekrar);
	}
		return 0;
}
