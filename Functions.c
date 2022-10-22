//Functions used by program
#include "Game.h"
#include <time.h>
#include <ctype.h>

#define MAXLEN 10

//playGame - user plays the game; game returns a value to prompt quit or win
void playGame(void)
{
    union Data
    {
        int i;
        char str[MAXLEN+1];
    };
    
    union Data choice;
    int randomNum;
    time_t t;
    srand((unsigned) time(&t));

    //randomize correct number based on max number    
    randomNum = (rand() % max) + 1;
    //Loop within game while not 'q'
    while(tolower(choice.str) != 'q')
    {
        //union = get choice    
        while(tolower(choice.str) != 'q' && isdigit(choice.str) != 1)
        {
            printf("Guess a random number between 1 and %d (press q to quit): ", max);
            scanf("%s", choice.str);
            if(tolower(choice.str) != 'q' && isdigit(choice.str) != 1)
            {
                printf("Invalid input, please try again\n\n");
            }
        }

        //if choice != 'q'
        if(tolower(choice.str) != 'q')
        {
            //convert to int
            int temp = atoi(choice.str);
            choice.i = temp;

            //if choice is lower
            if(choice.i < randomNum && choice.i > 0)
            {
                printf("Your number is lower than the target number. \n");
            }
            //if choice is higher
            else if(choice.i > randomNum && choice.i <= max)
            {
                printf("You number is higher than the target number. \n");
            }
            //if choice is correct
            else if(choice.i == randomNum)
            {
                printf("You guessed the correct number! \n");
                strcpy(choice.str, 'q');
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
    while(isdigit(temp) != 1)
    {
        printf("Enter a new Max Number between 1 and 100: ");
        scanf("%s", temp);
        if (isdigit(temp) != 1)
        {
            printf("Not a number, please try again...\n\n");
        }
        else if(atoi(temp) < 1 || atoi(temp) > 100)
        {
            printf("Invalid value, please try again...\n\n");
        }
        *temp = "";
    }
}
//exitProgram - user ends program