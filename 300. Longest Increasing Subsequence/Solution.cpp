#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int LCS(vector<int>& nums, vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
            if (i < 0 || j < 0) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            
            if (nums[i] == arr[j]) {
                return dp[i][j] = 1 + LCS(nums, arr, i - 1, j - 1, dp);
            }
    
            int op1 = LCS(nums, arr, i - 1, j, dp);
            int op2 = LCS(nums, arr, i, j - 1, dp);
            return dp[i][j] = max(op1, op2);
        }
    
        int lengthOfLIS(vector<int>& nums) {
            vector<int> arr = nums;
            sort(arr.begin(), arr.end());
            arr.erase(unique(arr.begin(), arr.end()), arr.end()); 
            int n = nums.size();
            int m = arr.size();
            vector<vector<int>> dp(n, vector<int>(m, -1));
            return LCS(nums, arr, n - 1, m - 1, dp);
        }
    };
    