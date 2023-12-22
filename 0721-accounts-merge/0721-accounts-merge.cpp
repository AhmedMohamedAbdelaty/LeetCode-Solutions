class DSU {
private:
    vector<int> parent;

public:
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        int n = accounts.size();
        DSU dsu(n);

        unordered_map<string, int> emailToIndex;
        // [email] -> index of the account that has the email (ex: [am0103738@mail.com] -> 0, this email
        // belongs to the account at index 0)
        for (int i = 0; i < n; i++) {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++) {
                string email = accounts[i][j];
                if (emailToIndex.count(email)) { // if email already exists
                    dsu.unite(i, emailToIndex[email]); // unite the current account with the account that has the same email
                } else {
                    emailToIndex[email] = i; // else add the email to the map
                }
            }
        }

        unordered_map<int, set<string>> mergedAccounts; // map to store the merged accounts
        // [index of the account] -> set of emails in the account
        for (auto& entry : emailToIndex) {
            int root = dsu.find(entry.second); // find the root of the account that has the email
            mergedAccounts[root].insert(entry.first); // emtry.first is the email and entry.second is the index of the account
        }

        vector<vector<string>> merged;
        for (auto& entry : mergedAccounts) {
            // entry.first is the index of the account and entry.second is the set of emails in the account
            vector<string> account;
            account.push_back(accounts[entry.first][0]); // push the name of the account

            account.insert(account.end(), entry.second.begin(), entry.second.end()); // push the emails in the account

            merged.push_back(account); // push the account to the merged vector
        }

        return merged;
    }
};