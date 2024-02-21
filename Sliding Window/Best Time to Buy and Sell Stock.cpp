#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 0;
        int maxProfit = 0;
        while (right < prices.size()){
            int profit = 0;
            if(prices[right] > prices[left]){
                profit = prices[right] - prices[left];
                maxProfit = max(profit, maxProfit);
                right++;
            }else{
                left = right;
                right++;
            }
        }
        return maxProfit;
    }
};

int main(){
    Solution solution;
    vector<int> prices = {7,1,5,3,6,4};
    int profit = solution.maxProfit(prices);
    cout << profit << endl;
}