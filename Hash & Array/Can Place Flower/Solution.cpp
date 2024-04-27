#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i+1] == 0)) {
                count++; // A flower can be planted here.
                flowerbed[i] = 1; // Plant a flower here.
                i++; // Move to the next next position.
            }
        }
        return count >= n;
    }
};

int main(){
    Solution solution;
    vector <int> flowerbed = {0,0,1,0,0};
    int n = 2;
    bool result = solution.canPlaceFlowers(flowerbed, n);
    cout << (result ? "true" : "false");
    return 0;
}