//main function - function that runs the game
#include "Game.h"

//const array of strings with function names
const char* const menuItems[] = {"Start Number Guessing Game", "Change Max Number Value", "Quit Game"};

//array of pointers for functions
void (*menuFuncPtrs[])(void) = {playGame, changeMax, exitProgram};

//int main
int main()
{
    void showUserMenuProcess(int, const char* const[], void(*[])(void));
    const int choices = sizeof(menuFuncPtrs)/sizeof(menuFuncPtrs[0]);
    showUserMenuProcess(choices, menuItems, menuFuncPtrs);
    
    return EXIT_SUCCESS;
}