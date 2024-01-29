#include <iostream>
#include <vector>

class Solution{
    public:
    std::vector<int> dailyTemperature(std::vector<int> &temperatures){
        std::vector<int> result(temperatures.size(), 0);
        std::vector<std::pair<int,int>> stack; // pair: <temperature, index>

        for (int i = 0; i < temperatures.size(); ++i){

            while(!stack.empty() && temperatures[i] > stack.back().first){
                int stackTemp = stack.back().first;
                int stackIndex = stack.back().second;
                stack.pop_back();
                result[stackIndex] = i - stackIndex;
            }
            stack.push_back({temperatures[i], i});
        }
        return result;
    }
};

int main(){
    Solution solution;
    std::vector<int> temperatures = {73,74,75,71,69,72,76,73};
    std::vector<int> result = solution.dailyTemperature(temperatures);
    for (int i: result){
        std::cout<<i<<std::endl;
    }
    return 0;


}