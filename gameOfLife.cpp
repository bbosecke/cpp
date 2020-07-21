#include <iostream>
#include <chrono>
#include <thread>
#include <future>

using std::cout;
using std::endl;

/**
* @author Brodie Bosecke
*   The game Of Life is a well-known computing problem that I am going to replicate
*   This is the first program I am going to use that has a GUI in cpp
*
*   To compile the program, "g++ -o gamePlay gameOfLife.cpp"
*   To run the program, "./gamePlay"
*
*
*/

void nextGeneration(int board[10][10])
{
    int future[10][10];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int aliveNeighbours = 0;
            for(int x = -1; x <= 1; x++){
                for(int y = -1; y <= 1; y++){
                    aliveNeighbours += board[i+x][j+y];
                }
            }
            aliveNeighbours -= board[i][j];
            if((board[i][j] == 1) && (aliveNeighbours < 2)){
                future[i][j] = 0;
            } else if((board[i][j] == 1) && (aliveNeighbours > 3)){
                future[i][j] = 0;
            } else if((board[i][j] == 0) && (aliveNeighbours == 3)){
                future[i][j] = 1;
            } else {
                future[i][j] = board[i][j];
            }
        }
    }

    cout << "Next Generation" << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(future[i][j] == 0){
                cout << ".";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }


}


/**
*
*
*Testing pointers and how to access from methods
*/
int main()
{
    int board[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    };
    cout << "Original Generation" << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(board[i][j] == 0){
                cout << ".";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
    int timer = 0;
    //while(timer != 10){
    //}
    nextGeneration(board);
    



    //Intialise original living tiles, all else is dead
    //Rules per rotation

    return 0;
}