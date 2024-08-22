class Solution {
public:
    int findComplement(int num) {
        int digitsInXorWith = floor(log2(num) + 1);
        cout << "digitsInXorWith " << digitsInXorWith << endl;
        int xorWith = (pow(2, digitsInXorWith) - 1);
        cout << "xorWith " << xorWith <<  endl;
        int res = num ^ xorWith;
        return res;
    }
};