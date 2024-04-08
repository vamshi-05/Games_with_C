//Bingo Game
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void initialization(int brd_1[][5],int brd_2[][5]);
void randomnumbers(int brd[][5]);
void displayboard(int brd_1[][5],int brd_2[][5]);
int samenumbers(int brd[][5],int num);
int matchingcheck(int brd[][5],int num);

int main(){
   int brd_1[5][5],brd_2[5][5];
   int i,num,res;
   int player_1=0,player_2=0;
   initialization(brd_1,brd_2);
   randomnumbers(brd_1);
   randomnumbers(brd_2);
   printf("\n!!!..................................BINGO..................................!!!\n");
   displayboard(brd_1,brd_2);
   for( i=1;i<=25;i++){
      start1:
      printf("\nplayer 1 \n Choose your number(1-25) : ");
      scanf("%d",&num);
      if(num>0 && num<=25){
         res=matchingcheck(brd_1,num);
         if(res==-1){
            printf("\n....NUMBER IS ALREADY CHOOSEN.....!");
            goto start1;
         }
         if(res!=0){
            player_1+=res;
            printf("\n .........................PLAYER 1 SCORE : %d\n",player_1);
         }
         if(player_1>=5){
            displayboard(brd_1,brd_2);
            printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n\n");
            printf("\n ....CONGRATULATIONS..........!!! PLAYER 1 WINS........!!!");
            break;
         }
         res=matchingcheck(brd_2,num);
         displayboard(brd_1,brd_2);
         if(res!=0){
            player_2+=res;
            printf("\n ..........................PLAYER 2 SCORE : %d\n",player_2);
         }
         if(player_2>=5){
         printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n\n");
         printf("\n ....CONGRATULATIONS..........!!! PLAYER 2 WINS........!!!");
         break;
      }
         
      }
      else{
         printf("\n INVALID NUMBER.....!");
         goto start1;
      }
      start2:
      printf("\nplayer 2 \n Choose your number(1-25) : ");
      scanf("%d",&num);
      if(num>0 && num<=25){
   
         res=matchingcheck(brd_1,num);
         if(res==-1){
            printf("\n....NUMBER IS ALREADY CHOOSEN.....!");
            goto start2;
         }
         if(res!=0){
            player_1+=res;
            printf("\n ..........................PLAYER 1 SCORE : %d\n",player_1);
         }
         if(player_1>=5){
            displayboard(brd_1,brd_2);
            printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n\n");
            printf("\n ....CONGRATULATIONS..........!!! PLAYER 1 WINS........!!!");
            break;
         }
         res=matchingcheck(brd_2,num);
         displayboard(brd_1,brd_2);
         if(res!=0){
            player_2+=res;
            printf("\n ..........................PLAYER 2 SCORE : %d\n",player_2);
         }
         if(player_2>=5){
            printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n\n");
            printf("\n ....CONGRATULATIONS..........!!! PLAYER 2 WINS........!!!");
            break;
         }
      }
      else{
         printf("\n INVALID NUMBER.....!");
         goto start2;
      }
     
   }
   return 0;
}
void initialization(int brd_1[][5],int brd_2[][5]){
   int i,j;
   for(i=0;i<5;i++){
      for(j=0;j<5;j++){
         brd_1[i][j]=0;
         brd_2[i][j]=0;
      }
   }
}
void displayboard(int brd_1[][5],int brd_2[][5]){
   printf("\tPLAYER 1 \t\t\t\t\t PLAYER 2\n");
   printf("______________________________\t\t\t______________________________\n");
   for(int i=0;i<5;i++){
      printf("| %2d  | %2d  | %2d  | %2d  | %2d  |",brd_1[i][0],brd_1[i][1],brd_1[i][2],brd_1[i][3],brd_1[i][4]);
      printf("\t\t\t| %2d  | %2d  | %2d  | %2d  | %2d  |\n",brd_2[i][0],brd_2[i][1],brd_2[i][2],brd_2[i][3],brd_2[i][4]);
      printf("|_____|_____|_____|_____|_____|\t\t\t|_____|_____|_____|_____|_____|\n");
   }
}
void randomnumbers(int brd[][5]){
   int i,j,num,check;
   for(i=0;i<5;i++){
      for(j=0;j<5;j++){
         begin :
         num=rand()%25 +1;
        
         check=samenumbers(brd,num);
         if(check==-1)
            goto begin;
         else
           brd[i][j]=num;
      }
   }
}
int samenumbers(int brd[][5],int num){
   int res=0,i,j;
   for(i=0;i<5;i++){
      for(j=0;j<5;j++){
         if(num==brd[i][j]){
            res=-1;
            break;
         }
      }
      if(res==-1)
         break;
   }
  return res;
}
int matchingcheck(int brd[][5],int num){
   int i,j,res=-1,row,col,count;
   for(i=0;i<5;i++){
      for(j=0;j<5;j++){
         if(num==brd[i][j]){
            brd[i][j]=0;
            res=0;
            row=i;
            col=j;
            break;
         }
      }
   }
   if(res==-1)
      goto end;
      count=0;
      for(i=0;i<5;i++){
         if(brd[row][i]!=0){
            count++;
            break;
         }
      }
      if(count==0)
         res++;
      count=0;
      for(i=0;i<5;i++){
         if(brd[i][col]!=0){
            count++;
            break;
         }
      }
      if(count==0)
         res++;
      if((row==col)&&(brd[0][0]==brd[1][1] && brd[2][2]==brd[3][3] &&brd[0][0]==brd[4][4] ))
         res++;
      if((row+col==4)&&(brd[0][4]==brd[1][3] && brd[2][2]==brd[3][1] &&brd[2][2]==brd[4][0] ))
         res++;
   end :
 return res;
}
