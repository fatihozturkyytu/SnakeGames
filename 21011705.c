#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
  
  time_t t;
  int haritasatir,haritasutun,toplamyemek,i,j,yemsayisi;
  int hamlesayisi=0;
  int yilaninboyu=1;
  printf("oynamak istediginiz yilan oyununun satir boyutunu girin: ");
  scanf("%d",&haritasatir);
  printf("oynamak istediginiz yilan oyununun sutun boyutunu girin: ");
  scanf("%d",&haritasutun);
  printf("yemek sayisini giriniz: ");
  scanf("%d",&toplamyemek); 
    while (toplamyemek>=haritasatir*haritasutun) {
    printf("bu alana bu kadar yemek yerlestirilemez, lutfen tekrar girin: ");
    scanf("%d",&toplamyemek);
    }
  char harita[100][100];
  for (i=0; i<haritasatir; i++) {
    for(j=0; j<haritasutun; j++) {
      harita[i][j]=' ';
    }
  }

  srand((unsigned) time(&t));
  i = rand() %haritasatir;
  j = rand() %haritasutun;
  int yilankoordinatlari[100][2];
  harita[i][j]='1';
  
  int yilansatir=i;
  int yilansutun=j;
  yilankoordinatlari[0][0] = yilansatir;
  yilankoordinatlari[0][1] = yilansutun;
  printf("\nBaslangic Koordinatlari: %d %d\n",yilansatir+1,yilansutun+1);
  for (i=1; i<=haritasutun; i++) {
  	printf("_");
  	if (i==haritasutun )printf("|");
  }
  printf("\n");
  yemsayisi=toplamyemek;
    while (toplamyemek!=0)  {
  i = rand() %haritasatir;
  j = rand() %haritasutun;
  if (harita[i][j] == '0' || harita[i][j] =='1') toplamyemek=toplamyemek+1;
  if (harita[i][j] != '1')   harita[i][j]='0';
  toplamyemek=toplamyemek-1;
  }
  
        for (i=0; i<haritasatir+1; i++) {
      for (j=0; j<haritasutun+1; j++) {
      	if (i==haritasatir) harita[i][j]='^';
      	if (j==haritasutun) harita[i][j]='|';
        printf("%c",harita[i][j]);
      }
      printf("\n");
    } 
  
  
  int k=0;
  char hamle;
  char yem;
  while (k==0) {
    printf("\nLutfen hamlenizi giriniz: ");
    scanf(" %c",&hamle);
    printf("\n\n");
    hamlesayisi=hamlesayisi+1;
    
    if (hamle=='u') {
        yem=harita[yilansatir-1][yilansutun];
        yilansatir=yilansatir-1;
    }
    if (hamle=='d') {
        yem=harita[yilansatir+1][yilansutun];
        yilansatir=yilansatir+1;
    }
    if (hamle=='r') {
        yem=harita[yilansatir][yilansutun+1];
        yilansutun=yilansutun+1;
    }
    if (hamle=='l') {
        yem=harita[yilansatir][yilansutun-1];
        yilansutun=yilansutun-1;
    }
      
      harita[yilankoordinatlari[0][0]][yilankoordinatlari[0][1]]=' ';

      for(i=yilaninboyu; i>=1; i--) {
        for(j=0; j<2; j++) {
        
        yilankoordinatlari[i][j]=yilankoordinatlari[i-1][j];
        }
        harita[yilankoordinatlari[i][0]][yilankoordinatlari[i][1]]=' ';
        
      }
      
      yilankoordinatlari[0][0]=yilansatir;
      yilankoordinatlari[0][1]=yilansutun;
      harita[yilankoordinatlari[0][0]][yilankoordinatlari[0][1]]='1';
      if ( yilansatir+1>haritasatir || yilansutun+1>haritasutun || yilansatir==-1 || yilansutun==-1) {
      	k=1;
      	printf("\nHarita disina ciktiginiz icin kaybettiniz!\n");
      	yilansatir=0;
      	yilansutun=0;
	  }
      j=1;
      for (i=1; i<yilaninboyu; i++) {
      	
      	if (harita[yilankoordinatlari[0][0]][yilankoordinatlari[0][1]] ==harita[yilankoordinatlari[i][j-1]][yilankoordinatlari[i][j]]) {
      		printf ("Kendinize carptiniz icin kaybettiniz.\n"); k=1;
      		
		  }
      	}
      	if (k==0) {
      	 for (i=0; i<yilaninboyu; i++) {
        harita[yilankoordinatlari[i][j-1]][yilankoordinatlari[i][j]] = i+1+'0';
        if(harita[yilankoordinatlari[i][j-1]][yilankoordinatlari[i][j]]>=58) harita[yilankoordinatlari[i][j-1]][yilankoordinatlari[i][j]]='*';
		 //9 dan sonraki buyumeler, kullaniciya gosterim kolayligi olması acisindan * ile gosterilmistir.
        printf("%d(%d,%d)   ",i+1,yilankoordinatlari[i][j-1]+1,yilankoordinatlari[i][j]+1);
        if(i%6 ==5) printf("\n");
   		 }
      }
      printf("\n");
      if (k==0) {
      	  for (i=1; i<=haritasutun; i++) {
  		printf("_");
  		if (i==haritasutun )printf("|");
  		}
  		printf("\n");
    for (i=0; i<haritasatir+1; i++) {
      for (j=0; j<haritasutun+1; j++) {
      	if (i==haritasatir) harita[i][j]='^';
      	if (j==haritasutun) harita[i][j]='|';
        printf("%c",harita[i][j]);
      }
      printf("\n");
    } 
    printf("hamlesayisi:%d",hamlesayisi);
	}
          if (yem==48){
          	yemsayisi=yemsayisi-1;
     yilaninboyu=yilaninboyu+1;
     yilankoordinatlari[yilaninboyu][0]=yilankoordinatlari[yilaninboyu-1][0];
     yilankoordinatlari[yilaninboyu][1]=yilankoordinatlari[yilaninboyu-1][1];
 }
    if (yemsayisi==0) k=1;
  }
  printf("\nSonuc: \n");
  if (yemsayisi==0) printf("%d hamle sonucu hic yem birakmayarak %d puanla oyunu tamamladiniz.",hamlesayisi,yilaninboyu);
  else printf("%d hamle sonucu %d yem birakarak %d puan ile yandiniz.",hamlesayisi-1,yemsayisi,yilaninboyu);
    

  return 0;
  
}