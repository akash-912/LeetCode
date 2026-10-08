class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(') count++;
            else count--;

            if((count==1&&s[i]=='(')||count==0){
                continue;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};