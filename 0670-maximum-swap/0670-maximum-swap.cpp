class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int maxIdx = -1, idx1 = -1, idx2 = -1;
        
        char maxCh = '/';
        
        for (int i = s.length() - 1; i >=0; i--) {
            char ch = s[i];
            if (ch > maxCh) {
                maxCh = ch;
                maxIdx = i;
                continue;
            }
            
            if (ch < maxCh) {
                idx1 = i;
                idx2 = maxIdx;
                cout << idx1 << endl;
                cout << idx2 << endl;
            }
        }
        
        if (idx1 == -1 or idx2 == -1) return stoi(s);
        swap(s[idx1], s[idx2]);
        return stoi(s);
    }
};