class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long> dp(n,0);
        dp[0] = nums[0];
        for(int ind = 1;ind<n;ind++){
            long long left = dp[ind-1];
            long long right = 0;
            if(colors[ind]==colors[ind-1]) right = nums[ind] + ((ind >= 2) ? dp[ind-2] : 0);
            else right = nums[ind] + dp[ind-1];
            dp[ind] = max(left,right);
        }
        return dp[n-1];
    }
};