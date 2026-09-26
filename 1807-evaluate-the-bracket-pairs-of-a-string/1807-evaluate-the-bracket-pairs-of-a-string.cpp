class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mpp;
        for(int i = 0;i<knowledge.size();i++){
            mpp[knowledge[i][0]] = knowledge[i][1];
        }
        int n = s.size();
        string ans = "";
        for(int i = 0;i<n;i++){
            if(s[i]!='('){
                ans += s[i];
            }
            else{
                i++;
                string temp = "";
                while(i<n&&s[i]!=')'){
                    temp += s[i];
                    i++;
                }
                if(mpp.find(temp)!=mpp.end()){
                    ans += mpp[temp];
                }else{
                    ans += '?';
                }

            }
        }
        return ans;
    }
};