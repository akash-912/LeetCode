class Solution {
public:
    int popcount(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1); 
            count++;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return true;
        int prevMax = 0;
        int currMax = nums[0];
        int currMin = nums[0];
        int currbits = popcount(nums[0]);
        for(int i = 1;i<n;i++){
            int bits = popcount(nums[i]);
            if(bits==currbits){
                currMax = max(nums[i],currMax);
                currMin = min(nums[i],currMin);
            }else{
                if(prevMax>currMin){
                    return false;
                }
                prevMax = currMax;
                currMin = nums[i];
                currMax = nums[i];
                currbits = bits;
            }
        }
        return prevMax<=currMin;
    }
};