class Solution {
public:
    int n;
    int MOD = 1e9 + 7;
    bool isValid(int i, int j, vector<string>& board){
        return (i>=0&&i<n&&j>=0&&j<n&&board[i][j]!='X');
    }
    int getIntFromChar(char ch){
        return ch != 'S' ? ch - '0' : 0;
    }
    pair<int,int> solve(int i ,int j,vector<string>& board,vector<vector<pair<int,int>>>& dp){
        if(board[i][j]=='E'){
            return {0,1};
        }
        if(board[i][j]=='X'){
            return {0,0};
        }
        if(dp[i][j].first!=-1&&dp[i][j].second!=-1) return dp[i][j];
        int upScore = 0, upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;

        char ch = board[i][j];
        if(isValid(i-1,j,board)){
            auto [score,paths] = solve(i-1,j,board,dp);
            upScore = score;
            upPaths = paths;
            if(upPaths>0){
                upScore += getIntFromChar(ch);
            }
        }
        if(isValid(i,j-1,board)){
            auto [score,paths] = solve(i,j-1,board,dp);
            leftScore = score;
            leftPaths = paths;
            if(leftPaths>0){
                leftScore += getIntFromChar(ch);
            }
        }
        if(isValid(i-1,j-1,board)){
            auto [score,paths] = solve(i-1,j-1,board,dp);
            diagScore = score;
            diagPaths = paths;
            if(diagPaths>0){
                diagScore += getIntFromChar(ch);
            }
        }
        int bestScore = 0, bestPaths = 0;
        if(upScore==leftScore&&leftScore==diagScore){
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        }
        else if(upScore==leftScore){
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;
            if(diagScore>bestScore||(diagScore==bestScore&&diagPaths>bestPaths)){
                bestScore = diagScore; bestPaths = diagPaths;
            }
        }
        else if(leftScore==diagScore){
            bestScore = leftScore;
            bestPaths = diagPaths + leftPaths;
            if(upScore>bestScore||(upScore==bestScore&&upPaths>bestPaths)){
                bestScore = upScore; bestPaths = upPaths;
            }
        }else{
            bestScore = upScore;bestPaths = upPaths;
            if(leftScore>bestScore||(leftScore==bestScore&&leftPaths>bestPaths)){
                bestScore = leftScore; bestPaths = leftPaths;
            }
            if(diagScore>bestScore||(diagScore==bestScore&&diagPaths>bestPaths)){
                bestScore = diagScore; bestPaths = diagPaths;
            }
        }
        return dp[i][j] = {bestScore,bestPaths%MOD};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{0,0}));
        dp[0][0] = {0,1};
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==0&&j==0) continue;
                int upScore = 0, upPaths = 0;
                int leftScore = 0, leftPaths = 0;
                int diagScore = 0, diagPaths = 0;

                char ch = board[i][j];
                if(isValid(i-1,j,board)){
                    auto [score,paths] = dp[i-1][j];
                    upScore = score;
                    upPaths = paths;
                    if(upPaths>0){
                        upScore += getIntFromChar(ch);
                    }
                }
                if(isValid(i,j-1,board)){
                    auto [score,paths] = dp[i][j-1];
                    leftScore = score;
                    leftPaths = paths;
                    if(leftPaths>0){
                        leftScore += getIntFromChar(ch);
                    }
                }
                if(isValid(i-1,j-1,board)){
                    auto [score,paths] = dp[i-1][j-1];
                    diagScore = score;
                    diagPaths = paths;
                    if(diagPaths>0){
                        diagScore += getIntFromChar(ch);
                    }
                }
                int bestScore = 0, bestPaths = 0;
                if(upScore==leftScore&&leftScore==diagScore){
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths + diagPaths;
                }
                else if(upScore==leftScore){
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths;
                    if(diagScore>bestScore||(diagScore==bestScore&&diagPaths>bestPaths)){
                        bestScore = diagScore; bestPaths = diagPaths;
                    }
                }
                else if(leftScore==diagScore){
                    bestScore = leftScore;
                    bestPaths = diagPaths + leftPaths;
                    if(upScore>bestScore||(upScore==bestScore&&upPaths>bestPaths)){
                        bestScore = upScore; bestPaths = upPaths;
                    }
                }else{
                    bestScore = upScore;bestPaths = upPaths;
                    if(leftScore>bestScore||(leftScore==bestScore&&leftPaths>bestPaths)){
                        bestScore = leftScore; bestPaths = leftPaths;
                    }
                    if(diagScore>bestScore||(diagScore==bestScore&&diagPaths>bestPaths)){
                        bestScore = diagScore; bestPaths = diagPaths;
                    }
                }
                dp[i][j] = {bestScore,bestPaths%MOD};
            }
        }
        pair<int,int> result = dp[n-1][n-1];
        return {result.first,result.second};
    }
};