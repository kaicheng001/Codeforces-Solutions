#include <bits/stdc++.h>

using namespace std;

// Dijkstra 最短路径算法
vector<int> dijkstra(const vector<vector<pair<int, int>>> &graph, int start) {
  int n = graph.size();
  vector<int> dist(n, INT_MAX);
  dist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [current_dist, u] = pq.top();
    pq.pop();

    if (current_dist > dist[u])
      continue;

    for (auto [v, weight] : graph[u]) {
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }

  return dist;
}

// 拓扑排序
vector<int> topological_sort(const vector<vector<int>> &graph) {
  int n = graph.size();
  vector<int> in_degree(n, 0);
  for (int u = 0; u < n; u++) {
    for (int v : graph[u]) {
      in_degree[v]++;
    }
  }

  queue<int> q;
  for (int u = 0; u < n; u++) {
    if (in_degree[u] == 0) {
      q.push(u);
    }
  }

  vector<int> topo_order;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topo_order.push_back(u);

    for (int v : graph[u]) {
      if (--in_degree[v] == 0) {
        q.push(v);
      }
    }
  }

  if (topo_order.size() != n) {
    return {}; // 有环
  }

  return topo_order;
}
