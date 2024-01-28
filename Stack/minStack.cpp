#include <iostream>
#include <stack>
#include <cassert>
class MinStack{
    public:
    std::stack<int> array;
    std::stack<int> minArray;
    MinStack(){
    // Nothing to declare
    }
    void push(int val){
        array.push(val);
        if (minArray.empty() || val <= minArray.top()){
            minArray.push(val);
        }

    }
    void pop(){
        if(minArray.top() == array.top()){
            minArray.pop();
        }
        array.pop();
    }
    int top(){
        return array.top();

    }
    int getMin(){
        return minArray.top();
    }

};


int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    assert(minStack.getMin() == -3); // Should be -3
    std::cout << "getMin() returned " << minStack.getMin() << " after push(-3), as expected." << std::endl;

    minStack.pop();

    assert(minStack.top() == 0); // Top should now be 0
    std::cout << "top() returned " << minStack.top() << " after pop(), as expected." << std::endl;

    assert(minStack.getMin() == -2); // Minimum should now be -2
    std::cout << "getMin() returned " << minStack.getMin() << " after pop(), as expected." << std::endl;

    return 0;
}
