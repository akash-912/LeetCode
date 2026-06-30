class Solution {
public:
    int mod = 1e9+7;
    int countVowelPermutation(int n) {
        long long a = 1,e = 1,i = 1,o = 1,u = 1;
        for(int j = 2;j<=n;j++){
            long long na = e%mod;
            long long ne = (a+i)%mod;
            long long ni = (a+e+o+u)%mod;
            long long no = (i+u)%mod;
            long long nu = (a)%mod;
            a = na;
            e = ne;
            i = ni;
            o = no;
            u = nu;
        }
        return (a+e+i+o+u)%mod;
    }
};