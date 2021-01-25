//
// Created by ahmeddrawy on 1/25/21.
//

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lst = -1 ;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(lst ==- 1){
                if(nums[i] == 1)
                    lst = i;
            }
            else {
                if(nums[i] == 1 && i-lst -1 <k )
                    return false;
                else if(nums[i] == 1)
                    lst= i;
            }
        }
        return true;
    }
};