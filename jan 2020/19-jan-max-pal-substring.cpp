//
// Created by ahmeddrawy on 1/20/21.
/** we get the max pal substring by flagging all substrings of size 1 as pal,
 * preprocess all substrings of size 2,
 * building other substrings by checking lesser size from i,j and if s[i]==s[j]
 * then we can add the new substring and flag it and increase max size of substring,
 * we store starting point too
 * Time Complexity O(n*n)
 * Memory O(n*n)
 *
 * second solution
 * time O(n*n)
 * memory O(1)
 * by calculating all even pals and odd pals
 *
 */

const int N = 1005;
bool dp[N][N];
class Solution {
public:
    string longestPalindrome(string s) {
        memset(dp,0,sizeof dp);
        for (int i = 0; i <s.size() ; ++i) {
            dp[i][i] = 1;
        }
        int mxlen = 1, st = 0;
        for (int i = 1; i <s.size() ; ++i) {
            if(s[i] == s[i-1]){
                dp[i-1][i] = 1;
                mxlen = 2;
                st = i-1;
            }
        }
        for (int len = 3; len <=s.size() ; ++len) {
            for (int i = 0; i <= s.size() - len ; ++i) {
                int j = i + len -1;
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j] =1;
                    if(len > mxlen){
                        mxlen = len;
                        st = i ;
                    }
                }
            }
        }
        return s.substr(st,mxlen);
    }
    string longestPalindrome2(string s ){
        int mxlen = 1,st = 0 ;
        for (int i = 1; i < s.size() ; ++i) {
            int l = i-1,h = i;
            while(l>=0 && h <s.size() && s[l]==s[h]){
                if(h-l+1 > mxlen){
                    mxlen = h-l+1;
                    st = l;
                }
                l--,h++;
            }
            l = i-1,h=i+1;
            while(l>=0 && h <s.size() && s[l]==s[h]){
                if(h-l+1 > mxlen){
                    mxlen = h-l+1;
                    st = l;
                }
                l--,h++;
            }
        }
        return s.substr(st,mxlen);




    }
};