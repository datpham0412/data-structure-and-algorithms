#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution{
    public:
    string encode(vector<string> &strs){
        string result = "";
        for (string i:strs){
            result += std::to_string(i.size()) + "#" + i;
        }
        return result;
    }
    vector<string> decode(string str){
        int i = 0;
        vector<string> result = {};
        while(i < str.size()){
            int j = i;
            while(str[j] != '#'){
                j++;
            }
            int length = stoi(str.substr(i, j - i));
            i = j+1;
            result.push_back(str.substr(i, length));
            i += length;
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