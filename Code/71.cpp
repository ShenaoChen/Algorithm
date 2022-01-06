class Solution {
public:
    string simplifyPath(string path) {
        vector<string> c;
        string str = "";
        int idx = 0, n = path.size();
        for(int i = 0; i < n; i++){
            if(path[i] != '/'){
                str += path[i];
                if(i != n - 1)
                    continue;
            }
            if(str == ".." && !c.empty())
                c.pop_back();
            else if(str != "" && str != "." && str != "..")
                c.push_back(str);
            str = "";
        }
        str = "";
        for(int i = 0; i < c.size(); i++)
            str += "/" + c[i];
        if(str.size() == 0)
            str = "/";
        return str;   
    }
};
