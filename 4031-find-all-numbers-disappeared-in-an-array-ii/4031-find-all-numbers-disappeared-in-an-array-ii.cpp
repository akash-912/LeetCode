class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> output;
        int next_expected = lower;
        for(int i = 0;i<n;i++){
            if(next_expected>upper){
                break;
            }

            if(next_expected==nums[i]){
                next_expected++;
            }else if(next_expected<nums[i]){
                output.push_back({next_expected,min(upper,nums[i]-1)});
                next_expected = nums[i] + 1;
            }
        }
        if(next_expected<=upper){
            output.push_back({next_expected,upper});
        }
        return output;
    }
};