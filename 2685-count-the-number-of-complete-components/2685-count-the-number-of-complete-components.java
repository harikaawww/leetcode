class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; ++i)
            graph.add(new ArrayList<>());

        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }

        boolean[] visited = new boolean[n];
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                List<Integer> component = new ArrayList<>();
                dfs(graph, i, visited, component);

                // Check if this component is complete
                boolean isComplete = true;
                int size = component.size();
                for (int node : component) {
                    if (graph.get(node).size() != size - 1) {
                        isComplete = false;
                        break;
                    }
                }
                if (isComplete)
                    count++;
            }
        }

        return count;
    }

    private void dfs(List<List<Integer>> graph, int u, boolean[] visited, List<Integer> component) {
        visited[u] = true;
        component.add(u);
        for (int v : graph.get(u)) {
            if (!visited[v])
                dfs(graph, v, visited, component);
        }
    }
}