class Solution {
private:
    std::vector<int> cnt, ans;
    std::vector<std::vector<int>> graph;

public:
    std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges) {
        cnt.resize(n); ans.resize(n); graph.resize(n);

        std::fill(cnt.begin(), cnt.end(), 1);
        std::fill(ans.begin(), ans.end(), 0);
        for(std::vector<int>& edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        auto posdfs = [&](int curr, int prev, auto&& posdfs) -> void {
            for(int next: graph[curr]) {
                if(next != prev) {
                    posdfs(next, curr, posdfs);
                    cnt[curr] += cnt[next];
                    ans[curr] += ans[next] + cnt[next];
                }
            }
        };

        auto predfs = [&](int curr, int prev, auto&& predfs) -> void {
            for(int next: graph[curr]) {
                if(next != prev) {
                    ans[next] = ans[curr] - cnt[next] + n - cnt[next];
                    predfs(next, curr, predfs);
                }
            }
        };

        posdfs(0, -1, posdfs);
        predfs(0, -1, predfs);

        return ans;
    }
};
