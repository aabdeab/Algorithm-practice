#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        struct window {
            int freq[127];
            int slot[127];
            int different_letters;
            int formed_letters;
            window(const string &p){
                int mint=0;
                memset(freq, 0, sizeof(freq));
                for(int i=0;i<p.size();i++){
                    if(freq[p[i]]==0){
                        mint++;
                    }
                    freq[p[i]]++;
                }
                different_letters=mint;
                formed_letters=0;
                memset(slot, 0, sizeof(slot));
            }
            void push(const string &s , int i){
                slot[s[i]]++;
                if(slot[s[i]]==freq[s[i]]){
                    formed_letters++;
                }
            }
            void pop(const string &s , int i ){
                if(slot[s[i]]==freq[s[i]] && freq[s[i]]>0){
                    formed_letters--;
                }
                slot[s[i]]--;
            }
            void reset(){
                for (auto &i:slot){
                    i=0;
                }
                formed_letters=0;
            }
            bool match(){
                return formed_letters==different_letters;
            }
    
        };
        vector<int> findAnagrams(string s, string p) {
            int taille = s.size();
            int len = p.size();
            if(taille < len){
                return {};
            }
            vector<int> result;
            window w(p);
                int first(0);
                int last(0);
                while(last<taille){
                    if(last-first<len){
                        w.push(s,last);
                        last++;
                        if (last - first == len && w.match()) {
                            result.push_back(first);
                        }
                    }
                    else{
                        w.push(s,last);
                        w.pop(s,first);
                        if(w.match()){
                            result.push_back(first+1);
                        }
                        last++;
                        first++;
                    }
                }
            return result;
            
        }
    };