#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, vector<int>> map1;
        unordered_map<char, vector<int>> map2;
        for (int i = 0; i < s.size(); i++)
        {
            map1[s[i]].push_back(i);
            map2[t[i]].push_back(i);
            if (map1[s[i]] != map2[t[i]])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    // Test cases
    string s1 = "egg", t1 = "add";
    string s2 = "foo", t2 = "bar";
    string s3 = "paper", t3 = "title";
    string s4 = "abca", t4 = "zbaa";

    // Running and displaying results for each test case
    cout << "Is '" << s1 << "' isomorphic to '" << t1 << "'? " << (solution.isIsomorphic(s1, t1) ? "Yes" : "No") << endl;
    cout << "Is '" << s2 << "' isomorphic to '" << t2 << "'? " << (solution.isIsomorphic(s2, t2) ? "Yes" : "No") << endl;
    cout << "Is '" << s3 << "' isomorphic to '" << t3 << "'? " << (solution.isIsomorphic(s3, t3) ? "Yes" : "No") << endl;
    cout << "Is '" << s4 << "' isomorphic to '" << t4 << "'? " << (solution.isIsomorphic(s4, t4) ? "Yes" : "No") << endl;

    return 0;
}
