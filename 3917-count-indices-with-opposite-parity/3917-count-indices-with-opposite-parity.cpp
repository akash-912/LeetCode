class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int numOdd = 0;
        int numEven = 0;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++){
            if(nums[i]%2==0) numEven++;
            else numOdd++;
        }
        for(int i = 0; i < n; i++){
            if(nums[i]%2==0){
                ans[i] = numOdd;
                numEven--;
            }else{
                ans[i] = numEven;
                numOdd--;
            }
        }
        return ans;
    }
};