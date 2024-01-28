#include <iostream>
#include <stack>
class MinStack{
    public:
    std::stack<int> array;
    std::stack<int> minArray;
    MinStack(){
    // Nothing to declare
    }
    void push(int val){
        array.push(val);
        

    }
    void pop(){

    }
    int top(){

    }
    int getMin(){
        
    }

};


int main(){
    std::cout <<"Hello World" <<std::endl;
    return 0;
}