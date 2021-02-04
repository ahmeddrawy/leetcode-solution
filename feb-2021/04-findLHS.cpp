//
// Created by ahmeddrawy on 2/4/21.
//

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 1;
        while(l < nums.size() && nums [l] == nums[0])
            l++;
        l--;
        int ans = 0 ;
        int prev= l ;
        int prevCnt= l + 1;
        int currCnt = 0 ;
        for (int i = l+1; i <nums.size() ; ++i) {
            if(abs(nums[i] - nums[prev]) == 1){
                if(i == nums.size()-1){
                    /// last
                    ans = max(ans,prevCnt+ currCnt + 1);
                }
                currCnt++;
                continue;
            }
            else if(nums[i] == nums[prev]){
                prev++;
                prevCnt++;
            }
            else{
                if(currCnt >0){
                    ans = max(ans, prevCnt + currCnt);
                    prev = i-1;
                    prevCnt = currCnt;
                    currCnt = 0 ;
                    i--;
                }else{
                    prev = i ;
                    prevCnt = 1;
                }
            }
        }
        return ans ;
    }
};