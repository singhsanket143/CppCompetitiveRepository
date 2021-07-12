from collections import deque

n, m, d = [int(x) for x in input().split()]
graph = [[] for i in range(n)]
min_wt, max_wt = float('inf'), -float('inf')
for i in range(m):
    src, dest, wt = [int(x) for x in input().split()]
    min_wt = min(wt, min_wt)
    max_wt = max(wt, max_wt)
    graph[src-1].append((dest-1, wt))


lo, hi = min_wt, max_wt
ans = -1
parent = [-1]*n

def bfs(src, dest, d, mid):
    qu = deque([])
    qu.append(src)
    visited = [False]*n 
    dist = [-1]*n
    dist[src] = 0
    parent[src] = src 
    while not len(qu) <= 0:
        curr = qu.popleft()
        for neighbour in graph[curr]:
            if not visited[neighbour[0]]:
                if neighbour[1] <= mid:
                    visited[neighbour[0]] = True 
                    qu.append(neighbour[0])
                    dist[neighbour[0]] = dist[curr] + 1
                    parent[neighbour[0]] = curr
    
    return (dist[dest], parent)

while lo <= hi:
    mid = lo + (hi - lo)//2
    result = bfs(0, n-1, d, mid)
    if result[0] == -1 or result[0] > d:
        lo = mid + 1
    else:
        ans = result[0]
        parent = result[1]
        hi = mid - 1

print(ans)
if(ans != -1):
    vertex = n-1
    path = []
    while parent[vertex] != vertex:
        path.append(vertex+1)
        vertex = parent[vertex]
    
    path.append(vertex+1)
    path.reverse()
    for i in path:
        print(i, end = " ")








