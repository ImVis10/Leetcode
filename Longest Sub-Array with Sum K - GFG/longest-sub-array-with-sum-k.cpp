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
            if (prefixSum.find(sum) == prefixSum.end())
                prefixSum[sum] = i;
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