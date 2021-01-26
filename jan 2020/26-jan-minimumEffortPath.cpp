//
// Created by ahmeddrawy on 1/26/21.
//
/*
 * we binary search on value, then floodfill trying all paths
 */

bool visited[100][100];
class Solution {
private:
    vector<vector<int>> heights;
    int n ;
    int m;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        this->heights = heights;
        this->n = heights.size();
        this->m = heights[0].size();
        return bs();
    }
    bool can(int k,int i = 0, int j = 0){
        /// we bfs
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || visited[i][j])
            return false;
        if(i == heights.size() -1 && j ==  heights[0].size() -1)
            return true;
        bool ret = 0 ;
        visited[i][j] = 1;
        if( !out(i+1,j) &&abs(heights[i][j] - heights[i+1][j]) <=k)
            ret = ret || can(k,i+1,j);
        if(!out(i,j+1)&& abs(heights[i][j] - heights[i][j+1]) <=k )
            ret = ret || can(k,i, j+1);
        if(!out(i-1,j) && abs(heights[i][j] - heights[i-1][j]) <= k )
            ret = ret || can(k,i-1,j);
        if( !out(i,j-1)&&abs(heights[i][j] - heights[i][j-1]) <= k)
            ret = ret || can(k,i,j-1);

        return ret;
    }
    bool out(int i, int j){
        return (i <0 || j <0 || i >= n || j >=m);
    }
    int bs(){
        int l = 0, r =1e6 +5;
        while(l<r){
            int mid = l + (r-l)/2;
            memset(visited,0,sizeof visited);
            if(can(mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l ;
    }


};