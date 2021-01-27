//
// Created by ahmeddrawy on 1/27/21.
/** f(n) = (f(n-1)<<digits(n) + n)
 *
 */

class Solution {
private:
    int md= 1e9+7;
public:
    int concatenatedBinary(int n) {
        return solve(n);
    }
    int Cnt(long long n){
        int ret= 0 ;
        while(n){
            ret++;
            n>>=1;
        }
        return ret;
    }
    int solve(long long n){
        if(n == 1)
            return 1;
        long long ret= solve(n-1);
        return ((ret<<Cnt(n))+n)%md;
    }
};