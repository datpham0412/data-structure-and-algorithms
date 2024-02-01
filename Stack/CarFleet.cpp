#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int, double>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }
        sort(pair.begin(), pair.end(), std::greater<>());

        std::vector<double> stack;
        for (auto p : pair) {
            if (stack.empty() || p.second > stack.back()) {
                stack.push_back(p.second);
            }
        }

        return stack.size();
    }
};

int main() {
    Solution solution;
    int target = 12;
    std::vector<int> position = {10, 8, 0, 5, 3};
    std::vector<int> speed = {2, 4, 1, 1, 3};

    int result = solution.carFleet(target, position, speed);
    std::cout << "Number of car fleets: " << result << std::endl;

    return 0;
}
