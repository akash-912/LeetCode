class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long a = 0;
        for(long long i = 1000;i<=n;i=i*1000){
            a += (n - i + 1);
        }
        return a;

    }
};