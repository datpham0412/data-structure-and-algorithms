#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        // if (m.find(key) == m.end()) {
        if (!m.count(key)) {
            return "No values found";
        }
        
        int low = 0;
        int high = m[key].size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (m[key][mid].second < timestamp) {
                low = mid + 1;
            } else if (m[key][mid].second > timestamp) {
                high = mid - 1;
            } else {
                return m[key][mid].first;
            }
        }
        
        if (high >= 0) {
            return m[key][high].first;
        }
        return "To small timestamp";
    }
private:
    unordered_map<string, vector<pair<string, int>>> m;
};

int main() {
    // Instantiate TimeMap object
    TimeMap* timeMap = new TimeMap();

    // Test case operations
    timeMap->set("apple", "juice", 2);    // Set "apple" = "juice" at timestamp 2
    timeMap->set("apple", "cider", 10);   // Set "apple" = "cider" at timestamp 10

    cout << timeMap->get("apple", 5) << endl;   // Output should be "juice"
    cout << timeMap->get("apple", 10) << endl;  // Output should be "cider"
    timeMap->set("apple", "pie", 15);           // Set "apple" = "pie" at timestamp 15

    cout << timeMap->get("apple", 2) << endl;   // Output should be "juice"
    cout << timeMap->get("apple", 10) << endl;  // Output should be "cider"
    cout << timeMap->get("apple", 20) << endl;  // Output should be "pie"
    cout << timeMap->get("apple", 1) << endl;  // Outputs: "", because there are no timestamps <= 1 for "apple".
    cout << timeMap->get("banana", 5) << endl;  // Outputs: "", because "banana" was never set.


    // Clean up
    delete timeMap;
    return 0;
}
