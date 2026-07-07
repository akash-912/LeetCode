class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        while(n>0){
            int digit = n%10;
            n = n/10;
            if(digit!=0){
                sum += digit;
                x = x*10 + digit;
            }
        }
        long long res = 0;
        while(x>0){
            int digit = x%10;
            x = x/10;
            res = res*10 + digit;
        }
        return res*sum;
    }
};