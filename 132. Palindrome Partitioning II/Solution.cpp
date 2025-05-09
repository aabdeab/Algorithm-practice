class Solution {
    public:
        vector<int> manacher(string s) {
            if (s.empty()) return {};
            string t = "^";
            for (char c : s) {
                t += "#" + string(1, c);
            }
            t += "#$";
            int n = t.size();
            vector<int> p(n, 0);
            int center = 0, right = 0;
            
            for (int i = 1; i < n - 1; ++i) {
                int mirror = 2 * center - i;
                if (i < right) {
                    p[i] = min(right - i, p[mirror]);
                }
                while (t[i + (1 + p[i])] == t[i - (1 + p[i])]) {
                    p[i]++;
                }
                if (i + p[i] > right) {
                    center = i;
                    right = i + p[i];
                }
            }
            return p;
        }
    
        int minCut(string s) {
            int n = s.size();
            if (n <= 1) return 0;
            
            vector<int> p = manacher(s);
            vector<int> dp(n);
            iota(dp.begin(), dp.end(), 0); // Initialize dp[i] = i
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j <= i; ++j) {
                    int left = 2 * j + 2;
                    int right_t = 2 * i + 2;
                    int center = (left + right_t) / 2;
                    int required_radius = i - j;
                    
                    if (center >= 0 && center < p.size() && p[center] >= required_radius) {
                        if (j > 0) {
                            dp[i] = min(dp[i], dp[j - 1] + 1);
                        } else {
                            dp[i] = 0;
                        }
                    }
                }
            }
            
            return dp[n - 1];
        }
    };