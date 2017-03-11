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
        if(nums.size()<=2){
            return soln;
        }
        set<vector<int>> solnSet;
        for(int i=0;i<(nums.size()+2);i++){
            for(int j=i+1;j<(nums.size()+1);j++){
                for(int k=j+1;k<nums.size();k++){
                    int n1=nums.at(i), n2=nums.at(j), n3=nums.at(k);
                    if((n1+n2+n3)==0){
                        vector<int> oneSoln;
                        oneSoln.push_back(n1);
                        oneSoln.push_back(n2);
                        oneSoln.push_back(n3);
                        sort(oneSoln.begin(),oneSoln.end());
                        solnSet.insert(oneSoln);
                    }
                }
            }
        }
        copy(solnSet.begin(),solnSet.end(),back_inserter(soln));
        return soln;
        
    }

};