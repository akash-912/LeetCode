class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi_1 = INT_MIN,maxi_2 = INT_MIN;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]>maxi_1){
                maxi_2 = maxi_1;
                maxi_1 = nums[i];
            }else if(nums[i]>maxi_2){
                maxi_2 = nums[i];
            }
        }
        return (maxi_1 - 1)*(maxi_2 - 1);
    }
};