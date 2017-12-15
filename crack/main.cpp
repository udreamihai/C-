/**
 * File: main.cpp
 * Author: Mihai Udrea
 * Date: 18-10-2017
 * Desc: Must be the ugliest algorithm EVER! 
 * Copyright: University of West of England 2017
 */
#define _XOPEN_SOURCE
#include <stdio.h>
#include <string>
#include <iostream>
#include <crypt.h>
#include <ctime>
#include <thread>
#include <mutex>

// include the UFCFGL301's standard library
#include <ufcfgl-30-1.h>

// uncomment if you want to use the graphics library
//#include <graphics.h>

using namespace uwe;

/**
 * main routine, implements ...
 * @return      success
 */

int start_s=clock();
std::string password;
char salt[3];
char hashed[256];
std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char test[4];
std::string testpass;
std::mutex MyMutex;
// let's declare and create our 4 functions which will run in separate threads
int crack1(int argc, const char *hash[]);
int crack2(int argc, const char *hash[]);
int crack3(int argc, const char *hash[]);
int crack4(int argc, const char *hash[]);

int crack1(int argc, const char *hash[]){
    // case 1 char password
    MyMutex.lock();
    std::lock_guard<std::mutex> lck (MyMutex, std::adopt_lock);
    std::cout << std::endl << "Start checking 1 character passwords" << std::endl;
    char test1[2];
    std::string testpass1;
    password = hash[1];
    // let's build the salt
    salt[0] = password[0];
    salt[1] = password[1];
    salt[2] = '\0';
    // let's get the hashed password
    for (int j1=2; j1<=password.length(); j1++){
        hashed[j1-2] = password[j1];
    }
    for (int i1 = 0; i1<alphabet.length(); i1++){
        test1[0] = alphabet[i1];
        test1[1] = '\0';
        testpass1 = crypt(test, salt);
        //std::cout << test1 << std::endl;
        if (testpass1 == password){
            std::cout << "Finished checking 1 character passwords - success" << std::endl;
            std::cout << "Cracked password: " << test1 << " with the salt: " << salt << std::endl;
            int stop_s=clock();
            std::cout << "... and it only took " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << " seconds to crack." << std::endl;
            return 0;
        }
    }
    std::cout << "Finished checking 1 character passwords - no success" << std::endl;
    return 0;
}

int crack2(int argc, const char *hash[]){
    // case 2 chars password
    MyMutex.lock();
    std::lock_guard<std::mutex> lck (MyMutex, std::adopt_lock);
    std::cout << std::endl << "Start checking 2 characters passwords" << std::endl;
    char test2[3];
    std::string testpass2;
    password = hash[1];
    // let's build the salt
    salt[0] = password[0];
    salt[1] = password[1];
    salt[2] = '\0';
    // let's get the hashed password
    for (int j2=2; j2<=password.length(); j2++){
        hashed[j2-2] = password[j2];
    }
    for (int i2 = 0; i2<alphabet.length(); i2++){
            for (int j2 = 0; j2<alphabet.length(); j2++){
                test2[0] = alphabet[i2];
                test2[1] = alphabet[j2];
                test2[2] = '\0';
                testpass2 = crypt(test2, salt);
                //std::cout << test2 << std::endl;
                if (testpass2 == password){
                    std::cout << "Finished checking 2 characters passwords - success" << std::endl;
                    std::cout << "Cracked password: " << test2 << " with the salt: " << salt << std::endl;
                    int stop_s=clock();
                    std::cout << "... and it only took " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << " seconds to crack." << std::endl;
                    return 0;
                    }
            }
    }
    std::cout << "Finished checking 2 characters passwords - no success" << std::endl;
    return 0;
}

int crack3(int argc, const char *hash[]){
    // case 3 chars password
    MyMutex.lock();
    std::lock_guard<std::mutex> lck (MyMutex, std::adopt_lock);
    std::cout << std::endl << "Start checking 3 characters passwords" << std::endl;
    char test3[4];
    std::string testpass3;
    password = hash[1];
    // let's build the salt
    salt[0] = password[0];
    salt[1] = password[1];
    salt[2] = '\0';
    // let's get the hashed password
    for (int j3=2; j3<=password.length(); j3++){
        hashed[j3-2] = password[j3];
    }
    for (int i3 = 0; i3<alphabet.length(); i3++){
            for (int j3 = 0; j3<alphabet.length(); j3++){
                    for (int k3 = 0; k3<alphabet.length(); k3++){
                        test3[0] = alphabet[i3];
                        test3[1] = alphabet[j3];
                        test3[2] = alphabet[k3];
                        test3[3] = '\0';
                        testpass3 = crypt(test3, salt);
                        //std::cout << test3 << std::endl;
                        if (testpass3 == password){
                            std::cout << "Finished checking 3 characters passwords - success" << std::endl;
                            std::cout << "Cracked password: " << test3 << " with the salt: " << salt << std::endl;
                            int stop_s=clock();
                            std::cout << "... and it only took " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << " seconds to crack." << std::endl;
                            return 0;
                        }
                    }
            }
    }
    std::cout << "Finished checking 3 characters passwords - no success" << std::endl;
    return 0;
}

int crack4(int argc, const char *hash[]){
    // case 4 chars password
    MyMutex.lock();
    std::lock_guard<std::mutex> lck (MyMutex, std::adopt_lock);
    std::cout << std::endl << "Start checking 4 characters passwords" << std::endl;
    char test4[6];
    std::string testpass4;
    password = hash[1];
    // let's build the salt
    salt[0] = password[0];
    salt[1] = password[1];
    salt[2] = '\0';
    // let's get the hashed password
    for (int j4=2; j4<=password.length(); j4++){
        hashed[j4-2] = password[j4];
    }
    for (int i4 = 0; i4<alphabet.length(); i4++){
            for (int j4 = 0; j4<alphabet.length(); j4++){
                    for (int k4 = 0; k4<alphabet.length(); k4++){
                        for (int l4 = 0; l4<alphabet.length(); l4++){
                            test4[0] = alphabet[i4];
                            test4[1] = alphabet[j4];
                            test4[2] = alphabet[k4];
                            test4[3] = alphabet[l4];
                            test4[4] = '\0';
                            testpass4 = crypt(test4, salt);
                            //std::cout << test4 << std::endl;
                            if (testpass4 == password){
                                std::cout << "Finished checking 4 characters passwords - success" << std::endl;
                                std::cout << "Cracked password: " << test4 << " with the salt: " << salt << std::endl;
                                int stop_s=clock();
                                std::cout << "... and it only took " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << " seconds to crack." << std::endl;
                                return 0;
                            } 
                        }
                }
        }
    }
    std::cout << "Finished checking 4 characters passwords - no success" << std::endl;
    return 0;
}

int main(int argc, const char *hash[]) {
    if (argc < 2) {
        std::cout << "Error. Doesn't look like a valid hash." << std::endl;
        return 1;
    }
    // here comes the fun part
    std::thread t4(crack1,argc,hash);
    std::thread t3(crack2,argc,hash);
    std::thread t2(crack3,argc,hash);
    std::thread t1(crack4,argc,hash);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    // why aren't you working properly????
    return 0;
}
