//SOS GAME
#include<stdio.h>
#include<stdlib.h>

typedef struct sos{
    char board[8][8];
    int player1;
    int player2;
}SOS;

void displayboard(SOS *g);
void initialization(SOS *g);
int selec_score(SOS *g);
int main(){
    
    SOS *g;
    g=malloc(sizeof(SOS));
    int res,choice;
    
    initialization(g);
    displayboard(g);
    
    for(int i=0;i<64;i++){
        beg_p1:
        printf("\nPLAYER 1 TURN ");
        res=selec_score(g);
         if(res==-1){
            printf("\nPLAYER 1 LEFT THE GAME...");
            printf("\nCONGRATULATIONS-----!!....PLAYER 2 WINS....!!");
            break;
        }
        displayboard(g);
        if(res>0){
           g->player1+=res;
           printf("\n%d MATCHED................................PLAYER 1 SCORE : %d",res,g->player1);
           goto beg_p1;
        }
        
        beg_p2:
        printf("\nPLAYER 2 TURN ");
        res=selec_score(g);
        if(res==-1){
            printf("\nPLAYER 2 LEFT THE GAME...");
            printf("\nCONGRATULATIONS-----!!....PLAYER 1 WINS....!!");
            break;
        }
        displayboard(g);
        if(res>0){
           g->player2+=res;
           printf("\n%d MATCHED.................................PLAYER 2 SCORE : %d",res,g->player2);
           goto beg_p2;
        }
      if(i%10==0 && i!=0){
         printf("\n*!!!!!*");
         printf("\nCONTINUE THE GAME(1) OR STOP THE GAME(0)");
         printf("\nEnter your choice");
         scanf("%d",&choice);
         if(choice==0){
            printf("*");
            printf("\nGAME IS ENDED....................");
            break;
         }
      }  
   }
    
    if(res!=-1){
      printf("\n**");
      if(g->player1==g->player2)
         printf("\n!!....DRAW....!!");
      else if(g->player1>g->player2)
         printf("\n!!.......CONGRATULATIONS-----!!....PLAYER 1 WINS....!!");
      else 
         printf("\n!!........CONGRATULATIONS-----!!....PLAYER 2 WINS....!!");
    }  
       
  return 0;
}
void initialization(SOS *g){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            g->board[i][j]=' ';
        }
    }
}
void displayboard(SOS *g){
    printf(" \n   0    1     2     3     4     5     6     7 \n");
    printf(" _______________________________________________\n");
    for(int i=0;i<8;i++){
        printf("%d| %c  | %c   | %c   | ",i,g->board[i][0],g->board[i][1],g->board[i][2]);
        printf(" %c  | %c   | %c   | ",g->board[i][3],g->board[i][4],g->board[i][5]);
        printf(" %c  | %c   |\n",g->board[i][6],g->board[i][7]);
        printf(" ||||||||_|\n");
   
    }
   
}
int selec_score(SOS *g){
    int i,j;
    char ch;
    int res=0;
    begin:
    printf("\nCHOOSE S or O or Q (QUIT)  :");
    scanf(" %c",&ch);
    if(ch=='S' || ch=='s' || ch=='O' || ch=='o' || ch=='Q' || ch=='q')
    {
      if ( ch=='Q' || ch=='q'){
         res=-1;
         goto end;
      }  
      begindim:
      printf("\nENTER ROW (0-7) : ");
      scanf("%d",&i);
      printf("\nENTER COLUMN (0-7) : ");
      scanf("%d",&j);
      if((i<0 || i>7)||(j<0 || j>7)){
          printf("\nINVALID BOX.!!");
          goto begindim;
      }
      if((ch=='S' || ch=='s')&& g->board[i][j]==' ')
         g->board[i][j]='S';
      else if((ch=='O' || ch=='o') && g->board[i][j]==' ')
         g->board[i][j]='O';
      else{
         printf("\n!CHOOSEN BOX IS FILLED!");
         goto begin;
      }
    }
    else{
       printf("\nINVALID CHOICE.!");
       goto begin;
    }
   if(ch=='S'||ch=='s'){
      if(j<6 && (g->board[i][j]=='S' && g->board[i][j+1]=='O' && g->board[i][j+2]=='S'))
           res++;
      if(j>1 && (g->board[i][j]=='S' && g->board[i][j-1]=='O' && g->board[i][j-2]=='S'))
           res++;
      if(i>1 && (g->board[i][j]=='S' && g->board[i-1][j]=='O' && g->board[i-2][j]=='S'))
           res++;
      if(i<6 && (g->board[i][j]=='S' && g->board[i+1][j]=='O' && g->board[i+2][j]=='S'))
           res++;
      if((i>1&&j<6) && (g->board[i][j]=='S' && g->board[i-1][j+1]=='O' && g->board[i-2][j+2]=='S'))
           res++;
      if((i<6&&j<6) && (g->board[i][j]=='S' && g->board[i+1][j+1]=='O' && g->board[i+2][j+2]=='S'))
           res++;
      if((i>1&&j>1) && (g->board[i][j]=='S' && g->board[i-1][j-1]=='O' && g->board[i-2][j-2]=='S'))
           res++;
      if((i<6&&j>1) && (g->board[i][j]=='S' && g->board[i+1][j-1]=='O' && g->board[i+2][j-2]=='S'))
           res++;
   }
   else{
      if((j>0&&j<7) && (g->board[i][j-1]=='S' && g->board[i][j]=='O' && g->board[i][j+1]=='S'))
           res++;
      if((i>0&&i<7) && (g->board[i-1][j]=='S' && g->board[i][j]=='O' && g->board[i+1][j]=='S'))
           res++;
      if((j>0&&j<7 && i>0&&i<7) && (g->board[i+1][j-1]=='S' && g->board[i][j]=='O' && g->board[i-1][j+1]=='S'))
           res++;
      if((j>0&&j<7 && i>0&&i<7) && (g->board[i-1][j-1]=='S' && g->board[i][j]=='O' && g->board[i+1][j+1]=='S'))
           res++;
   }
   end:
 return res;  
}
