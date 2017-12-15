/**
 * File: main.cpp
 * Author: Mihai Udrea
 * Date: 18-10-2017
 * Desc:
 * Copyright: University of West of England 2017
 */
#include <stdio.h>
#include <string>
#include <iostream>

// include the UFCFGL301's standard library
#include <ufcfgl-30-1.h>

// uncomment if you want to use the graphics library
//#include <graphics.h>

using namespace uwe;

/**
 * main routine, implements ...
 * @return      success
 */
int main(void) {
    std::string FullName;
    std::cout << "Enter your full name (add as many spaces as you want): "; // get user input for full name
    FullName = getString(); // get the name stored in FullName variable
    for (int i=0; i<=FullName.length(); i++){
        FullName[i] = toupper(FullName[i]); // convert string to uppercase, so we can print proper initials. for the purpose of this program, we can replace the original string instead of creating a new one
    }
    if (FullName[0] != ' '){
        std::cout << FullName[0]; // check if first character is a space
    }
    for(int i=0; i<FullName.length(); i++){
            if ((FullName[i-1] == ' ') && (FullName[i] != ' ')){ // check for double spaces
                std::cout << FullName[i]; // if current character is not space and previous character is space, print current character
            
        }
    }
    std::cout << std::endl;
    return 0;
}
