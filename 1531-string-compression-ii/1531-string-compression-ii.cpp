class Solution {
private:
    vector<vector<int>> dp;
    int f(int ind, int k, string &s){
        int n = s.length();

        if(n - ind <= k) return 0; //remove all from ind to n-1;

        //If already calculated, then just return it using DP.
        if(dp[ind][k]!=-1) return dp[ind][k];

        //k>0 then remove current character.
        int ans = k ? f(ind+1, k-1, s) : 1e5;

        //Or  not remove current char and start a substring from it and remove all other character which occures btw first and last occurence of this char till k>0.
        int cnt = 1, removeCnt = 0;
        for(int i = ind+1; i <= n; i++){
            int cur = 1 + ((cnt>99) ? 3 : (cnt>9) ? 2 : (cnt>1) ? 1 : 0) + f(i, k - removeCnt, s);
            ans = min(ans, cur);
            if(i<n && s[i] == s[ind]) cnt++;
            else if(k - removeCnt <= 0) break;//Further we can't remove any character.
            else removeCnt++;//Remove it, so increae removeCnt.
        }
        return dp[ind][k] = ans;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        dp.resize(101, vector<int>(101, -1));
        return f(0, k, s);
    }
};