class Solution {
public:
    string encode(vector<string>& strs) {
        vector<int> sizes;
        for(auto str:strs)
        {
            sizes.push_back(str.length());
        }
        string res;
        res = to_string(strs.size()) + ",";
        for(auto x:sizes)
        {
            res += to_string(x) + ",";
        }
        res += '/';
        for(auto str:strs)
        {
            res+= str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<int> sizes;
        int indx=0;
        int sz = 0;
        string cur="";
        while(s[indx]!=',')
        {
            cur+=s[indx++];
        }
        indx++;
        sz = stoi(cur);
        cur="";
        for(int i=0; i<sz; indx++)
        {
            if(s[indx] == ',')
            {
                i++;
                sizes.push_back(stoi(cur));
                cur="";
            }
            else cur+=s[indx];
        }
        indx++;
        vector<string> res;
        for(auto sz:sizes)
        {
            res.push_back(s.substr(indx,sz));
            indx+=sz;
        }
        return res;
    }
};
