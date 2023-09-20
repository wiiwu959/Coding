class Solution {
public:
    class path {
    public:
        int current_node;
        int mask;
        int step;
        
        path(int current_node, int mask, int step) {
            this -> current_node = current_node;
            this -> mask = mask;
            this -> step = step;
        }
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        queue<path> to_run;
        int all_mask = (1 << graph.size()) - 1;
        // record path that have walked before (to prevent TLE)
        // pair(node, mask)
        set<pair<int, int>> record;

        // all of the node can be the start point
        for (int i = 0; i < graph.size(); i++) {
            int mask = 1 << i;
            path tmp(i, mask, 0);
            to_run.push(tmp);
            record.insert({i, mask});
        }

        while (!to_run.empty()) {
            path target = to_run.front();
            to_run.pop();

            if (target.mask == all_mask) {
                return target.step;
            }

            for (auto& node: graph[target.current_node]) {
                int mask = target.mask;
                mask = mask | (1 << node);

                // Check if the path walked, if walked, ignore it
                if (record.count({node, mask}) == 0) {
                    path to_node(node, mask, target.step + 1);
                    to_run.push(to_node);
                    record.insert({node, mask});
                }
            }
        }
        return -1;
    }
};
