#include <iostream>
#include <unordered_map>
#include <string>

class Solution{
    public:
    bool validAnagram(std::string &s, std::string &t){
        std::unordered_map<char, int> s_freq;
        std::unordered_map<char, int> t_freq;
        for (char c : s){
            s_freq[c] ++;
        }
        for (char c : t){
            t_freq[c] ++;
        }
        return s_freq == t_freq;
    }
};


int main(){
    Solution solution;
    std::string s = "car";
    std::string t = "racq";
    bool result = solution.validAnagram(s,t);
    std::cout<<std::boolalpha<<result<<std::endl;
}