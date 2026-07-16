class Solution {
public:
    long long gcd(long long a,long long b){
        while(a>0&&b>0){
            if(a>b) a = a % b;
            else b = b % a;
        }
        if(a==0) return b;
        else return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> mxi(n,0);
        vector<long long> prefixGcd(n,0);
        long long maxNum = LLONG_MIN;
        for(int i = 0;i<n;i++){
            mxi[i] = max(maxNum,(long long) nums[i]);
            maxNum = mxi[i];
        }
        for(int i = 0;i<n;i++){
            prefixGcd[i] = gcd(mxi[i],(long long)nums[i]);    
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long sum = 0;
        int i = 0;
        int j = n-1;
        while(i<j){
            sum += gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};