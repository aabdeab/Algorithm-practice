class Solution {
    public:
        vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
            sort(products.begin(), products.end());
            vector<vector<string>> search;
            string prefix = "";
            for(char c : searchWord){
                prefix += c;
                auto it = lower_bound(products.begin(), products.end(), prefix);
                auto it1 = upper_bound(products.begin(), products.end(), prefix + char(127));
                
                int start = it - products.begin();
                int end = min(start + 3, int(it1 - products.begin()));  
    
                vector<string> vec;
                for(int i = start; i < end; ++i){
                    vec.push_back(products[i]);
                }
    
                search.push_back(vec);
            }
            return search;
        }
    };
    