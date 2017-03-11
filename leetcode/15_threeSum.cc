/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 *  [-1, 0, 1],
 *  [-1, -1, 2]
 * ]
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> soln;
        if(nums==NULL || nums.size()<=2){
            return soln;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<(nums.size()-2);i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
				int lo=i+1,hi=nums.size()-1,negNum1=-nums[i];
				while(lo<hi){
					if(nums[lo]+nums[hi]==negNum1){
						soln.push_back({-negNum1,nums[lo], nums[hi]});
						while(lo<hi && nums[lo]==nums[lo+1]){
							lo++;
						}
						while(lo<hi && nums[hi]==nums[hi-1]){
							hi--;
						}
						lo++;hi--;
					}else if(nums[lo]+nums[hi]<negNum1){
						lo++;
					}else{
						hi--;
					}
				}
			}
        }
        return soln;
    }

};