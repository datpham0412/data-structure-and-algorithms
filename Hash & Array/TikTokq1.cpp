#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> result (vector<int> &a, vector<int> &b){
    unordered_set<int> setB(b.begin(), b.end());
    vector<int> res;
    for(int i: a){
        if(!setB.count(i)){
            res.push_back(i);
        }
    }
    return res;
    }
int main() {
    vector<int> a = {4,3,3,5,10,9,7,8}; // expected: {4,3,3,10,9}
    vector<int> b = {5,7,8};
    vector<int> res = result(a,b);
    for (int i: res){
        cout << i << endl;
    }
}