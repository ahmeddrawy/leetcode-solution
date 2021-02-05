//
// Created by ahmeddrawy on 2/5/21.
//
/** we split string on '/' then we add to all directories to stack and pop or not based on if ".." we pop,
 *
 *
 */
class Solution {
public:
    string simplifyPath(string path) {
        path = fixLevels(path);
        return path ;
    }
    string fixLevels(string path){
        string ret = "";
        stack<string > dirs;
        int pos = 0,prev= 0 ;
        do{
            pos = path.find("/", prev);
            if(pos == string::npos)
                pos = path.size();
            string dir = path.substr(prev, pos-prev);
            if(!dir.empty()){
                if(dir =="..") {
                    if (!dirs.empty())
                        dirs.pop();
                }
                else if(dir != ".")
                    dirs.push(dir);
            }
            prev = pos + 1; /// 1 is delim length
        }while(pos<path.size() && prev< path.size());
        while(!dirs.empty()){
//            ret+="/" + dirs.top();
            ret = '/'+ dirs.top() + ret;
            dirs.pop();
        }
        if(ret.empty())
            return "/";

        return ret;
    }
};