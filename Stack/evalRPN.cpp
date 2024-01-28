#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::vector<int> stack;  // Even though you asked for a vector<string>, we need a vector<int> for arithmetic operations
        for (const std::string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = stack.back();
                stack.pop_back();
                int left = stack.back();
                stack.pop_back();
                if (token == "+") {
                    stack.push_back(left + right);
                } else if (token == "-") {
                    stack.push_back(left - right);
                } else if (token == "*") {
                    stack.push_back(left * right);
                } else if (token == "/") {
                    // In C++, the division of two integers results in integer division
                    stack.push_back(left / right);
                }
            } else {
                // Directly pushing the integer converted from string
                stack.push_back(std::stoi(token));
            }
        }
        return stack.back();
    }
};

int main() {
    Solution solution;
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    std::cout << "Result: " << solution.evalRPN(tokens) << std::endl; // Should output 9
    return 0;
}
