#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define pii pair<int, int>

void dijkstra(vector<vector<pii>> &graph, int startNode, vector<int> &distances)
{
    int numNodes = graph.size();
    distances.assign(numNodes, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    distances[startNode] = 0;

    pq.push({0, startNode});

    while (!pq.empty())
    {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if (currDist > distances[currNode])
        {
            continue;
        }
        for (auto neighbor : graph[currNode])
        {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;
            int totalDist = currDist + edgeWeight;
            if (totalDist < distances[nextNode])
            {
                distances[nextNode] = totalDist;
                pq.push({totalDist, nextNode});
            }
        }
    }
}

int main()
{
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<pii>> graph(numNodes);

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < numEdges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    vector<int> distances;
    dijkstra(graph, startNode, distances);

    cout << "Shortest distances from node " << startNode << ":\n";
    for (int i = 0; i < numNodes; i++)
    {
        cout << "Node " << i << ": ";
        if (distances[i] == INT_MAX)
        {
            cout << "Not reachable\n";
        }
        else
        {
            cout << distances[i] << "\n";
        }
    }

    return 0;
}
