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
void  encrypt (int, char[]);
char transform (char, int);

void encrypt(int key, char mess[]){
    int i=0;
    std::cout << "Cipher: ";
    while(mess[i]!='\0')
        std::cout << transform(mess[i++], key);
    std::cout << std::endl;
    return;
   }
char transform(char ch, int key){
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // entire alphabet
    char up_case = toupper(ch); // convert to uppercase
    int i=0;
    while((up_case != alpha[i]) && (i < 26))    // locate the letter or end of alphabet
              i++;
     if (i > 25)    // check if character is in the alphabet
           return ch;
    int new_key = key % 26; // check if key is larger than the number of characters in the alphabet and create the new key
    if (new_key + i > 25){
         return alpha[(new_key + i) % 26];  // return the coded char
        }
        else{
             return alpha[new_key + i]; // return the coded char
        }
}

int main(int argc, char *argv[]){
    int i,n,key;
    if (!argv[1]){
        std::cout << "You forgot the key. Please restart." << std::endl;
        return 1;
    }
    std::string Message;
    char Mess[256];
    std::cout << "Enter message: ";
    Message = getString();  // get the message from user input
    key = atoi(argv[1]);    // transform the key from char to integer
    for (int i = 0; i < Message.length(); i++) {
        Mess[i] = Message[i];
    }
    encrypt(key,Mess);

    return 0;  
}