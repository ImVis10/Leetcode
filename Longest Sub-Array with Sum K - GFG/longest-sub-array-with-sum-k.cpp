//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int n = N;
        int maxLen = 0;
        int sum = 0;
        map<int, int> prefixSum;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (sum == K) {
                maxLen = max(maxLen,  i + 1);
            }
            int rem = sum - K;
            if (prefixSum.find(rem) != prefixSum.end()) {
                int currLen = i - prefixSum[rem];
                maxLen = max(maxLen, currLen);
            }
            if (prefixSum.find(sum) == prefixSum.end()) // we need the leftmost 'x - k', so only update when the 'x - k' was not present in the map previously
                prefixSum[sum] = i;                     // eg: [2, 0, 0, 3] -- for 2 we should store (2, 0) not (2,2), as we should maximize the size of the subarry having sum == K, in this case (0, 0, 3)
        }
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends