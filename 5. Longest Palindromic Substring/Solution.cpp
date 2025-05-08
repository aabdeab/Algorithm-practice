class Solution {
    public:
        string longestPalindrome(string s) {
            if (s.empty()) return "";
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
                while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
                    p[i]++;
                if (i + p[i] > right) {
                    center = i;
                    right = i + p[i];
                }
            }
            int max_len = 0, center_index = 0;
            for (int i = 1; i < n - 1; ++i) {
                if (p[i] > max_len) {
                    max_len = p[i];
                    center_index = i;
                }
            }
            int start = (center_index - max_len) / 2; 
            return s.substr(start, max_len);
        }
    };
    