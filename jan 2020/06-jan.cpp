//
// Created by ahmeddrawy on 1/6/21.
//
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int indx= 0 , number =1 , cnt = 0 ;
        for (; cnt <k ; ) {
            if(indx < arr.size()&&arr[indx ] == number){
                number++;
                indx++;
            }
            else{
                cnt++;
                number++;

            }

        }
        return number-1;

    }
};

