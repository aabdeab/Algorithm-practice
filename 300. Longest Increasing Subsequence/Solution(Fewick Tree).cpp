class Solution {
    public:
        struct FenwickTree {
        private:
            int size;
            vector<int> tree;
    
        public:
            FenwickTree(int n) {
                size = n;
                tree.assign(n + 2, 0); // 1-based indexing
            }
    
            void update(int index, int value) {
                while (index <= size) {
                    tree[index] = max(tree[index], value);
                    index += index & -index;
                }
            }
    
            int query(int index) {
                int result = 0;
                while (index > 0) {
                    result = max(result, tree[index]);
                    index -= index & -index;
                }
                return result;
            }
        };
    
        int lengthOfLIS(vector<int>& nums) {
            vector<int> sorted = nums;
            sort(sorted.begin(), sorted.end());
            sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
            unordered_map<int, int> rank;
            for (int i = 0; i < sorted.size(); ++i) {
                rank[sorted[i]] = i + 1; // 1-based index for BIT
            }
    
            FenwickTree bit(sorted.size());
            for (int num : nums) {
                int r = rank[num];
                int maxLIS = bit.query(r - 1); // strictly increasing
                bit.update(r, maxLIS + 1);
            }
    
            return bit.query(sorted.size());
        }
    };
    