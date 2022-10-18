/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        // using binary search as the problem statement resembles binary search.
        int l = 1, r = n;
        while(l < r) {
            int mid = l + (r - l)/2;
            if(isBadVersion(mid)) { // if mid is a bad version, we know that first bad version is before mid or at mid itself.
                r = mid;
            } else { // if mid is a good version, we know that first bad version is not in the interval [l ,mid]
                l = mid + 1;
            }
        }
        return l; // return when the search space is reduced to 1 element.
    }
}