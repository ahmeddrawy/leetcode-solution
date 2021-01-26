//
// Created by ahmeddrawy on 1/25/21.
/**
 * we flag last occurence of chars
 * check if start is same start or we need to shift after first occurence of current char
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lsts(265,-1);
        int st = 0 ;
        int ret= 0 ;
        for (int i = 0; i <s.size() ; ++i) {
            st = max(st, lsts[s[i]] +1);
            ret = max(ret, i-st + 1);
            lsts[s[i]] =  i;
        }
        return ret;
    }
};