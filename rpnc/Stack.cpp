#include "Stack.h"
Stack::Stack(int s){
    stack = new int[s];
    size = s;
}
void Stack::push(int v){
    topstack += 1;
    stack[topstack] = v;
}
int Stack::pop(){
    topstack -= 1;
    return stack[topstack + 1];
}
int Stack::top(){
    return stack[topstack];
}