//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
	    // code here
	   // int count = 0, maxCount = 0;
	   // int res = -1;
	    
	   // for (int  i = 0; i < n; i++) {
	   //     for (int j = 0; j < m; j++) {
	   //         if (arr[i][j] == 1) {
	   //             count++;
	   //         }
	   //     }
	   //     if (count > maxCount) {
	   //         maxCount = count;
	   //         res = i;
	   //     }
	   //     count = 0;
	   // }
	   // return res;
	   
	   // WE CAN REDUCE THE RUNNING TIME USING BINARY SEARCH AS THE MATRIX IS SORTED IN EACH ROW
	   // SO GOTTA FIND THE FIRST INSTANCE OF '1' IN A ROW
	   int res = -1, maxCount = 0, target = 1;
	   for (int i = 0; i < n; i++) {
	       int firstOccuredPosOfOne = getfirstOccuredPosOfOne(arr[i], 0, m - 1, target);
	       if (firstOccuredPosOfOne != -1 && m - firstOccuredPosOfOne > maxCount) {
	           maxCount = m - firstOccuredPosOfOne;
	           res = i;
	       }
	   }
	   return res;
	}
private:
    int getfirstOccuredPosOfOne(vector<int> row, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((mid == 0 || row[mid - 1] == 0) && row[mid] == target) {
                return mid;
            } else if (target > row[mid]) {
                low = mid + 1;
            } else  {
                high = mid - 1;
            }
        }
        return -1;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
