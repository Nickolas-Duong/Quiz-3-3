//Contains code for all functions used by the game
#include "Game.h"
#define MAXLEN 80

//get char from input
int getline(char *buf, int bufLen)
{
    int c;
    int i = 0;
    while((c = getchar()) != '\n' && c != EOF)
    {
        if(i < bufLen)
        {
            buf[i++] = c;
        }
    }
    buf[i] = '\0';
    return (c==EOF) ? -1 : i;
}

static void showUserMenu(int n, const char *const items[]) 
{ 
    printf("Your choices are:\n"); 
    for (int i = 1; i <= n; i++) 
    {
        printf("\t%i) %s\n", i, items[i-1]); 
    }

    printf("Enter a value between 1 and %i: ", n);

} 

//getChoice - get a choice from the user - type cast return type
static int getChoice(int n, const char *const items[])
{
    //get choice from user
    int choice;
    char line[MAXLEN+1];
    showUserMenu(n, items);
    //printf("Enter a value between 1 and %i: ", n);
    while(getline(line, MAXLEN) != -1)
    {
        //return choice
        if(sscanf(line, "%i", &choice) == 1 && 1 <= choice && choice <= n)
        {
            return choice;
        }
    }

    return EXIT_SUCCESS;
}

//showUserMenu - print the user the menu to decide to play the game
void showUserMenuProcess(int numChoices, const char *const menu[], void (*fPtrs[])(void))
{
    //print user menu
    int choice;
    while((choice = getChoice(numChoices, menu)) != 0)
    {
        //get function ptr | calls function
        fPtrs[choice-1]();

        if(choice == 3)
        {
            break;
        }
    }

}
