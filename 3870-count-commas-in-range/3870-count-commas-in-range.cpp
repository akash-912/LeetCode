class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        int ans = n%1000;
        int rem = n/1000;
        int k = (rem - 1)*1000;
        return ans + 1 + k;
    }
};