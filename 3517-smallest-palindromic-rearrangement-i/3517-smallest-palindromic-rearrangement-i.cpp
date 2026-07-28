class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a']++;
        }

        string first_half = "";
        string middle = "";
        
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                middle = string(1, i + 'a');
            }
            first_half += string(count[i] / 2, i + 'a');
        }

        string result = first_half + middle;
        
        reverse(first_half.begin(), first_half.end());
        result += first_half;
        
        return result;
    }
};