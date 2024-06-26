/********************************************************************
 * Course: Modolar Programming in C++
 * Lecture: 2 - basic string
 * File: basic_string_c_bonus.cc
 * 
 * Author: Yaniv Gabay
 * Date: 2024-04-08
 * 
 * Overview:
 * previosly we have shown: strcpy, strlen, strcat, strcmp
 * there are many more functions in the cstring library
 * this is some of my favorites 
 * link:  https://en.cppreference.com/w/cpp/header/cstring
 * 
 * Notes:
 * 
 *******************************************************************/

// ---------- Include Section ----------
#include <iostream>
// Add more #include directives as needed
#include <iomanip>
#include <cstring>
// ---------- Using Section ----------
using std::cout;
using std::cin;
using std::endl;

// ---------- Constants ----------
const int MAX_STRING_SIZE = 100;
const int MAX_STRINGS_ALLOWED = 20;

enum class WordType {
    Smallest,
    Biggest
};
// ---------- Function Prototypes ----------
void printContent(const char dict[][MAX_STRING_SIZE], int size);
int take_input(char dict[][MAX_STRING_SIZE]);
void wordFinder(const char dict[][MAX_STRING_SIZE], const int size,WordType type);
void infoContent(const char dict[][MAX_STRING_SIZE],const int size, WordType type);
// ---------- Main Function ----------
int main() {

  
    // lets say we have an empty two dim array
    // we want to fill it with words/strings
    // we want to take input from the user
    // untill the user will enter the word "end"
    
    //memset == good for initializing arrays
    char array[MAX_STRINGS_ALLOWED][MAX_STRING_SIZE];
    cout << "printing before memset" << endl;
    printContent(array, MAX_STRINGS_ALLOWED);
    memset(array, 0, sizeof(array));
    cout << "printing after memset" << endl;
    printContent(array, MAX_STRINGS_ALLOWED);

    cout << "====================" << endl;
    cout << "enter strings, end with 'end'" << endl;

    int size = take_input(array);
    cout << "====================" << endl;
    cout << "printing after input" << endl;
    cout << "took " << size << " strings" << endl;
    cout << "====================" << endl;
    cout << "printing the content" << endl;
    printContent(array, size);

    // lets take input from the user
    // till he will enter the word "end"
    // or untill we will reach the end of the array

    infoContent(array, size, WordType::Smallest);
    infoContent(array, size, WordType::Biggest);

    return 0;


}

// ---------- Functions ----------
void infoContent(const char dict[][MAX_STRING_SIZE],const int size, WordType type) {
    cout << "====================" << endl;
    cout << "printing info" << endl;
    
    wordFinder(dict, size, type);

    
    cout << "====================" << endl;

}

void wordFinder(const char dict[][MAX_STRING_SIZE], const int size, WordType type) {
    if (size == 0) return; // Handle empty array
    
    int index = 0; // Index of the currently smallest or largest word

    for (int i = 1; i < size; i++) { // Start from the second element
        int compare = strcmp(dict[i], dict[index]);

        if (type == WordType::Smallest && compare < 0) {
            index = i; // Found a smaller word
        } else if (type == WordType::Biggest && compare > 0) {
            index = i; // Found a bigger word
        }
    }

    // Print the result after finding the smallest or biggest word
    if (type == WordType::Smallest) {
        std::cout << "The smallest word is: " << dict[index] << std::endl;
    } else { // WordType::Biggest
        std::cout << "The biggest word is: " << dict[index] << std::endl;
    }
}

void printContent(const char dict[][MAX_STRING_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        cout << "line: " << i << " content: "<<dict[i] << endl;
    }
}
int take_input(char dict[][MAX_STRING_SIZE]) {

    //this const can be in constants section
    const char END[] = "end";
    char word[MAX_STRING_SIZE]; //temp word
    int size = 0;

    cin >> std::setw(MAX_STRING_SIZE) >> word;//important setw!!
    while(strcmp(word, END) != 0 && size < MAX_STRINGS_ALLOWED) {
        strcpy(dict[size], word);
        size++;
        //read another word
        cin >> std::setw(MAX_STRING_SIZE) >> word;
    }



    return size;
}