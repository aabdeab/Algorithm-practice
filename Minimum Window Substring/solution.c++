#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string minWindow(string s, string t) {
            if (s.size() < t.size()) return "";
    
            int target[128] = {0}; 
            int window[128] = {0}; 
    
            for (char c : t) target[c]++;
    
            int required = 0;
            for (int i = 0; i < 128; ++i)
                if (target[i] > 0) required++;
    
            int formed = 0;
            int left = 0, right = 0;
            int minLen = INT_MAX, start = 0;
    
            while (right < s.size()) {
                char c = s[right];
                window[c]++;
                if (target[c] > 0 && window[c] == target[c])
                    formed++;
    
                while (formed == required) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        start = left;
                    }
    
                    char d = s[left];
                    window[d]--;
                    if (target[d] > 0 && window[d] < target[d])
                        formed--;
                    left++;
                }
    
                right++;
            }
    
            return minLen == INT_MAX ? "" : s.substr(start, minLen);
        }
    };
int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t) << endl; 
    return 0;

}
    