class Solution {
    public:
        int manacher(string &s){
            if(s.empty()) return 0;
            string t = "^";
            for(char c : s){
                t+= "#" + string(1,c);
            }
            t+="#$";
            int n = t.size();
            vector<int> p(n,0);
            int result=0;
            int center=0;int right =0;
            for(int i=1;i<n-1;i++){
                int mirroir = 2*center-i;
                if(i<right){
                    p[i]=min(p[mirroir],right-i);
                }
                while(t[i+(p[i]+1)]==t[i-(p[i]+1)]){
                    p[i]++;
                }
                if(i+p[i]>right){
                    center=i;
                    right=i+p[i];
                }
                result+=(p[i]+1)/2;
            }
            return result;
        }
        int countSubstrings(string s) {
            return manacher(s);
            
        }
    };