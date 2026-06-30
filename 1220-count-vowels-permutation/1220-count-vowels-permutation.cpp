class Solution {
public:
    int mod = 1e9+7;
    int getVowel(char ch){
        if(ch=='a') return 0;
        else if(ch=='e') return 1;
        else if(ch=='i') return 2;
        else if(ch=='o') return 3;
        else return 4;
    }
    int solve(int idx,char ch,int& n,vector<vector<int>>& dp){
        if(idx==n){
            return 1;
        }
        int count = 0;
        int vidx = getVowel(ch);
        if(dp[idx][vidx]!=-1) return dp[idx][vidx];
        if(ch=='a'){
            count = (count + solve(idx+1,'e',n,dp))%mod;
        }
        else if(ch=='e'){
            count = (count + solve(idx+1,'a',n,dp))%mod;
            count = (count + solve(idx+1,'i',n,dp))%mod;
        }else if(ch=='i'){
            count = (count + solve(idx+1,'a',n,dp))%mod;
            count = (count + solve(idx+1,'e',n,dp))%mod;
            count = (count + solve(idx+1,'o',n,dp))%mod;
            count = (count + solve(idx+1,'u',n,dp))%mod;
        }else if(ch=='o'){
            count = (count + solve(idx+1,'i',n,dp))%mod;
            count = (count + solve(idx+1,'u',n,dp))%mod;
        }else if(ch=='u'){
            count = (count + solve(idx+1,'a',n,dp))%mod;
        }
        return dp[idx][vidx] = count;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        char vowels[5] = {'a','e','i','o','u'};
        int result = 0;
        for(char ch:vowels){
            result = (result + solve(1,ch,n,dp))%mod;
        }
        return result;
    }
};