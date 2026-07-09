class Solution {
public:
    long long solve(int ind,vector<int>& nums,vector<int>& colors,vector<long long>& dp){
        if(ind<0) return 0;
        if(ind==0) return nums[ind];
        if(dp[ind]!=-1) return dp[ind];
        long long left = solve(ind-1,nums,colors,dp);
        long long right = 0;
        if(colors[ind]==colors[ind-1]) right = nums[ind] + solve(ind-2,nums,colors,dp);
        else right = nums[ind] + solve(ind-1,nums,colors,dp);
        return dp[ind] = max(left,right);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long> dp(n,-1);
        return solve(n-1,nums,colors,dp);
    }
};