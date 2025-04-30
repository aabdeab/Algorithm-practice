#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int power10(int exp) {
            int res = 1;
            while (exp--) res *= 10;
            return res;
        }
    
        string intToRoman(int num) {
            string n = to_string(num);
            int taille = n.size();
            string result = "";
            unordered_map<int, char> mp;
            mp[1] = 'I'; mp[5] = 'V'; mp[10] = 'X'; mp[50] = 'L';
            mp[100] = 'C'; mp[500] = 'D'; mp[1000] = 'M';
    
            for (int i = 0; i < taille; i++) {
                int digit = n[i] - '0';
                int base = power10(taille - i - 1);
                if (digit == 4) {
                    result += string(1, mp[base]) + string(1, mp[5 * base]);
                } else if (digit == 9) {
                    result += string(1, mp[base]) + string(1, mp[10 * base]);
                } else {
                    if (digit >= 5) {
                        result += string(1, mp[5 * base]);
                        digit -= 5;
                    }
                    while (digit > 0) {
                        result += string(1, mp[base]);
                        digit--;
                    }
                }
            }
            return result;
        }
    };
int main() {
    Solution sol;
    int num = 1994; // Example input
    cout << sol.intToRoman(num) << endl; // Output: MCMXCIV
    return 0;
}
    