//
// Created by ahmed on 1/1/2021.
/** test case

                 4
                4
                91 4 64 78
                3
                1 78
                2 4 64
                1 91
                4
                1 3 5 7
                1
                4 2 4 6 8
                3
                49 18 16
                1
                3 16 18 49
                2
                85 15
                2
                1 15
                1 85

 */
//

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, int> mmap;
        for (int i = 0; i <arr.size() ; ++i) {
            mmap[arr[i]] = i+1; /// starting with 1 based to check later
        }
        bool ret = true;
        for(auto v :pieces){
            ret= ret &&can(v,mmap);
            if(!ret)
                return ret;
        }
        return ret;
    }
    /// we've been told that the len of vector and vector of vectors total length are equal
    /// and all elements are distinct in both
    /// so we need to check only if all elements in array exist
    /// and the subsequences in array be together in vector of vectors
private:
    bool can (vector <int> & vec , map <int,int>& mmap){
        if(vec.size() == 1  ){

            if(mmap[vec[0]])
                return true;
            else return false;
        }
        int indx = mmap[vec[0]];
        for (int i = 1; i <vec.size() ; ++i,indx++) {
            if(indx+1 != mmap[vec[i]])
                return false;
        }

        return true;
    }
};