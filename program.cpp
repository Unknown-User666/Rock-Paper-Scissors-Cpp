#include <iostream>
#include <ctime>
#include <cstdlib>


//Get computer move
char
getComputerMove()
{
    int move;
    // gernerating random number between 0 - 2
    srand(time(NULL));
        move = rand() % 3;
    // returning move based on the random number generated
    if (move == 0) 
    {
        return 'p';
    }
    else if (move == 1)
    {
        return 's';
    }
    return 'r';
}

//Function to return the result of the game
int getResults(char playerMove, char computerMove)
{
    // Condition for draw
    if (playerMove == computerMove)
    {
        return 0;
    }

    //Condition for win and loss according to the game rule
    if (playerMove == 's' && computerMove == 'p')
    {
        return 1;
    }
    if (playerMove == 's' && computerMove == 'r')
    {
        return -1;
    }
    if (playerMove == 'p' && computerMove == 'r')
    {
        return 1;
    }
    if (playerMove == 'p' && computerMove == 's')
    {
        return -1;
    }
    if (playerMove == 'r' && computerMove == 's')
    {
        return -1;
    }
    if (playerMove == 'r' && computerMove == 'p')
    {
        return 1;
    }

    return 0;
}

//Driver code
int main()
{
    
    char playerMove;

    std::cout << "\n\n\n\tWelcome to Rock Paper Scissors Game\n";

    std::cout << "\n\tEnter r for ROCK, p for PAPER, and s for SCISSORS\n";

    //input from the user
        while(1)
        {
            std::cin >> playerMove; 
            if (playerMove == 'p' || playerMove == 'r' || playerMove == 's')
            {
                break;
            }
            else 
            {
                std::cout << "\t\t\tInvalid player move!!! Please try again.";
            }
        }

        //Computer move
        char
        computerMove = getComputerMove();

        int result = getResults (playerMove, computerMove);

        //printing results based on who won the game
        if (result == 0)
        {
           std::cout << "\n\t\t\tGame Draw!\n";
        }
        else if (result == 1)
        {
            std::cout << "\n\t\t\tCongratulations! Player won the game!\n";
        }
        else 
        {
            std::cout << "\n\t\t\tOh! Computer won the game!\n";
        }

        //Showing both moves
            std::cout << "\t\t\tYour move: " << playerMove;
            std::cout << "\t\t\tComputer's move: " << computerMove;

    return 0;
}