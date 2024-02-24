#include <stdio.h>
#include <stdlib.h>

extern char gameMap[9];
extern struct players
{
	int wins;
	int loses;
	int tie;
}
p1,p2;
int draw()
{
        system("clear");
        for(int i = 0; i < 9; i++ )
        {
                printf("%c ", gameMap[i]);
                if(i == 2 || i == 5 || i == 8)
                        printf("\n");
        }


        return 0;
}
int reset()
{
        for(int i = 0; i < 9; i++)
        {
                short reset = i + 48; // convert the Integers to char ascii table
                gameMap[i] = (char)reset;
        }
        return 0;
}

char check(int i)
{
	   if(gameMap[0] == gameMap[1] && gameMap[1] == gameMap[2])
           	return gameMap[0];
        
	   else if(gameMap[3] == gameMap[4] && gameMap[4] == gameMap[5])
		return gameMap[3];
        
	   else if(gameMap[6] == gameMap[7] && gameMap[7] == gameMap[8])
		return gameMap[6];
        
	   if(gameMap[0] == gameMap[3] && gameMap[3] == gameMap[6])
		return gameMap[0];
        
	   else if(gameMap[1] == gameMap[4] && gameMap[4] == gameMap[7])
		return gameMap[1];
        
	   else if(gameMap[2] == gameMap[5] && gameMap[5] == gameMap[8])
		return gameMap[2];
        
	   if(gameMap[0] == gameMap[4] && gameMap[4] == gameMap[8])
		return gameMap[0];
        
	   else if(gameMap[2] == gameMap[4] && gameMap[4] == gameMap[6])
		return gameMap[2];
	   
	   else if(i == 8)	
		   return 'D';
	    

	   else	
   		 return '\0';
}
int game()
{
        reset();
        for(int i = 0; i < 9; i++)
        {
                draw();
                if(i % 2 == 0)
                {
                        int play1 = 0;

                        printf("Player1 Take your turn ! : ");
                        scanf("%d", &play1);

                        while(gameMap[play1] == 'X' ||  gameMap[play1] == 'O')
                        {
                                printf("Player1 take another location! : ");
                                scanf("%d", &play1);

                        }
                        gameMap[play1] = 'X';

                        if(check(i) == 'X')
                        {
                                p1.wins += 1;
				p2.loses += 1;
				draw();
                        	printf("player 1 wins !\n");
				return 0;
			}
			else if (check(i) == 'D')
                	{
				p1.tie += 1;
				draw();
				printf("Tie...\n");
				return 0;
			}
		}

                else
                {
                        int play2 = 0;
                        printf("Player2 Take your turn ! : ");
                        scanf("%d", &play2);

                        while(gameMap[play2] == 'X' || gameMap[play2] == 'O')
                        {
                                printf("Player2 take another location! : ");
                                scanf("%d", &play2);
                        }
                        gameMap[play2] = 'O';
			if(check(i) == 'O')
                        {
                                p2.wins += 1;
				p1.loses += 1;
        			draw();
                        	printf("Player 2 wins !\n");
				return 0;
			}

			
			else if (check(i) == 'D')
                	{
				p2.tie +=1;
				draw();
				printf("Tie...\n");
				return 0;
			}
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
	, p1.wins, p1.loses);

	printf("player Two Statistics:\n"		
                "Wins:%d\n"
		"Loses:%d\n\n"
		, p2.wins, p2.loses);       
	
        printf("Number of draw:%d\n", p1.tie + p2.tie);
        printf("----------------------------------------\n");
        return 0;
}
