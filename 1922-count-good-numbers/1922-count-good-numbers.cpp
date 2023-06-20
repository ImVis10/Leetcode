#define mod 1000000007
class Solution {
public:
    int countGoodNumbers(long long n) {
        /** INTUITION:
        A digit string is good if the digits (0-indexed) at even indices are even (0, 2, 4, 6, 8) and the digits at odd indices are prime (2, 3, 5, or 7).
        So each even index has 5 possibilities and each odd index has 4 possibilities. 
        **/
        /** APPROACHES:
        1. The easiest approach is to iterate through the length of the string i.e. n and if the index is even multiply with 4, else multiply with 4. But this takes            O(n) time and if the maximum value of n is the range of 10^15, we'll get TLE. O(n) is doable when n is in the maximum range of 10^7.
        2. As mentioned previously, each even index has 5 possibilities and each odd index has 4 possibilities. For a string of length n, there are n / 2 odd                    inidices and n / 2 + (n % 2) even indices.
           eg: say n = 5, we have 0 1 2 3 4---> [1, 3] odd indices, [0, 2, 4] even indices.
           we have 2 (5/2 ==> n / 2) odd indices and 3 (5 / 2 + 5 % 2 ==> n / 2 + (n % 2)) even indices.
           So the formula would be pow(5, n / 2) * pow(4, n / 2 + (n % 2)).
           BUT WE CAN'T USE THE POW FUNCTION FROM STL AS THAT WON'T TAKE CARE OF THE THE CONSTRAINT: Since the answer may be large, return it modulo 109 + 7.
           SO WRITING OUR OWN POW FUNCTION IS A LOT BETTER
        **/
        long long numOddIndices = n / 2;
        long long numEvenIndices = n / 2 + (n % 2);
        return (power(5, numEvenIndices) * power(4, numOddIndices)) % mod; 
    }
private:
    long long power(long long x, long long y) {
        if (y == 0) {
            return 1;
        } else if (y == 1) {
            return x;
        }
        
        long long res = power(x, y / 2);
        res *= res;
        res %= mod; // applying modulus operation after every multiplication, just so that we don't go over the constraint as the res might be large
        
        if (y % 2 == 1) { // if y is even, res should be multiplied by x one more time. Eg: y = 7, 7 / 2 = 3, so far we did x^ 3 * x ^ 3. What about remaining x?
            res *= x;
            res %= mod;
        }
        return res;
    }
};