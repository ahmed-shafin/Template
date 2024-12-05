/**
 * Author: chilli
 * Date: 2019-04-26
 * License: CC0
 * Description: Basic Dijkstra
 * Time: O(ElogV)
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */

typedef long long ll;
struct Edge {
    int to;
    ll weight;
    bool operator>(const Edge& other) const {
        if (weight != other.weight) return weight > other.weight;
        return to > other.to;
    }
};

const ll INF = 2e15;
vector<vector<Edge>> adj;

void dijkstra(int source, vector<ll>& dist, vector<int>& parent) {
    const int n = adj.size();
    dist.assign(n, INF);
    parent.assign(n, -1);
    vector<bool> visited(n + 2, false);

    // auto Compare = [&](const auto& a, const auto& b){
    //     return a.second > b.second;
    // };
    // priority_queue<pair<int, ll>, vector<pair<int, ll>>, decltype(Compare)> pq(Compare);

    dist[source] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({source, 0});
    while (!pq.empty()) {
        int from = pq.top().to;
        pq.pop();
        if (visited[from]) continue;
        visited[from] = true;
        for (auto& edge : adj[from]) {
            if (dist[edge.to] > dist[from] + edge.weight) {
                dist[edge.to] = dist[from] + edge.weight;
                parent[edge.to] = from;
                pq.push({edge.to, dist[edge.to]});
            }
        }
    }
}
