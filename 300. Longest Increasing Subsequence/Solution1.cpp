class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> sorted = nums;
            sort(sorted.begin(), sorted.end());
            sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
            int n = sorted.size();
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++) {
                mp[sorted[i]] = i + 1;
            }
    
            vector<int> vec(n + 2, 0);
            for (int i = 0; i < nums.size(); i++) {
                int rang = mp[nums[i]];
                int upper = 0; 
                for (int j = 1; j < rang; j++) {
                    upper = max(upper, vec[j]);
                }
                vec[rang] = max(vec[rang], upper + 1);
            }
    
            int result = 0;
            for (int val : vec) {
                result = max(result, val);
            }
            return result;
        }
    };
    