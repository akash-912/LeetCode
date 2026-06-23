class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum = 0;
        int n = nums.size();
        int count = n/3;
        int m = 0;
        for(int i = n-2;i>0;i = i - 2){
            if(m==count) break;
            sum += nums[i];
            m++;
        }
        return sum;
    }
};