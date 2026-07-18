class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxNum = 0;
        int n = nums.size();
        int minNum = INT_MAX;
        for(int i = 0;i<n;i++){
            minNum = min(minNum,nums[i]);
            maxNum = max(maxNum,nums[i]);
        }
        return gcd(minNum,maxNum);
    }
};