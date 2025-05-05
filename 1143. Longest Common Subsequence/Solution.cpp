#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int Dis(const string &word1, const string &word2, int i, int j, vector<vector<int>> &dp) {
            if (i < 0) return j + 1;
            if (j < 0) return i + 1;
            
            if (dp[i][j] != -1) return dp[i][j];
            if (word1[i] == word2[j]) {
                return dp[i][j] = Dis(word1, word2, i - 1, j - 1, dp);
            }
    
            int insertOp = Dis(word1, word2, i, j - 1, dp);
            int deleteOp = Dis(word1, word2, i - 1, j, dp);
    
            return dp[i][j] = 1 + min(insertOp, deleteOp);
        }
        int longestCommonSubsequence(string text1, string text2) {
            int len1 = text1.size();
            int len2 = text2.size();
            vector<vector<int>> vec(len1,vector<int>(len2,-1));
            return (len1+len2-Dis(text1,text2,len1-1,len2-1,vec))/2;
            
        }
    };