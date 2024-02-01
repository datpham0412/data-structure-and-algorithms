#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class MinStack {
public:
    vector <int> array;
    vector <int> minArray;
    MinStack() {
        
    }
    
    void push(int val) {
        array.push_back(val);
        if(!minArray.empty() || minArray.back() > val){
            minArray.push_back(val);
        }
    }
    
    void pop() {
        array.pop_back();
        if(array.back() == minArray.back()){
            minArray.pop_back();
        }
    }
    
    int top() {
        array.back();
    }
    
    int getMin() {
        minArray.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){

}