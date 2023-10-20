class Solution {
public:
    
    int convert(string& s){
        int idx = -1, i = 0;
        while(i < s.length()){
            if(s[i] == '#'){
                idx--;
                if(idx < 0){
                    idx = -1;
                }
            }else{
                idx+=1;
                s[idx] = s[i];
            }
            i+=1;
        }
        return idx;
    }
    bool backspaceCompare(string s, string t) {
        int idx1 = convert(s);
        int idx2 = convert(t);
        if(idx1 != idx2)    return false;
        for(int i=0;i<=idx1;i++){
            if(s[i]!=t[i])  return false;
        }
        return true;
    }
};