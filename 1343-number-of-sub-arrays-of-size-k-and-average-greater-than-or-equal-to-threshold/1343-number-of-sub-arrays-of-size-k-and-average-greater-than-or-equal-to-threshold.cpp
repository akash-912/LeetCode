class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int m = k*threshold;
        int cnt = 0;
        int sum = 0;
        int n = arr.size();
        for(int i = 0;i<k;i++){
            sum += arr[i];
        }
        if(sum>=m) cnt++;
        int l = 0;
        int r = k;
        while(r<n){
            sum -= arr[l];
            sum += arr[r];
            if(sum>=m) cnt++;
            l++;
            r++;
        }
        return cnt;
    }
};