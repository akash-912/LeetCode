class Solution {
public:
    string solve(int ind,string str,int n,unordered_map<string,int>& mpp){
        if(ind==n){
            if(mpp.find(str)==mpp.end()){
                return str;
            }
            return "";
        }

        string res1 = solve(ind+1,str+'1',n,mpp);
        if(res1!="") return res1;
        string res2 = solve(ind+1,str+'0',n,mpp);
        if(res2!="") return res2;
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> mpp;
        int n = nums.size();
        for(auto str: nums){
            mpp[str]++;
        }
        string ans = solve(0,"",n,mpp);
        return ans;
    }
};