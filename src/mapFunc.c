#include <stdio.h>
#include <stdlib.h>

char gameMap[3][3];

int printMap()
{
        system("clear");
        for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			printf("%c ", gameMap[i][j]);
		
		printf("\n");
	}
	
	return 0;
}
int check(int counter)
{
	for(int i = 0; i < 3; i++)
		if(gameMap[i][0] == gameMap[i][1] && gameMap[i][1] == gameMap[i][2])
			return gameMap[i][0];
	
	for(int i = 0; i < 3; i++)
		if(gameMap[0][i] == gameMap[1][i] && gameMap[1][i] == gameMap[2][i])
			return gameMap[0][i];
	

	if(gameMap[0][0] == gameMap[0][5] && gameMap[0][5] == gameMap[0][8])
		return gameMap[0][0];

	else if(gameMap[0][2] == gameMap[0][4] && gameMap[0][4] == gameMap[0][6])
		return gameMap[0][2];
	
	else if(counter == 8) 
		return 'D';
	else 
		return 0;
}
int reset()
{
        for(int i = 0; i < 9; i++)		
		gameMap[0][i] = (char)(i + 48); // convert the Integers to char ascii
	
        return 0;
}
