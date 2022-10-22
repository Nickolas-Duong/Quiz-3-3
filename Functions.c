//Functions used by program
#include "Game.h"
#include <time.h>
#include <ctype.h>
#define MAXLEN 10

//playGame - user plays the game; game returns a value to prompt quit or win
void playGame(void)
{
    int randomNum;
    time_t t;
    char choice[MAXLEN+1];
    srand((unsigned) time(&t));

    //randomize correct number based on max number    
    randomNum = (rand() % max) + 1;
    //Loop within game while not 'q'
    while(tolower((int)*choice) != 'q')
    {
        //union = get choice    
        while(tolower((int)*choice) != 'q' && isdigit((int)*choice) != 1)
        {
            printf("Guess a random number between 1 and %d (press q to quit): ", max);
            scanf("%s", choice);
            if(tolower((int)*choice) != 'q' && isdigit((int)*choice) != 1)
            {
                printf("Invalid input, please try again\n\n");
            }
        }

        //if choice != 'q'
        if(tolower((int)*choice) != 'q')
        {
            //convert to int
            int temp = atoi(choice);

            //if choice is lower
            if(temp < randomNum && temp > 0)
            {
                printf("Your number is lower than the target number. \n");
            }
            //if choice is higher
            else if(temp > randomNum && temp <= max)
            {
                printf("You number is higher than the target number. \n");
            }
            //if choice is correct
            else if(temp == randomNum)
            {
                printf("You guessed the correct number! \n");
                
            }
            //if choice is not accepted
            else
            {
                printf("That value is not correct, please try again...\n");
            }
        }
        //if union == 'q'
        //quit game    
        else
        {
            printf("Quitting current game...\n\n");
        }
    }
}
//changeMaxNum - user changes max number the game uses
void changeMaxNum(void)
{
    char temp[MAXLEN+1] = "";
    while(isdigit((int)*temp) != 1)
    {
        printf("Enter a new Max Number between 1 and 100: ");
        scanf("%s", temp);
        if (isdigit((int)*temp) != 1)
        {
            printf("Not a number, please try again...\n\n");
        }
        else if(atoi(temp) < 1 || atoi(temp) > 100)
        {
            printf("Invalid value, please try again...\n\n");
        }
    }

    max = atoi(temp);
}

//exitProgram - user ends program
void exitProgram(void)
{
    printf("Quitting program...\n\n");
}