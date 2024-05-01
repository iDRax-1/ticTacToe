#include <stdio.h>
#include <stdlib.h>
#include "../lib/function.h"

extern char gameMap[3][3];

struct players
{
	int wins;
	int loses;
	int tie;
}
p1,p2;
		
int input(int userInput[], int charLimet)
{
	int character , counter = 0;

	while((character = getchar()) != '\n')
		if(counter < charLimet)
			userInput[counter++] = (int)character - 48;
	
	userInput[counter] = '\0';
	return counter;
}

int player_move(int playerNum, char playerChar)
{
			int playLocation[2];
			playLocation[0] = 0;
                        printf("Player%d: Take your turn ! : ", playerNum); input(playLocation, 1);

			while(gameMap[0][playLocation[0]] == 'X' || gameMap[0][playLocation[0]] == 'O' || playLocation[0] == 9){ 
				printf("Player%d: take another location! : ", playerNum); input(playLocation, 1); 
			}
			gameMap[0][playLocation[0]] = playerChar;
	
}

int who_win(char playerChar)
{
	if(playerChar == 'X')
		p1.wins += 1;	
	else if(playerChar == 'O')	
		p2.wins += 1;
	
	return 0;
}

int game_status(int counter, int playerNum, char playerChar)
{ 
	if(check(counter) == playerChar)
        {       
		who_win(playerChar);
       		printMap();
                printf("Player%d wins !\n", playerNum);
		return 1;
	}
	else if(check(counter) == 'D')
        {
		p1.tie +=1;
		printMap();
		printf("Tie...\n");
		return 1;	
	}
	return 0;
}
	
int game()
{
        reset();
        for(int i = 0; i < 9; i++)
        {
                printMap();
                if(i % 2 == 0) // player 1 move
		{
			player_move(1,'X');
			if(game_status(i, 1,'X') == 1)
				return 0;
		}
		else // player 2 move
                {
			player_move(2, 'O');
			if(game_status(i,2,'O') == 1)
				return 0;
                }
        }
}

int statistics()
{
        system("clear");
	printf("----------------------------------------\n");
	printf("Player One Statistics:\n" 					
        "Wins:%d\n" 
	"Loses:%d\n \n"
	, p1.wins
	, p1.loses = p2.wins);

	printf("player Two Statistics:\n"		
                "Wins:%d\n"
		"Loses:%d\n\n"
		, p2.wins
		, p2.loses = p1.wins);       
	
        printf("Number of draw:%d\n", p1.tie + p2.tie);
        printf("----------------------------------------\n");
        return 0;
}

int game_reset()
{
	system("clear");
	p1.wins = 0 , p1.loses = 0 , p2.wins = 0 , p2.loses =0 , p1.tie = 0, p2.tie = 0;
	return 0;
}
