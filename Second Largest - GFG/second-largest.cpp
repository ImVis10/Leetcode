//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    if (n < 2) {
	        return -1;
	    }
	    int maxVal = INT_MIN;
	    int secondMaxVal = INT_MIN;
	    
	    for (int i = 0; i < n; i++) {
	        if (arr[i] > maxVal) {
	            secondMaxVal = maxVal;
	            maxVal = arr[i];
	        } else if (arr[i] > secondMaxVal && arr[i] != maxVal) {
	            secondMaxVal = arr[i];
	        }
	    }
	    return secondMaxVal == INT_MIN ? -1 : secondMaxVal;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends