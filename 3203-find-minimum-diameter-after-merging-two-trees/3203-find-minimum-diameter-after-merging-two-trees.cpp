class Solution {
    int diameterOfGraph(const map<int, vector<int>>& adj, int n, int start_node) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start_node);
        visited[start_node] = true;
        int last = start_node;

        while (!q.empty()) {
            int sizee = q.size();
            for (int i = 0; i < sizee; ++i) {
                last = q.front();
                q.pop();
                for (int neighbor : adj.at(last)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }

        fill(visited.begin(), visited.end(), false);
        q.push(last);
        visited[last] = true;
        int hop = 0;
        while (!q.empty()) {
            int sizee = q.size();
            for (int i = 0; i < sizee; ++i) {
                last = q.front();
                q.pop();
                if (adj.count(last)) {
                    for (int neighbor : adj.at(last)) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
            hop++;
        }
        return hop - 1;
    }
    int finddiameter(vector<vector<int>>& edges) {
       if (edges.empty()) {
            return 0;
        }
        map<int, vector<int>> mpp;
        set<int> stt;
        for (auto& a : edges) {
            mpp[a[0]].push_back(a[1]);
            mpp[a[1]].push_back(a[0]);
            stt.insert(a[1]);
            stt.insert(a[0]);
        }
        int n=stt.size();
        return diameterOfGraph(mpp, n,0);
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        int a = finddiameter(edges1);
        int b = finddiameter(edges2);
        int ans = ((a + 1) / 2) + 1 + ((b + 1) / 2);
        return ans;
    }
};