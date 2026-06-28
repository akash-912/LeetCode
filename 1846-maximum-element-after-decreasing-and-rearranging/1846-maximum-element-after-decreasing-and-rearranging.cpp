class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int max_element = 1;
        int start = 1;
        int n = arr.size();
        arr[0] = 1;
        for(int i = 1;i<n;i++){
            if(abs(arr[i]-arr[i-1])<=1){
                max_element = max(max_element,arr[i]);
            }else{
                arr[i] = arr[i-1] + 1;
                max_element = max(max_element,arr[i]);
            }
        }
        return max_element;
    }
};