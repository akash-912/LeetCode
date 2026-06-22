class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> check(26,0);
        int n = cost.size();
        for(int i = 0; i < n; i++){
            char ch = s[i];
            check[ch-'a'] += cost[i]; 
        }
        long long total = 0;
        for(int i = 0;i<26;i++){
            total += check[i];
        }
        long long minNum = LLONG_MAX;
        for(int i = 0;i<26;i++){
            minNum = min(minNum,total-check[i]);
        }
        return minNum;
    }
};