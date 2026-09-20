class Solution {
public:

    bool isSafe(int node, int color[], bool graph[101][101],
                int n, int col) {

        for(int k = 0; k < n; k++) {

            if(k != node && graph[k][node] == 1 && color[k] == col) {
                return false;
            }
        }

        return true;
    }


    bool solve(int node, int color[], int m, int N,
               bool graph[101][101]) {

        if(node == N) {
            return true;
        }

        for(int i = 1; i <= m; i++) {

            if(isSafe(node, color, graph, N, i)) {

                color[node] = i;

                if(solve(node + 1, color, m, N, graph))
                    return true;

                color[node] = 0;
            }
        }

        return false;
    }


    bool graphColoring(int V, vector<vector<int>>& edges, int m) {

        bool graph[101][101] = {false};

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        int color[101] = {0};

        if(solve(0, color, m, V, graph))
            return true;

        return false;
    }
};