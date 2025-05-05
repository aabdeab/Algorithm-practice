#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int Dis(const string &word1, const string &word2, int i, int j, vector<vector<int>> &dp) {
            if (i < 0) return j+1 ;
            if (j < 0) return i+1 ;
            
            if (dp[i][j] != -1) return dp[i][j];
    
            if (word1[i] == word2[j]) {
                return dp[i][j] = Dis(word1, word2, i - 1, j - 1, dp);
            }
    
            int insertOp = Dis(word1, word2, i, j - 1, dp);
            int deleteOp = Dis(word1, word2, i - 1, j, dp);
            int replaceOp = Dis(word1, word2, i - 1, j - 1, dp);
    
            return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
    
        int minDistance(string word1, string word2) {
            int m = word1.size();
            int n = word2.size();
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return Dis(word1, word2, m - 1, n - 1, dp);
        }
    };
    