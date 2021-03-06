#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>
//#include <Windows.h>
#include <termios.h>
#include <unistd.h>


/*
 *COMPATIBILITY CODE EXTRACTED FROM STACKOVERFLOW:
 * http://stackoverflow.com/questions/7469139/what-is-equivalent-to-getch-getche-in-linux 
 */
static struct termios old, _new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  _new = old; /* make new settings same as old settings */
  _new.c_lflag &= ~ICANON; /* disable buffered i/o */
  _new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &_new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}

/*
 * END OF COMPATIBLE CODE
 */

void title()
{
	printf("XXXXX  X  XXXXX     XXXXX    X    XXXXX     XXXXX    X    XXXXX\n");
	printf("  X       X     XXX   X    X   X  X     XXX   X    X   X  X\n");
	printf("  X    X  X     XXX   X    XXXXX  X     XXX   X    X   X  XXXXX\n");
	printf("  X    X  X           X    X   X  X           X    X   X  X\n");   
	printf("  X    X  XXXXX       X    X   X  XXXXX       X      X    XXXXX\n\n\n\n");
}



void mainGame(bool *isGameActiveP)
{
	system("clear");
	srand(time(NULL));
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
char message1[]="\nPlease input the number of the square where you want to place your: ";
char message2[]="\nComputer went to: ";

for( i = 0; i<9 && winner==0; i++){
	
        printf("\n\n");
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("-----------\n");
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("-----------\n");
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
        
player = i%2 + 1; 

 do{
if(player==1) printf("%s %c: ", message1,(player==1)?'X':'O');

if(player==1) scanf("%d", &go);
if(player==2) go=rand()%9+1;

            row = --go/3;
            column = go%3;
            
        if(player==2 && go>=0 && go<=9&&(board[row][column]!='X'&&board[row][column]!='O')){
		printf("\n%s %d", message2, go+1);
	}
		}
        while(go<0 || go>=9 || board[row][column]=='X'||board[row][column]=='O');
        
         board[row][column] = (player == 1) ? 'X' : 'O';
        
        if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
           (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
            winner = player;
        else            
            for(line = 0; line <= 2; line ++)
                
                if((board[line][0] == board[line][1] && board[line][0] == board[line][2])||
                   (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
                    winner = player;
}
  printf("\n\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    
    if(winner == 0)
        printf("\nDraw\n");
    else{
		if(winner==1) printf("\nYou won!");
    	if(winner==2) printf("\nComputer won!");
}

printf("\n\nPress any key to return to main menu...\n");
sleep(1);
getchar();
getchar();
		*isGameActiveP=true;
}




void instruction(bool *isGameActiveP)
{
	system("clear");
printf("Rules:\n\n");
printf("There are two players on 3x3 field.\n");
printf("Crosses go first.\n");
printf("Player wins if he makes up the right combination.\n");
printf("\nThis is the game field:\n");	
int l=0;
printf("\n\n");
        printf(" 1 | 2 | 3\n");
printf("-----------\n");
        printf(" 4 | 5 | 6\n");
printf("-----------\n");
        printf(" 7 | 8 | 9\n");

printf("\nTo win you should cross numbers diagonally, vertically or horizontally.");
printf("\n\nFor example, \"X\" player wins here:\n");
l=0;
printf("\n");
        printf(" X | 2 | 3\n");
printf("-----------\n");
        printf(" 4 | X | 6\n");
printf("-----------\n");
        printf(" 7 | 8 | X\n");

		printf("\nIf you both can't cross entire field, game is draw.");	
printf("\n\nPress any key to return to main menu...");
getchar();
*isGameActiveP = true;
}



void about(bool *isGameActiveP)
{
	system("clear");
	printf("The game was developed for programming coursework.\n");
	printf("\nCreated by Ilya Konnov.\n");
	printf("For more information check out my github profile: \nhttps://github.com/konnov-007");	
printf("\n\nPress any key to return to main menu...");
getch();
*isGameActiveP = true;	
}



void gameMenu(bool *isGameActiveP)
{	
	system("clear");
	title();
	printf("Welcome to \"Tic-Tac\" game.\n\n");
	printf("1)Play\n2)Instruction\n3)About\n4)Quit\n");
	unsigned char inputChar = getch();
	
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


int main()
{
bool isGameActive;
	
	do{
	gameMenu(&isGameActive);
}while(isGameActive==true);

	return 0;	
}
