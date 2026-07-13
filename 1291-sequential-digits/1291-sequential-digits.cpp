class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;
        
        int lowLen = to_string(low).length();
        int highLen = to_string(high).length();
        for (int len = lowLen; len <= highLen; ++len) {
            for (int i = 0; i <= 9 - len; ++i) {
                int num = stoi(digits.substr(i, len));
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};