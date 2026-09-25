class Solution {
public:
    int solve(int rem, vector<int>& dp){
        if (rem == 0) return 0;
        if (dp[rem] != -1) return dp[rem];
        
        int min_days = 1e9;
        
        for (int k = 1; k * (k + 1) / 2 <= rem; ++k) {
            int points = k * (k + 1) / 2; 
            int days = k + 1;             
            
            min_days = min(min_days, days + solve(rem - points, dp));
        }
        
        return dp[rem] = min_days;
    }
    int minDays(int n) {
        if(n==0) return 0;
        vector<int> dp(n+1,-1);
        return solve(n,dp) - 1;
    }
};