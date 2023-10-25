class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        
        int currLength = 1 << (n - 1);
        int prevLength = currLength / 2;
        
        if (k <= prevLength) return kthGrammar(n - 1, k);
        return !kthGrammar(n - 1, k - prevLength);
    }
};