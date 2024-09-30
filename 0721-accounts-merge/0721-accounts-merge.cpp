class UnionFind {
public:
    UnionFind(int n) {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    
    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }
    
    bool unionSets(int x1, int x2) {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2) return false;
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
    
private:
    vector<int> par;
    vector<int> rank;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> emailToAccIdx;
        unordered_map<int, unordered_set<string>> emailGroup;
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToAccIdx.find(email) != emailToAccIdx.end()) {
                    uf.unionSets(i, emailToAccIdx[email]);
                } else {
                    emailToAccIdx[email] = i;
                }
            }
        }
        
        for (auto& [email, accIdx] : emailToAccIdx) {
            int leader = uf.find(accIdx);
            emailGroup[leader].insert(email);
        }
        
        vector<vector<string>> res;
        for (auto& [accIdx, emails] : emailGroup) {
            vector<string> account;
            account.push_back(accounts[accIdx][0]); // acc name
            account.insert(account.end(), emails.begin(), emails.end());
            sort(account.begin() + 1, account.end());
            res.push_back(account);
        }
        return res;
    }
};