#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            int size = words.size();
            int len = words[0].size();
            int taille = s.size();
            if (len * size > taille) {
                return {};
            }
    
            vector<int> vec;
            unordered_map<string, int> mp;
            for (auto c : words) {
                mp[c]++;
            }
    
            for (int offset = 0; offset < len; offset++) {
                unordered_map<string, int> m;
                queue<string> q;
                int first = offset;
                int last = offset;
                int formed = 0;
    
                while (last <= taille - len) {
                    string st = s.substr(last, len);
                    last += len;
                    m[st]++;
                    q.push(st);
                    if (mp.find(st) != mp.end() && m[st] == mp[st]) {
                        formed++;
                    }
                    if (q.size() > size) {
                        string debut = q.front();
                        if (mp.find(debut) != mp.end() && m[debut] == mp[debut]) {
                            formed--;
                        }
                        m[debut]--;
                        q.pop();
                        first += len;
                    }
    
                    if (formed == mp.size()) {
                        vec.push_back(first);
                    }
                }
            }
    
            return vec;
        }
    };
    