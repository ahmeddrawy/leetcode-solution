//
// Created by ahmeddrawy on 1/18/21.
// adding two numbers without using + or - operators

class Solution {
public:
    int getSum(int a, int b) {
        int ret = 0 ;
        int rem = 0 ;
        for (int indx = 0; indx < 32 ; ++indx) {
            int b1 = (1<<indx)&a;
            int b2 = (1<<indx)&b;

            if(rem)
                rem = 1<<indx;

            ret = ret | ( (1<<indx)&(b1^b2^rem));
            rem = (b1&b2) | (b2&rem) | (b1&rem);
        }
        return ret;
    }
};
