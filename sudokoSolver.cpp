#include <iostream>

using std::cout;
using std::endl;

/**
* @author Brodie Bosecke
* July 2020
*
* Sudoko solver I am creating because I struggled with 2 sudoko's today >:(
* I am going to implement a brute force algorithm (depth first, with backtracking)
* as described by the wikipedia of "sudoko solving algorithms".
*
* The rules of sudoko are each row, column and square must only contain 1 * value of 1-9
* therefore to create a solver, I have to insert a number, check if it violates the condition
* by checking the row, checking the column, and checking the square.
*
* TO COMPILE - "g++ -o solve sudokoSolver.cpp"
* TO RUN - ./solve"
*
* CHANGES TO MAKE ONCE GOT WORKING BELOW
* Make it so can enter sudoko from textFile OR manually enter using argc and argv flags
*
*/


/**
*
*
* 
*/
bool checkRules(int posRow, int posCol)
    //Call 3 methods, one by one, if any return false, then number cannot exist there. n++
    //check row
    //check col
    //check square
/**
*
* This function iterates through the entire grid to find all the blank spaces to be solved
* 
*/
bool findBlankSpaces(int grid[9][9])
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(grid[i][j] == 0){
                checkRules(grid[i][j])
            }
        }
    }
    return false;
}





int main()
{
    int grid[9][9] =   {{7, 3, 4, 0, 0, 2, 0, 0, 0},
                        {6, 0, 5, 0, 8, 0, 0, 7, 2},
                        {9, 2, 0, 5, 0, 0, 0, 4, 0},
                        {1, 0, 0, 3, 0, 9, 8, 0, 0},
                        {0, 0, 0, 1, 5, 0, 0, 2, 0},
                        {0, 6, 3, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 6, 0, 4, 2, 3, 0},
                        {0, 4, 0, 0, 7, 0, 6, 0, 0},
                        {8, 0, 0, 2, 3, 0, 4, 1, 7}};
    
    findBlankSpaces(grid);

    return 0;
}