/*
 * Example: [1,2,3] returns
 * [[1,2,3],
 *  [1,3,2],
 *  [2,1,3],
 *  [2,3,1],
 *  [3,1,2],
 *  [3,2,1]]
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> soln;
        findPermute(nums, 0, soln);
        return soln;
    }
    
    void findPermute(vector<int>& nums, int begin, vector<vector<int>> &soln){
        if(begin>=nums.size()){
			//add to soln after finishing all swap
            soln.push_back(nums);
            return; 
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[i], nums[begin]);
            findPermute(nums, begin+1, soln);
            swap(nums[i], nums[begin]);
        }
    }
};