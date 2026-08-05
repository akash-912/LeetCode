class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;

        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                long long val = gcd(nums[i],nums[j]);
                long long pdt = ((long long) (1LL*nums[i]*nums[j]))/(val*val);
                ans = max(ans,pdt);
            }
        }
        return ans;
    }
};