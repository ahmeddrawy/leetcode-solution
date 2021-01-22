//
// Created by ahmeddrawy on 1/22/21.
//


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ///first we check if 2 words not equal then false
        if(word1.size() != word2.size())
            return false;
        int n = word1.size();
        map<char,int> m1;
        map<char,int> m2;
        for (int i = 0; i <n ; ++i) {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        /// if they have different number of unique chars, then false
        if(m1.size() != m2.size())
            return false;
        /// if word 1 has unique char not in word2, then false
        /// we should check word2 too but not needed we check that with numbers next step
        for(auto  it : m1){
            if(m2[it.first] ==0 )
                return false;
        }
        map<int,int> f1;
        map<int,int> f2;
        /// we register the frequency of chars in a frequency array
        /// for e.q if 'a' showed 2 times in word 1, we count 2 as 1 occurrence
        /// both words must have same unique chars and same number of occurrences -no matter what occurrences for what char-
        /// if the condition passed, then we can interchange chars with each other
        for(auto it : m1){
            f1[it.second]++;
        }
        for(auto it : m2){
            f2[it.second]++;
        }
        if(f2.size() != f1.size())
            return false;
        for(auto it : f1){
            if(it.second != f2[it.first]){
                return false;
            }
        }
        return true;


    }
};
