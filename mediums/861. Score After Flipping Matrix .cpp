//
// Created by ahmeddrawy on 8/22/21.
//

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i <row ; ++i) {
            if (grid[i][0] == 0){
                grid[i][0] = 1;
                for (int j = 1; j < col; ++j) {
                    grid[i][j] = (grid[i][j] == 0)? 1: 0;
                }
            }
        }
        for (int j = 1; j < col; ++j) {
            int cnt = 0 ;
            for (int i = 0; i < row; ++i) {
                cnt += grid[i][j] == 1;
            }
            if( cnt <= row/2){
                for (int i = 0; i < row; ++i) {
                    grid[i][j] = (grid[i][j] == 0)? 1: 0;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < row ; ++i) {
            long long curr = 0;
            for (int j = 0; j < col ; ++j) {
                curr += (grid[i][j] == 1)? (1<<(col - (j +1))): 0;
            }
            ans += curr;
        }
        return ans ;
    }
};