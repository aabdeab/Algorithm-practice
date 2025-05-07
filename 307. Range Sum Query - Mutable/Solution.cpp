#include <bits/stdc++.h>
using namespace std;
class FenwickTree{
    private:
        int sum;
        vector<int> vec;
    public :
        FenwickTree(int n){
            sum=n;
            vec.assign(n+1,0);
        }
        int query(int n){
            int total =0;
            while(n>0){
                total+=vec[n];
                n-=n & -n;
            }
            return total;
        }
        void update(int n,int val){
            if(val==0) return;
            while(n<=sum){
                vec[n]+=val;
                n+=n&-n;
            }
            return;
        }
};
class NumArray {
public:
    FenwickTree F;
    vector<int> num;
    NumArray(vector<int>& nums) : F(nums.size()) {
        int size = nums.size();
        num=nums;
        for(int i=0;i<size;i++){
            F.update(i+1,nums[i]);
        }
    }
    void update(int index, int val) {
        int diff = val-num[index];
        num[index]=val;
        F.update(index+1,diff);
    }
    int sumRange(int left, int right) {
        return F.query(right+1)-F.query(left);        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */