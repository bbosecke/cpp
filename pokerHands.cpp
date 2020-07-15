#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;

/**
* @author Brodie Bosecke
* July 2020
* Etude Poker Hands - rewritten in c++ for practice
*
* COMMANDS TO USE IN TERMINAL
* To compile program, "g++ -o pokerHands pokerHands.cpp"
* to run the file, "./pokerHands"
*/

/**
*
*
*
* SOURCE: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
*/
std::vector<std::string> splitString (const std::string &s) {
    char delim = '/';
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

/**
*
* getInput takes input from the user, and returns the input to be stored in the array from
* where it was called.
*/
std::string getInput(){
    std::string temp;
    std::cin >> temp; 
    return temp;
}

/**
*
* This function takes a string as parameters and returns the uppercase version of the string
* SOURCE: https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
*/
std::string tidyHand(std::string card){
    std::transform(card.begin(), card.end(),card.begin(), ::toupper);
    return card;
}

/**
*
*change input into int values, the int values are ordered to how the hand should be ordered (smallest to largest)
*/
int stringCardToInt(std::string card){
    int placeholder = 0;
    if(card.at(0) == 'A' || card.at(0) == '1'){
        placeholder = 80;
    } else if(card.at(0) == 'J'){
        placeholder = 65;
    } else if(card.at(0) == 'Q'){
        placeholder = 70;
    } else if(card.at(0) == 'K'){
        placeholder = 75;
    } else if(card.at(0) == 'T'){
        placeholder = 60;
    } else {
        placeholder = card.at(0);
    }

    if(card.at(1) == 'C'){
        placeholder += 10;
    } else if(card.at(1) == 'D'){
        placeholder += 100;
    } else if(card.at(1) == 'H'){
        placeholder += 1000;
    } else if(card.at(1) == 'S'){
        placeholder += 10000;
    } else {
        placeholder = 0;
    }

    if(placeholder == 0){
        cout << "INVALID INPUT" << endl;
        exit(EXIT_FAILURE);
    }

    return placeholder;
}

// Function to sort character array b[] 
// according to the order defined by a[] 
// https://www.geeksforgeeks.org/sorting-array-according-another-array-using-pair-stl/
void pairsort(int a[], std::string b[], int n) 
{ 
    std::pair<int, std::string> pairt[n]; 
  
    // Storing the respective array 
    // elements in pairs. 
    for (int i = 0; i < n; i++)  
    { 
        pairt[i].first = a[i]; 
        pairt[i].second = b[i]; 
    } 
  
    // Sorting the pair array. 
    sort(pairt, pairt + n); 
      
    // Modifying original arrays 
    for (int i = 0; i < n; i++)  
    { 
        a[i] = pairt[i].first; 
        b[i] = pairt[i].second; 
    } 
} 
  


/**Checks the current pos of array to previously filled positions */
//Currently invalid. ONly works if the values are back to back. Sort before?
void duplicateChecker(int i){
    int temp[5];
    int j = 0;
    for(int k = 0; k < 5; k++){
        if(i == temp[k]){
            cout << "DUPLICATE VALUE" << endl;
            exit(0);
        }
    }
    temp[j] = i;

    j++;

}


/**
*
*
* READ IN FROM ARGS SOURCE:
*   https://stackoverflow.com/questions/7651243/c-read-a-file-name-from-the-command-line-and-utilize-it-in-my-file
* READ LINE BY LINE SOURCE:
*   https://stackoverflow.com/questions/13035674/how-to-read-line-by-line-or-a-whole-text-file-at-once
* Driver code */
int main(int argc, char** argv)
{
    std::string inFile = "";
    if(argc == 2){
        inFile = argv[1];
        cout << inFile << endl;
    } else {
        cout << "USAGE: ./pokerHands manyHands.txt" << endl;
        return 1;
    }
    int cardPlaceholder[5];
    std::string cardsList[5];
    std::ifstream file(inFile);
    std::string line;

    if(!file.is_open()){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while(std::getline(file, line)){
        std::vector<std::string> v = splitString(line);
        for(int j = 0; j < 5; j++){
            cardsList[j] = v[j];
        }
        for(int i = 0; i < 5; i++){
        cardsList[i] = tidyHand(cardsList[i]);
        }
        for(int i = 0; i < 5; i++){
            cardPlaceholder[i] = stringCardToInt(cardsList[i]);
        }
        //check for duplicate int values
        pairsort(cardPlaceholder, cardsList, 5);

        for(int i = 0; i < 5; i++){
            duplicateChecker(cardPlaceholder[i]);
        }

        for (int i = 0; i < 5; i++){
            cout << cardsList[i] << " "; 
        }
        cout << "" << endl;

    }
    return 0;
}