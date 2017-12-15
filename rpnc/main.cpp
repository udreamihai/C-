/**
 * File: main.cpp
 * Author: Mihai Udrea
 * Date: 09-11-2017
 * Desc:
 * Copyright: University of West of England 2017
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"
//#include <stack>

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
    Stack stack(256);
    std::cout << "Enter your expression (example: 10 10 + 20 20 + * =): " << std::endl;
	while(true){
		std::string expression;
		std::cin >> expression; // get user input
		if(expression == "+"){
            // case add
			int tmp1 = stack.top();
			stack.pop();
			int tmp2 = stack.top();
			stack.pop();
			stack.push(tmp1 + tmp2);
		}
		else if(expression == "-"){
            // case substract
			int tmp1 = stack.top();
			stack.pop();
			int tmp2 = stack.top();
			stack.pop();
			stack.push(tmp1 - tmp2);

		}
		else if(expression == "*"){
            // case multiply
			int tmp1 = stack.top();
			stack.pop();
			int tmp2 = stack.top();
			stack.pop();
			stack.push(tmp1 * tmp2);

		}
		else if(expression == "/"){
            // case divide
			int tmp1 = stack.top();
			stack.pop();
			int tmp2 = stack.top();
			stack.pop();
			stack.push(tmp1 / tmp2);

		}
		else if(expression == "="){
            // print the result
            std::cout << "Result: " << stack.top() << std::endl;
            stack.pop();
            break;
		}
		else{
            // look for integers in the expression and push them into the stack
			int tmp3;
			std::stringstream ss(expression);
    		ss >> tmp3;
	        stack.push(tmp3);
		}
	}
	}