#include <stdio.h>
#include <stdlib.h>
void printTabela(int matriz[3][3],int &r){
		int i,j,player,barra,chao;
	    printf("____________________\n\n");
	for(i=0,chao=0;i<3;i++){
		for(j=0,barra=0;j<3;j++){
			printf(" ");
			if((matriz[i][j]==1)||(matriz[i][j]==0)){
			printf("%i ",matriz[i][j]);
		}else{
			printf(" ");
				
		}
			if(barra<2){
				printf("|");
				barra++;
			}
		}
		printf("\n");
		if(chao<2){
			printf("-----------\n");
			chao++;
		}
	}
	r++;
	printf("____________________\nRodada %i\n", r);
	printf("____________________\n\n");
} 
	 
void jogo(int m[3][3],int &ganhador,int &r,int &player,int  &um,int  &dois,int  &tres,int  &quatro,int  &cinco,int  &seis,int  &sete,int  &oito,int  &nove){
	int jogada, validade=0;
	 printTabela(m,r);
	do{
		printf("\nPlayer %i\n", player);
		 printf("\nDigite a sua jogada(1-9): ");
	     scanf("%i", &jogada);
	     switch (jogada){
	     	case 1:
	     		if(um==0){
	     			m[0][0]=player;
	     			validade++;
	     			um++;
	     			break;
				 }else{
				 	printf("Jogada Invalida!! Tente Novamente!: ");
				 	break;
				 }
		    case 2:
		    	if(dois==0){
	     			m[0][1]=player;
	     			validade++;
	     			dois++;
	     			break;
				 }else{
				 	printf("Jogada Invalida!! Tente Novamente!: ");
				 	break;
				 }
			case 3:
		    	if(tres==0){
	     			m[0][2]=player;
	     			validade++;
	     			tres++;
	     			break;
				 }else{
				 	printf("Jogada Invalida!! Tente Novamente!: ");
				 	break;
				 }
		    case 4:
		    	if(quatro==0){
	     			m[1][0]=player;
	     			validade++;
	     			quatro++;
	     			break;
				 }else{
				 	printf("Jogada Invalida!! Tente Novamente!: ");
				 	break;
				 }
			case 5:
		    	if(cinco==0){
	     			m[1][1]=player;
	     			validade++;
	     			cinco++;
	     			break;
				 }else{
				 	printf("Jogada Invalida!! Tente Novamente!: ");
				 	break;
				 }
			case 6:
		    	if(seis==0){
	     			m[1][2]=player;
	     			validade++;
	     			seis++;
	     			break;
				 }else{
				 	printf("Jogada Invalida!! Tente Novamente!: ");
				 	break;
				 }
			case 7:
		    	if(sete==0){
	     			m[2][0]=player;
	     			validade++;
	     			sete++;
	     			break;
				 }else{
				 	printf("Jogada Invalida!! Tente Novamente!: ");
				 	break;
				 }	
		    case 8:
		    	if(oito==0){
	     			m[2][1]=player;
	     			validade++;
	     			oito++;
	     			break;
				 }else{
				 	printf("Jogada Invalida!! Tente Novamente!: ");
				 	break;
				 }
			case 9:
		    	if(nove==0){
	     			m[2][2]=player;
	     			validade++;
	     			nove++;
	     			break;
				 }else{
				 	printf("Jogada Invalida!! Tente Novamente!: ");
				 	break;
				 } 
			default:
					printf("Jogada Invalida!! Tente Novamente!: ");
				 	break;
		 }
	   
	     if((m[0][0]==0)&&(m[0][1]==0)&&(m[0][2]==0)||(m[0][0]==1)&&(m[0][1]==1)&&(m[0][2]==1)){
	     	printTabela(m,r);
	      printf("__________________\n|Campeao Player %i|\n------------------\n", m[0][0]);
		 	exit(0);
		 } 
		 if((m[1][0]==0)&&(m[1][1]==0)&&(m[1][2]==0)||(m[1][0]==1)&&(m[1][1]==1)&&(m[1][2]==1)){
	     	printTabela(m,r);
	      printf("__________________\n|Campeao Player %i|\n------------------\n", m[1][0]);
		 	exit(0);
		}
		 if((m[2][0]==0)&&(m[2][1]==0)&&(m[2][2]==0)||(m[2][0]==1)&&(m[2][1]==1)&&(m[2][2]==1)){
	     	printTabela(m,r);
	      printf("__________________\n|Campeao Player %i|\n------------------\n", m[2][0]);
		 	exit(0);
		} if((m[1][0]==0)&&(m[2][0]==0)&&(m[0][0]==0)||(m[0][0]==1)&&(m[1][0]==1)&&(m[2][0]==1)){
	     	printTabela(m,r);
	      printf("__________________\n|Campeao Player %i|\n------------------\n", m[2][0]);
		 	exit(0);
		}if((m[1][1]==0)&&(m[2][1]==0)&&(m[0][1]==0)||(m[0][1]==1)&&(m[1][1]==1)&&(m[2][1]==1)){
	     	printTabela(m,r);
	      printf("__________________\n|Campeao Player %i|\n------------------\n", m[0][1]);
		 	exit(0);
		}if((m[1][2]==0)&&(m[2][2]==0)&&(m[0][2]==0)||(m[0][2]==1)&&(m[1][2]==1)&&(m[2][2]==1)){
	     	printTabela(m,r);
	      printf("__________________\n|Campeao Player %i|\n------------------\n", m[0][2]);
		 	exit(0);
		}
		if((m[0][0]==0)&&(m[2][2]==0)&&(m[1][1]==0)||(m[0][0]==1)&&(m[1][1]==1)&&(m[2][2]==1)){
	     	printTabela(m,r);
	      printf("__________________\n|Campeao Player %i|\n------------------\n", m[1][1]);
		 	exit(0);
		}
		
		if(r==9){
	     	printTabela(m,r);
	      printf("Deu Velha!!\nNinguem Ganhou!");
		 	exit(0);
		}
	}while(validade!=1);

	
}
int main(){
	int r=0,ganhador=0,player=1,m[3][3]={
	3,3,3,
    3,3,3,
    3,3,3
    };
    int um=0,dois=0,tres=0,quatro=0,cinco=0,seis=0,sete=0,oito=0,nove=0;
	printf("_______________\n|Jogo Da Velha|\n---------------\nPlayer 1= 1\nPlayer 2= 0\n");
	
	do{
	jogo(m,ganhador,r,player,um,dois,tres,quatro,cinco,seis,sete,oito,nove);	
	if(player==1){
		player=0;
	}else{
		player=1;
	}
	
	}while(1);
	
}
