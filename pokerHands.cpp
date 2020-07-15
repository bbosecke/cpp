#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

/**
* @author Brodie Bosecke
* July 2020
* Etude Poker Hands - rewritten in c++ for practice
*/

/**
*
* getInput takes input from the user, and returns the input to be stored in the array from
* where it was called.
*/
string getInput(){
    string temp;
    cin >> temp; 
    return temp;
}

/**
*
* This function takes a string as parameters and returns the uppercase version of the string
* SOURCE: https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
*/
string tidyHand(std::string card){
    std::transform(card.begin(), card.end(),card.begin(), ::toupper);
    return card;
}

/**
*
*change input into int values, the int values are ordered to how the hand should be ordered (smallest to largest)
*/
int stringCardToInt(string card){
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
        exit(0);
    }

    return placeholder;
}

// Function to sort character array b[] 
// according to the order defined by a[] 
// https://www.geeksforgeeks.org/sorting-array-according-another-array-using-pair-stl/
void pairsort(int a[], string b[], int n) 
{ 
    pair<int, string> pairt[n]; 
  
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
* Driver code */
int main()
{
    int cardPlaceholder[5];
    string cardsList[5];
    cout << "Enter a card value, and press enter to then enter another card value" << endl;
    cout << "Please enter 5 card values e.g. '5H'" << endl;
    for(int i = 0; i < 5; i++){
        cardsList[i] = getInput();
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
    /**FOR LOOP to print what is currently in the cardsList
    for(int i = 0; i < 5; i++){
        cout << cardPlaceholder[i] << " ";
    } */
    cout << endl;
    return 0;
}