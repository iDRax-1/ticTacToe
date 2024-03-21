#include <stdio.h>
#include <stdlib.h>
#include "function.h"

extern struct players{
	
	int wins;	
	int draws;
	int loses;

}p1, p2;


enum options {PLAY = 1, STATISTICS ,RESET, QUIT};

int main()
{
	system("clear");
	while(1)
	{
		int PLAYER_CHOICE[2];
		printf(   "1: Start the Game..."
			"\n2: For Status..."
		       	"\n3: Reset game status"
			"\n4: quit..."
			"\nChoose an option: ");
		input(PLAYER_CHOICE, 1);
		
		switch(PLAYER_CHOICE[0])
		{
			case PLAY:
				game();
				break;

			case STATISTICS:
				statistics();
				break;	
			
			case RESET:
				game_reset();
				break;

			case QUIT:
				return 0;

			default:
				system("clear");
				printf("choose character from list\n\n");
		}	
	}
}
