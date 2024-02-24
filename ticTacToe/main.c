#include <stdio.h>
#include <stdlib.h>
#include "function.h"

char gameMap[9]; 
struct players{
	
	int wins;	
	int draws;
	int loses;

}p1, p2;



int main()
{
	system("clear");
	while(1)
	{
		int PLAYER_CHOICE;
		printf("1: start the Game... \n2: For Status... \n3: quit...\nChoose an option: ");
		scanf("%d", &PLAYER_CHOICE);
		
		switch(PLAYER_CHOICE)
		{
			case 1:
				game();
				break;

			case 2:
				statistics();
				break;	
			
			case 3:
				return 0;

			default:
				printf("choose a number from that list");
		}	
	}
	return 0;
}
