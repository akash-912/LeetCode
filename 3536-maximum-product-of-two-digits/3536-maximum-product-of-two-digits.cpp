class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        int k = s.size();
        int a = s[k-1] - '0';
        int b = s[k-2] - '0';
        return a*b;
    }
};