struct Stack{
    int * stack;
    int size;
    int topstack = -1;
    
    Stack(int s);
    void push(int v);
    int pop();
    int top();
};