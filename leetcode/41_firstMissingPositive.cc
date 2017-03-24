/*
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 */
class Solution {
public:
    //https://discuss.leetcode.com/topic/8293/my-short-c-solution-o-1-space-and-o-n-time/18
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            //let nums[i-1]=i
            while(nums[i]>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};