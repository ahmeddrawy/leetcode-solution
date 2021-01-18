//
// Created by ahmeddrawy on 1/18/21.
//

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mmap;
        for (int i = 0; i < n; ++i) {
            mmap[nums[i]]++;
        }
        int ret= 0 ;
        for(auto it : mmap){
            int mn = 0;
            if(it.first == k - it.first)
                mn = it.second/2;
            else
                mn = min(it.second, mmap[k- it.first]);

            mmap[it.first] -=mn;
            mmap[k-it.first]-=mn;
            ret+=mn;
        }
        return ret;

    }
};