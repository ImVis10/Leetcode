class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, int>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string res;
        
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            char ch = p.second;
            int freq = p.first;
            if (res.length() >= 2 and res[res.length() - 1] == ch and res[res.length() - 2] == ch) {
                if (pq.empty()) break;
                auto nextP = pq.top(); pq.pop();
                char nextCh = nextP.second;
                int nextFreq = nextP.first;
                res += nextCh;
                nextFreq -= 1;
                if (nextFreq > 0) pq.push({nextFreq, nextCh});
            } else {
                freq -= 1;
                res += ch;
            }

            if(freq > 0) pq.push({freq, ch});
        }
        return res;
    }
};