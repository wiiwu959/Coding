class Solution {
private:
    vector<string> ans;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> from_to;
        for (int i = 0; i < tickets.size(); i++) {
            from_to[tickets[i][0]].push_back(tickets[i][1]);
        }

        for (auto& ticket: from_to) {
            sort(ticket.second.rbegin(), ticket.second.rend());
        }

        dfs(from_to, "JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(unordered_map<string, vector<string>>& from_to, string src) {

        while (!from_to[src].empty()) {
            string dst = from_to[src].back();
            from_to[src].pop_back();
            dfs(from_to, dst);
        }

        ans.push_back(src);
        return;
    }
};
