#include <iostream>

using namespace std;

int main(){

    // C-strings are arrays of type char terminated with null 
    // character, that is, \0 (ASCII value of null character is 0).
    
    
    char str[] = "C++";  // 4  = 3 + \0;
    char str0[] = {'C', '+', '+', '\0'};
    char str1[4] = {'C', '+', '+', '\0'};


    char in[100];
    cin >> in;
    cout << "like scanner.next() in java" << endl;
    cout << in << endl;

    // BE CARREFUL : the extraction operator >> works as scanf() in C and considers
    // a space " " has a terminating character.

    cin.get(in, 100);
    cout << "like scanner.nextLine() in java, but control also maxmum of character to read :)" << endl;
    cout << in << endl;
}