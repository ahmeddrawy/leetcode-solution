//
// Created by ahmeddrawy on 8/22/21.
//

long long MOD =(long long) 1e9 +7 ;

long long multipy(long long x , long long y ){

    return ((x%MOD) *(y%MOD))%MOD;
}

class Solution {
public:
    int countHomogenous(string s) {
        int cnt = 1;
        long long ret = 0;
        for (int i = 1; i < s.size() ; ++i) {
            if (s[i] == s[i-1])
                cnt++;
            else{
                ret = (ret + (cnt*(cnt+1))/2)%MOD;
                cnt = 1;
            }
        }
        ret = (ret + multipy(cnt,(cnt+1))/2)%MOD;

        return  ret;

    }
};