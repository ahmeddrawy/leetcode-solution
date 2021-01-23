//
// Created by ahmeddrawy on 1/23/21.
//
/**
 * dp to count number of paths in grid, right and down moves only
 * first solution top down
 * second solution bottom up
 */

int dp[105][105];
class Solution {
    int n,m;
public:
    int uniquePaths(int m, int n) {
        this->n = n ;
        this->m = m;
        memset(dp,-1,sizeof dp);
        return solve(0,0);
    }
    int uniquePaths2(int m, int n) {
        this->n = n ;
        this->m = m;
        memset(dp,0,sizeof dp);
        dp[n-1][m-1] = 1;
        for (int i = n-1; i >=0 ; --i) {
            for (int j = m-1; j >=0 ; --j) {
                if(i+1<n)
                    dp[i][j] += dp[i+1][j];
                if(j+1 < m)
                    dp[i][j] += dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    int solve(int i, int j){
        if(i>n || j >m)
            return 0;
        if(i == n-1 && j == m-1)
            return 1;
        int &ret= dp[i][j];
        if(~ret)
            return ret;
        ret = 0 ;
        ret = solve(i+1,j) + solve(i,j+1);
        return ret;
    }
};