//
// Created by ahmeddrawy on 1/23/21.
//
/** sort all diagonals of a matrix
 * we first iterate over max of rows and cols
 * then we iterate first row and first col to start the diagonals
 * we store and sort then change the value
 * each value is checked only once
 *
 */
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for (int row = 0; row < max(mat.size(),mat[0].size() ); ++row) {
            int x = row, y = 0;
            vector<int>dig;
            for (int col = 0; col <mat[0].size() && x<mat.size() ; ++col) {
                dig.push_back(mat[x++][col]);
            }
            sort(dig.begin(),dig.end());
            x = row;
            for (int col = 0; col <mat[0].size()  && x<mat.size(); ++col) {
                mat[x++][col] = dig[col];
            }
            y = row;
            if(row != 0&&row < mat[0].size()){
                y = row;
                vector<int> dig2;
                for ( x = 0; x <mat.size() && y < mat[0].size() ; ++x) {
                    dig2.push_back(mat[x][y++]);
                }
                sort(dig2.begin(), dig2.end());
                y = row;
                for ( x = 0; x <mat.size() && y < mat[0].size() ; ++x) {
                    mat[x][y++] = dig2[x];
                }
            }

        }
        return mat;
    }
};