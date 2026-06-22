class Solution {
public:
    bool isPrime(int num){
        if(num<2) return false;
        int flag = true;
        for(int i = 2;i*i<=num;i++){
            if(num%i==0){
                flag = false;
            }
        }
        return flag;
    }
    int sumOfPrimesInRange(int n) {
        int rev = 0;
        int num = n;
        while(num>0){
            rev = rev*10 + num%10;
            num = num/10;
        }
        int sum = 0;
        for(int i = min(n,rev);i<=max(n,rev);i++){
            if(isPrime(i)){
                sum += i;
            }
        }
        return sum;
    }
};