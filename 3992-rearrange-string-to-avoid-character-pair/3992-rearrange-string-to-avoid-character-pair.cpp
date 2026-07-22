class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string t = "";
        int xcount = 0;
        int ycount = 0;
        for(auto ch: s){
            if(ch!=x&&ch!=y){
                t += ch;
            }
            else if(ch==x){
                xcount++;
            }else{
                ycount++;
            }
        }
        while(ycount--){
            t += y;
        }
        while(xcount--){
            t += x;
        }
        return t;
    }
};