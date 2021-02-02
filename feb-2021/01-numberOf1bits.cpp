//
// Created by ahmeddrawy on 1/2/21.
//

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret= 0 ;
        for (int i = 0; i <32 ; ++i) {
            ret += n&(1<<i);
        }
        return ret;
    }
};