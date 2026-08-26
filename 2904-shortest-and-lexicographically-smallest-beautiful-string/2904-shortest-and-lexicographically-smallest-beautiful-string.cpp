class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = s + "#";
        int n  = s.size();
        for(int i = 0;i<n;i++){
            int count = 0;
            string t = "";
            for(int j = i;j<n;j++){
                t += s[j];
                if(s[j]=='1'){
                    count++;
                } 
                if(count==k){
                    if(ans.length()>t.length()){
                        ans = t;
                    }else if(ans.length()==t.length()&&t<ans){
                        ans = t;
                    }
                    break;
                }
            }
        }
        return ans==s+'#'?"":ans;
    }
};