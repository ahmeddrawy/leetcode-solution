//
// Created by ahmeddrawy on 1/23/21.
//
class Solution {
    string s,p;
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;

        return solve(0,0);
    }
    bool solve(int l,int r){
        if(r == p.size()){
            return l ==  s.size();
        }
        bool match = l < s.size()&&(s[l] == p[r] || p[r]=='.');
        if (r+1 < p.size() && p[r+1] =='*'){
            return solve(l,r+2) || (match && solve(l+1,r));
        }
        return (match && solve(l+1,r+1));
    }
};
