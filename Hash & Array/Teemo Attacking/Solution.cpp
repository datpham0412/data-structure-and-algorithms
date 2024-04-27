// Time: O(n)
// SPace: O(1)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // 1,2, 4, 5 --> 4 seconds
         
         if (timeSeries.size() == 1){
            return duration;
         }
         int counter = duration;
        for (int i = 0; i < timeSeries.size() - 1; i ++){
            if (timeSeries[i + 1] - timeSeries[i] >= duration){
                counter += duration;
            }
            else{
                counter += (timeSeries[i+1] - timeSeries[i]);
            }
        }
        return counter;
    }
};

int main(){
    Solution solution;
    vector <int> timeSeries = {1, 4, 5}; // result 1,2,3,4,5,6,7 = 7 seconds
    int duration = 3;
    int result = solution.findPoisonedDuration(timeSeries, duration);
    cout << result;
    return 0;
}