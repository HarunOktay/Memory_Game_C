#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main (){
	setlocale(LC_ALL,"Turkish");
	int i, j, k, n, m, difficulty, tmp, sayac, oyuncuTahmin, botTahmin, satir1 ,sutun1, satir2, sutun2, ii, jj;
	int tekrar = 1;
	int exitcounter = 0;
	int difficultyCtrl = 0;
	int memoCounter = 0;
	srand(time(0));
	
	
	/************************ MATRIS ÜRETÝYORUM************************/
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
			printf("\n\n\n\n\n\n\t\t\t\t\tKART EÞLEÞTÝRME OYUNUNA HOÞGELDÝNÝZ\n\n");
			sleep(1);
			printf("\t\t\t\t\t Nasýl oynanýyor öðrenmek için 0,");
			sleep(1);
			printf("\n\t\t\t\t\t Kolay için 1,");
			sleep(1);
			printf("\n\t\t\t\t\t Orta için 2,");
			sleep(1);
			printf("\n\t\t\t\t\t Zor icin 3 seçiniz:");
			sleep(1);
			printf("\n\t\t\t\t\t Zorluk seçiniz:");
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
				printf("Kart açma oyununda her karttan iki tane olmak üzere belirli sayýda kart setleri karýþýk bir þekilde daðýtýlýr.");
				sleep(2);
				printf("\nAmacýnýz rastgele ya da sýralý bir þekilde kartlar açarak");
				sleep(2);
				printf("\naçtýðýnýz kartlarý hafýzanýzda tutmak ve eþ kartlarý seçerek puan kazanmaktýr.");
				sleep(2);
				printf("\n Oyun modlarýnda");
				sleep(1);
				printf("\n Kolay modda 4x4 16 kart");
				sleep(1);
				printf("\n Orta modda 6x6 36 kart");
				sleep(1);
				printf("\n Zor modda 8x8 64 kart bulunmaktadýr.");
				sleep(2);
				printf("\nÞu an bu oyunda MemoBot'a karþý, yani bilgisayarýn yapay zekasýna karþý oynayacaksýnýz.\n");
				sleep(2);
				printf("\t\t\t\t\t\t BOL ÞANS!!!\n");
				sleep(2);
				system("cls");
			}
			else
				printf ("HATALI ZORLUK DERECESÝ GÝRDÝNÝZ!!!");
		}
		difficultyCtrl = 0;
		int matris[n][n];
		sayac = 0;
		for(i = 0 ; i < n ; i++){
			for(j = 0 ; j < n ; j++){
				if(sayac != n * n / 2){
					matris[i][j] = sayac;
					sayac++;
				}
				else{
					matris[i][j] = 0;
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
			tmp = matris[shuffleOperatorx1][shuffleOperatory1];
			matris[shuffleOperatorx1][shuffleOperatory1] = matris[shuffleOperatorx2][shuffleOperatory2];
			matris[shuffleOperatorx2][shuffleOperatory2] = tmp;
		}
		tekrar = 0;
		/******************HAFIZA DÝZÝSÝ ÜRETÝYORUM************************/
		int memo[3][m];
		for(i = 0 ; i < 3 ; i++){
			for (j = 0 ; j < m ; j++){
				memo[i][j] = -1;
			}
		}
		sleep(2);
		
		
		/********************************** PROGRAM KOD BLOGU***************************/
		
/**********************************OYUNCU KISMI************************************/ 
		while (exit == 0){
			system("cls");
			int ctrlcevap = 0;
			/*********************************OYUNCU BLOÐU*****************************/
			while (ctrlcevap == 0){
				int cardCtrl = 0;
				while (cardCtrl == 0){
					printf("\n mevcut tablo:\n\n");
					for(i = 0 ; i < n ; i++){
						for(j = 0 ; j < n ; j++){
							if(matris[i][j] < (n*n)/2)
								printf("*\t");
							else
								printf("-\t");
					}
					printf("\n\n");
				}	
					printf("açmak istediðiniz ilk kartýn satýrý:");
					scanf("%d",&satir1);
					satir1--;
					printf("\naçmak istediðiniz ilk kartýn sütunu:");
					scanf("%d" ,&sutun1);
					sutun1--;
					if(satir1 > (n-1)|| sutun1 > (n-1) || matris[satir1][sutun1]=='-'){
						printf("Hatalý sayý girdiniz.\nÞu an oynadýðýnýz modda %d satýr %d sütun olmak üzere %d tane kart vardýr doðru bilinen kartlar tekrardan girilemez, girdilerinizi kontrol edip tekrardan deneyiniz.\n",n ,n ,(n*n));
						printf("\n mevcut tablo:\n\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if(matris[i][j] < (n*n)/2)
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
									printf("%d\t", matris[satir1][sutun1]);
									ii = i;
									jj = j;
								}
								else if(matris[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
					}
					printf("\n\n");
				}	
					printf("seçtiginiz ilk kart:%d",matris[satir1][sutun1]);
					printf("\naçmak istediðiniz ikinci kartýn satýrý:");
					scanf("%d",&satir2);
					satir2--;
					printf("\naçmak istediðiniz ikinci kartýn sütunu:");
					scanf("%d",&sutun2);
					sutun2--;
					printf("\n\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if(ii == i && jj == j)
								printf("%d\t",matris[satir1][sutun1]);
								else if (i == satir2 && j == sutun2)
									printf("%d\t", matris[satir2][sutun2]);
								else if(matris[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
					}
					printf("\n\n");
				}
					
					if(satir2 > (n-1) || sutun2 > (n-1) || matris[satir2][sutun2] == '-'){
					printf("Hatalý sayý girdiniz,\nÞu an oynadýðýnýz modda %d satýr %d sütun olmak üzere %d kart vardýr. Doðru bilinen kartlar tekrardan girilemez, girdilerinizi kontrol edip tekrardan deneyiniz.\n",n ,n ,(n*n));
					printf("mevcut tablo:\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if(matris[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
							}
							printf("\n\n");
						}}
					else 
						cardCtrl = 0;
				}
				if((satir1 == satir2 && sutun1 == sutun2) || satir1 > n || satir2 > n || sutun1 > n || sutun2 > n || matris[satir2][sutun2] == '-'){
					printf("Hatalý sayý girdiniz.\nÞu an oynadýðýnýz modda %d satýr %d sütun olmak üzere %d kart vardýr doðru bilinen kartlar tekrardan girilemez, girdilerinizi kontrol edip tekrardan deneyiniz.\n",n ,n ,(n*n));
				}
				else if(matris[satir1][sutun1] == matris[satir2][sutun2] && exit != 1){
					printf("\nAçtýðýnýz kartlar sýrasýyla:");
					printf("%d, %d \n",matris[satir1][sutun1], matris[satir2][sutun2]);
					sleep(2);
					oyuncuTahmin++;
					playerScore++;
					matris[satir1][sutun1]= '-', matris[satir2][sutun2] = '-';
					exitcounter = 0;
					for(i = 0 ; i <= (n-1) ; i++){
							for(j = 0 ; j <= (n-1) ; j++){
								if(matris[i][j] == '-')
									exitcounter++;
							}
					}
				if (exitcounter == 16){
					exit = 1;
					ctrlcevap = 2;
				}
				if(exit != 1){
				printf("Eþleþtirmeniz doðru tekrar kart seçiniz\n");
				sleep(2);
				
				printf("Mevcut tablo:\n");
					for(i = 0 ; i < n ; i++){
						for(j = 0 ; j < n ; j++){
							if(matris[i][j] < (n*n)/2)
								printf("*\t");
							else
								printf("-\t");
						}
							printf("\n\n");
					}
				}
				}
				else {
					ctrlcevap=1;
					printf("\nAçtýðýnýz kartlar sýrasýyla\n");
					printf("%d, %d \n",matris[satir1][sutun1], matris[satir2][sutun2]);
					sleep(2);
					printf("Açtýðýnýz kartlar eþleþmiyor sýra MemoBotta\n\n");
					oyuncuTahmin++;
				}
				if(memoCounter < m){
					memo[0][memoCounter] = satir1;
					memo[1][memoCounter] = sutun1;
					memo[2][memoCounter] = matris[satir1][sutun1];
					memoCounter++;
					memo[0][memoCounter] = satir2;
					memo[1][memoCounter] = sutun2;
					memo[2][memoCounter] = matris[satir2][sutun2];
					memoCounter++;
				} 
				else{
					memoCounter = 0;
					memo[0][memoCounter] = satir1;
					memo[1][memoCounter] = sutun1;
					memo[2][memoCounter] = matris[satir1][sutun1];
					memoCounter++;
					memo[0][memoCounter] = satir2;
					memo[1][memoCounter] = sutun2;
					memo[2][memoCounter] = matris[satir2][sutun2];
					memoCounter++;
					
				}
				
				exitcounter = 0;
					for(i = 0 ; i <= (n-1) ; i++){
						for(j = 0 ; j <= (n-1) ; j++)
						{
							if(matris[i][j] == '-')
								exitcounter++;
						}
					}
				system("cls");
				if (exitcounter == (n*n)){
					exit = 1;
					ctrlcevap = 2;
					printf("\nEþlestirmeniz doðru, Oyun bitti\n\n");
				}
			}
			/*******************************************BOT KISMI******************************/
				for(i = 0 ; i < 3 ; i++){
					for (j = 0 ; j < m ; j++){
						printf("%d\t",memo[i][j]);
					}
					printf("\n");
				}
			while(ctrlcevap == 1){
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
						if (matris[satir1][sutun1] == memo[2][j]){
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
				if((satir1 == satir2 && sutun1 == sutun2) || satir1 > n || satir2 > n || sutun1 > n || sutun2 > n || matris[satir1][sutun1] == '-'|| matris[satir2][sutun2] == '-')
					ctrlcevap = 1;
				
				else if(matris[satir1][sutun1]==matris[satir2][sutun2]){
					printf("\nMemoBotun açtýgý ilk kartýn satýrý:%d",satir1+1);
					printf("\nMemoBotun açtýgý ilk kartýn sütunu:%d",sutun1+1);
					printf("\nMemoBotun açtýgý ilk kart %d",matris[satir1][sutun1]);
					printf("\n\n");
					botTahmin++;
						printf("\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if (i == satir1 && j == sutun1){
									printf("%d\t", matris[satir1][sutun1]);
									ii = i;
									jj = j;
								}
								else if(matris[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
							}
							printf("\n\n\n");
						}
					sleep(1);
					printf("\nMemoBotun açtýgý ikinci kartýn satýrý:%d",satir2+1);
					printf("\nMemoBotun açtýgý ikinci kartýn sütunu:%d",sutun2+1);
					printf("\nMemoBotun açtýgý ikinci kart %d",matris[satir2][sutun2]);
					sleep(1);
					printf("\n\n\n");
							for(i = 0 ; i < n ; i++){
								for(j = 0 ; j < n ; j++){
									if(ii == i && jj == j)
										printf("%d\t",matris[satir1][sutun1]);
									else if (i == satir2 && j == sutun2)
										printf("%d\t", matris[satir2][sutun2]);
									else if(matris[i][j] < (n*n)/2)
										printf("*\t");
									else
										printf("-\t");
								}
					printf("\n\n\n");
							}
					printf("\nMemoBotun açtýgý kartlar sýrasýyla:");
					printf("%d, %d \n",matris[satir1][sutun1], matris[satir2][sutun2]);
					sleep(2);
					CPUscore++;
					matris[satir1][sutun1]='-', matris[satir2][sutun2] = '-';
					exitcounter = 0;
						for(i = 0 ; i <= (n-1) ; i++){
							for(j = 0 ; j <= (n-1) ; j++)
							{
								if(matris[i][j] == '-')
									exitcounter++;
							}
						}
					if (exitcounter == (n*n)){
						exit = 1;
						ctrlcevap = 2;
						printf("\nMemoBotun eþleþtirmesi doðru oyun bitti\n\n");
					}
					if(exit!=1){
						printf("\nMemoBotun eþleþtirmesi doðru tekrar kart seçiyor\n");
						sleep(2);
						system("cls");
					}
				}
				else 
				{
					printf("\nMemoBotun actigi ilk kartin satiri:%d",satir1+1);
					printf("\nMemoBotun actigi ilk kartin sutunu:%d",sutun1+1);
					printf("\nMemoBotun actigi ilk kart %d",matris[satir1][sutun1]);
						printf("\n\n\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if (i == satir1 && j == sutun1){
									printf("%d\t", matris[satir1][sutun1]);
									ii = i;
									jj = j;
								}
								else if(matris[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
							}
							printf("\n\n");
						}
					sleep(1);
					printf("\nMemoBotun actigi ikinci kartin satiri:%d",satir2+1);
					printf("\nMemoBotun actigi ikinci kartin sutunu:%d",sutun2+1);
					printf("\nMemoBotun actigi ikinci kart %d",matris[satir2][sutun2]);
					sleep(1);
					printf("\n\n\n");
						for(i = 0 ; i < n ; i++){
							for(j = 0 ; j < n ; j++){
								if(ii == i && jj == j)
									printf("%d\t",matris[satir1][sutun1]);
								else if (i == satir2 && j == sutun2)
									printf("%d\t", matris[satir2][sutun2]);
								else if(matris[i][j] < (n*n)/2)
									printf("*\t");
								else
									printf("-\t");
							}
							printf("\n\n");
						}
					if(memoCounter < m){
						memo[0][memoCounter] = satir1;
						memo[1][memoCounter] = sutun1;
						memo[2][memoCounter] = matris[satir1][sutun1];
						memoCounter++;
						memo[0][memoCounter] = satir2;
						memo[1][memoCounter] = sutun2;
						memo[2][memoCounter] = matris[satir2][sutun2];
						memoCounter++;
					} 
					else{
						memoCounter = 0;
						memo[0][memoCounter] = satir1;
						memo[1][memoCounter] = sutun1;
						memo[2][memoCounter] = matris[satir1][sutun1];
						memoCounter++;
						memo[0][memoCounter] = satir2;
						memo[1][memoCounter] = sutun2;
						memo[2][memoCounter] = matris[satir2][sutun2];
						memoCounter++;
						
					}
					ctrlcevap=0;
					botTahmin++;
					printf("\nBotun açtýðý kartlar sýrasýyla:");
					printf("%d, %d ",matris[satir1][sutun1], matris[satir2][sutun2]);
					sleep(1);
					printf("\nBotun açtýgý kartlar eþleþmiyor sýra sizde\n");
					sleep(2);
					system("cls");
				}
			}
			exitcounter = 0;
				for(i = 0 ; i <= (n-1) ; i++){
					for(j = 0 ; j <= (n-1) ; j++)
					{
						if(matris[i][j] == '-')
							exitcounter++;
					}
				}
			if (exitcounter == n*n){
				exit = 1;
			}
		}
		if(playerScore > CPUscore)
			printf("TEBRÝKLER %d TAHMÝNLE KAZANDINIZ!!!\nSizin Puanýnýz:%d\nMemoBotun Puaný:%d\n",oyuncuTahmin, playerScore, CPUscore);
		else if(CPUscore > playerScore)
			printf("MEMOBOT %d TAHMÝNLE KAZANDI, TEKRAR DENEYÝN.\n\n Sizin Puanýnýz:%d\n MemoBotun Puaný:%d\n\n",botTahmin, playerScore, CPUscore);
		else
			printf("MEMOBOTLA BERABERE KALDINIZ. TEKRAR DENEYÝN.\n\n Sizin Puaniniz:%d\n MemoBotun Puaný:%d\n\n",playerScore, CPUscore);
		tekrar--;
			
		printf("Tekrar oynamak istiyorsanýz 1 giriniz:");
		scanf("%d",&tekrar);
	}
		return 0;
}
