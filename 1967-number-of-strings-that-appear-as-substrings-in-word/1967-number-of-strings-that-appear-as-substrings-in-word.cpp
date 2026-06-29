class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& p : patterns) {
            // string::npos means the substring was not found
            if (word.find(p) != string::npos) {
                count++;
            }
        }
        return count;
    }
};