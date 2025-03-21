#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        if(nums.size()==0 && target==0){
            return 0;
        }
        int Min=INT_MAX;
        int sum=nums[0];
        int length=1;
        while(left<nums.size() && right<nums.size()){
            if(sum<target ){
                if(right==nums.size()-1){
                    break;
                }
                right++;
                sum+=nums[right];
                length++;
            }
            else{
                Min=min(Min,length);
                sum-=nums[left];
                left++;
                length--;
            }
        }
        Min=(Min==INT_MAX)?0:Min;
        return Min ;
        
    }
};

int main(){
    Solution solution;
    vector<int> nums={2,3,1,2,4,3};
    int target=7;
    cout<<solution.minSubArrayLen(target,nums);
    return 0;
}