#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";

        vector<int> t_freq(128, 0);
        for (char c : t) {
            t_freq[c]++;
        }

        int required = t.size(); 
        int l = 0, r = 0;
        int min_len = INT_MAX;
        int start_idx = 0;

        while (r < s.size()) {
            if (t_freq[s[r]] > 0) {
                required--;
            }
            t_freq[s[r]]--;
            r++;

            while (required == 0) {
                if (r - l < min_len) {
                    min_len = r - l;
                    start_idx = l;
                }

                t_freq[s[l]]++;
                if (t_freq[s[l]] > 0) { 
                    required++;
                }
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};