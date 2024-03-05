#include <iostream>

void swapValue(int &x, int &y){
    int temp = x;
    x = y; 
    y = temp;
}
using namespace std;
int main(){
    int x = 10;
    int y = 20;
    swapValue(x, y);
    cout << x << "," << y << endl;
}