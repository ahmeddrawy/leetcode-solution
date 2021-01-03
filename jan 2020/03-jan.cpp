//
// Created by ahmeddrawy on 1/3/2021.
// solving using dp bitmasking due to low constraints
/// all permutations failed because 15! is large
int dp[16][1<<15 +1];
class Solution {
public:
    int countArrangement(int n) {
        vector<int> vec(n);
        memset(dp,-1, sizeof dp);
        return solve(0,0,n);

    }

private:

    int solve(int indx , int mask, int n ){
        if(indx == n)
            return 1 ;
        int &ret = dp[indx][mask];
        if(~ret)
            return ret;
        ret = 0 ;
        for (int i = 1; i <= n; ++i) {
            if(((1<<i)&mask )== 0){
                if(i % (indx+1) ==0 || (indx+1) % i == 0  ){
                    ret += solve(indx+1 , (1<<i)|mask,n);
                }
            }
        }
        return ret;
    }
};
