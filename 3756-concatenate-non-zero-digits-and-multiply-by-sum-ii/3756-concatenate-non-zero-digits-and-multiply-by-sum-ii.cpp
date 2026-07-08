class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> power10(100001,1);
        for(int i = 1;i<100001;i++){
            power10[i] = (1LL*power10[i-1]*10) % MOD; 
        }
        int n = s.size();
        vector<int> digitSumUpto(n+1,0);
        vector<int> numberUpto(n+1,0);
        vector<int> nonZeroUpto(n+1,0);
        for(int i = 0;i<n;i++){
            int val = s[i] - '0';
            digitSumUpto[i+1] = digitSumUpto[i];
            nonZeroUpto[i+1] = nonZeroUpto[i];
            numberUpto[i+1] = numberUpto[i];
            if(val!=0){
                digitSumUpto[i+1] += val;
                numberUpto[i+1] = (1LL*numberUpto[i]*10 + val)%MOD;
                nonZeroUpto[i+1]++;
            }
        }

        vector<int> res;
        for(auto& it: queries){
            int l = it[0];
            int r = it[1];
            int len = nonZeroUpto[r+1] - nonZeroUpto[l];
            int sum = digitSumUpto[r+1] - digitSumUpto[l];
            int x = (numberUpto[r+1]-(1LL*numberUpto[l]*power10[len])%MOD + MOD)%MOD;
            res.push_back((1LL*x*sum)%MOD);

        }
        return res;
    }
};