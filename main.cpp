#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void title()
{
	printf("XXXXX  X  XXXXX     XXXXX    X    XXXXX     XXXXX    X    XXXXX\n");
	printf("  X       X     XXX   X    X   X  X     XXX   X    X   X  X\n");
	printf("  X    X  X     XXX   X    XXXXX  X     XXX   X    X   X  XXXXX\n");
	printf("  X    X  X           X    X   X  X           X    X   X  X\n");   
	printf("  X    X  XXXXX       X    X   X  XXXXX       X      X    XXXXX\n\n\n\n");
}



/*void firstStepChoose(bool *whoStartP)
{
	int tmp;
	srand(time(NULL));
	tmp=rand()%2;
	if(tmp==0) *whoStartP=false;
	if(tmp==1) *whoStartP=true;
}*/


void mainGame(bool *isGameActiveP)
{
	system("cls");
int i = 0;
int player = 0;
int go = 0;
int row = 0; 
int column = 0;
int line = 0;
int winner = 0;
char board[3][3] = 
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
char message1[]="\nPlease enter the number of the square where you want to place your";
char message2[]="\nComputer's step";

for( i = 0; i<9 && winner==0; i++){
	
        printf("\n\n");
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("-----------\n");
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("-----------\n");
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
        
player = i%2 + 1; 
if(player==1) printf("%s %c: ", message1,(player==1)?'X':'O');
if(player==2) printf("%s ", message2);

 /*do{
printf("\nPlayer %d, please enter the number of the square "
                   "where you want to place your %c: ", player,(player==1)?'X':'O');
            scanf("%d", &go);
            
            row = --go/3;
            column = go%3;
        }
        while(go<0 || go>9 || board[row][column]>'9');*/
	
}
printf("\n\nPress any key to return to main menu...");
getch();
		*isGameActiveP=true;
}




void instruction(bool *isGameActiveP)
{
	system("cls");
printf("Rules:\n\n");
printf("There are two players on 3x3 field.\n");
printf("Crosses go first.\n");
printf("Player wins if he makes up the right combination.\n");
printf("\nThis is the game field:\n");	
int l=0;
for(int i=0; i<3; i++){
	for(int j=0; j<3; j++){
		printf("| %c ", char(49+l));
		l++;
	}
	printf("|");
	printf("\n");
}
printf("\nTo win you should cross numbers diagonally, vertically or horizontally.");
printf("\n\nFor example, \"X\" player wins here:\n");
l=0;
for(int i=0; i<3; i++){
	for(int j=0; j<3; j++){
		if((i==0&&j==0)||(i==1&&j==1)||(i==2&&j==2)) printf("| X ");
		else printf("| %c ", char(49+l));
		l++;
	}
	printf("|");
	printf("\n");
}
		printf("\nIf you both can't cross entire field, game is draw.");
		
printf("\n\nPress any key to return to main menu...");
getch();
*isGameActiveP = true;
}



void about(bool *isGameActiveP)
{
	system("cls");
	printf("The game was developed for programming coursework.\n");
	printf("\nCreated by Ilya Konnov.\n");
	printf("For more information check out my github profile: \nhttps://github.com/konnov-007");	
	
	printf("\n\nPress any key to return to main menu...");
	getch();
*isGameActiveP = true;	
}



void gameMenu(bool *isGameActiveP)
{	
	system("cls");
	title();
	printf("Welcome to \"Tic-Tac\" game.\n\n");
	printf("1)Play\n2)Instruction\n3)About\n4)Quit\n");
	unsigned char inputChar = _getch();
	
	 if((inputChar!='1')&&(inputChar!='2')&&(inputChar!='3')&&(inputChar!='4'))
	    *isGameActiveP=true;
	
	switch (inputChar)
	{
		
	    case '1':
	    {
	    	mainGame(isGameActiveP);
		    break;
	    }
	    
	    case '2':
	    {
		    instruction(isGameActiveP);
		    break;
	    }

		case '3':
		{
			about(isGameActiveP);
			break;	
		}
		
	    case '4':
	    {
	    	*isGameActiveP=false;
		    break;
	    }
	   
}
}


main()
{
bool isGameActive;
	
	do{
	gameMenu(&isGameActive);
}while(isGameActive==true);

	return 0;	
}
