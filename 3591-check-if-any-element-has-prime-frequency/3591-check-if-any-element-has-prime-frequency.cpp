class Solution {
public:
    bool isPrime(int num){
        if(num<=1) return false;
        for(int i = 2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto& it: nums){
            mpp[it]++;
        }
        for(auto& it: mpp){
            if(isPrime(it.second)){
                return true;
            }
        }
        return false;
    }
};