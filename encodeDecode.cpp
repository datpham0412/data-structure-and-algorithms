#include <iostream>
#include <vector>
#include <string>
class Solution{
    public:
    std::string encode(std::vector<std::string> strs){
        std::string result = "";
        for (std::string str:strs){
            result += std::to_string(str.size()) + "#" + str;
        }
        return result;
    }
    std::vector<std::string> decode(std::string str){
        std::vector<std::string> result = {};
        size_t i = 0;
        while(i < str.size()){
            size_t j = i;
            while (str[j] != '#'){
                j++;   
            }
            int length_str = std::stoi(str.substr(i, j - i));
            i = j + 1;
            result.push_back(str.substr(i, length_str));
            i  += length_str;
        }
        return result;
    }
};

int main(){
    Solution solution;
    std::vector<std::string> strs = {"lint", "code", "love", "you"};
    std::string after_encode = solution.encode(strs);
    std::cout<<after_encode<<std::endl;
    std::vector<std::string> after_decode = solution.decode(after_encode);
    std::cout <<"Decode ";
    for (std::string str: after_decode){
        std::cout <<str << " ";
    }
    return 0;
}