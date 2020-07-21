#include <iostream>

using std::cout;
using std::endl;

/**
* @author Brodie Bosecke
* July, 2020
*
*This is going to be a program that reads arguments and depending on the
*argument given depends on what the program does
*
* To compile the program, 'g++ -o arguments argumentLearning.cpp'
* to run the program, './argument' which will then prompt you further
*/


void add()
{
    cout << "please enter an integer that you wish to add to 7" << endl;
    int num1 = 0;
    std::cin >> num1;
    int temp = 7 + num1;
    cout << "7 + " << num1 << " is equal to: " << temp << endl;

}


void multiply()
{
    cout << "please enter an integer that you wish to multiply by 7" << endl;
    int num1 = 0;
    std::cin >> num1;
    int temp = 7 * num1;
    cout << "7 * " << num1 << " is equal to: " << temp << endl;
}


void subtract()
{
    cout << "please enter an integer that you wish to subtract from 7" << endl;
    int num1 = 0;
    std::cin >> num1;
    int temp = 7 - num1;
    cout << "7 - " << num1 << " is equal to: " << temp << endl;
}


void divide()
{
    cout << "please enter an integer that you wish to divide by 7" << endl;
    int num1 = 0;
    std::cin >> num1;
    int temp = num1 / 7;
    cout << "7 / " << num1 << " is equal to: " << temp << endl;
}



/**
* 
*/
int main(int argc, char** argv)
{

    char inFile;
    if(argc == 2){
        inFile = *argv[1];
    } else {
        cout << "To see full details on how to run this program, './arguments h'" << endl;
        return EXIT_FAILURE;
    }

    switch(inFile){
        case 'a':
            add();
            break;
        case 'm':
            multiply();
            break;
        case 's':
            subtract();
            break;
        case 'd':
            divide();
            break;
        default:
            cout << "To run this program, please type, ./arguments x" << endl;
            cout << "replace x with either 'a', 'm', 's', or 'd' which will then" << endl;
            cout << "do the following with two numbers you enter" << endl;
            cout << "a will prompt you to add a number to another number" << endl;
            cout << "m will prompt you to multiply a number to another number" << endl;
            cout << "s will prompt you to subtract a number to another number" << endl;
            cout << "d will prompt you to divide a number to 7 giving a result" << endl;
    }

    return 1;
}