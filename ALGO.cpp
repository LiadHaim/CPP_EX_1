#include "ALGO.hpp"
#include <iostream>
#include <vector>
#include <limits>
#include "Graph.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"

namespace graph{
    
    Graph* creatEmptyGraph(int size){
        return new Graph(size);
    }
    
    Graph* Algorithms::bfs(const Graph& g, int start){
        int n = g.getNumV();
        Graph* tree = creatEmptyGraph(n);
        bool* visited = new bool[n] {false};

        Queue q(n);
        q.endQ(new Pointer (start));
        visited[start] = true;

        while (!q.isEmpty()){
            Pointer* curP = q.startQ();
            int cur = curP -> GetId();
            delete curP;

            Edge* neighbors = g.getNeighbors(cur);
            while(neighbors != nullptr) {
                int next = neighbors-> dest;
                if(!visited[next]){
                    visited[next]  = true;
                    tree -> addEdge(cur, next, neighbors->weight);
                    q.endQ(new Pointer (next));
                }
            neighbors = neighbors-> next;
            }
        }   
        delete[] visited;
        return tree;
    }

    void Algorithms::dfsUtil(const Graph& g, int v, bool* visited, Graph* tree) {
        visited[v] = true;
        Edge* neighbors = g.getNeighbors(v);

        while (neighbors != nullptr) {
            int next = neighbors->dest;
            if (!visited[next]) {
                tree->addEdge(v, next, neighbors->weight);
                dfsUtil(g, next, visited, tree);
            }
            neighbors = neighbors->next;
        }
    }


    Graph* Algorithms::dfs(const Graph& g, int start) {
        int n = g.getNumV();
        Graph* tree = creatEmptyGraph(n);
        bool* visited = new bool[n];
        for (int i=0; i<n; i++){
            visited[i] = false;
        }
        dfsUtil (g, start, visited, tree);
        delete[] visited;
        return tree;

    }
     Graph* Algorithms::dijkstra(const Graph& g, int start) {
        int n = g.getNumV();
        Graph* tree = creatEmptyGraph(n);

        int* dist = new int[n];
        bool* visited = new bool[n]{false};

        for (int i = 0; i < n; i++) dist[i] = 20000;
        dist[start] = 0;

        PriorityQueue pq(n);
        pq.push({start, 0});

        while (!pq.isEmpty()) {
            Node current = pq.pop();
            int u = current.vertex;
            if (visited[u]) continue;
            visited[u] = true;

            Edge* neighbors = g.getNeighbors(u);
            while (neighbors != nullptr) {
                int v = neighbors->dest;
                int w = neighbors->weight;
                if (!visited[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({v, dist[v]});
                    tree->addEdge(u, v, w);
                }
                neighbors = neighbors->next;
            }
        }

        delete[] dist;
        delete[] visited;
        return tree;
    }

    // Prim
    Graph* Algorithms::prime(const Graph& g) {
        int n = g.getNumV();
        Graph* tree = creatEmptyGraph(n);

        bool* visited = new bool[n]{false};
        PriorityQueue pq(n);

        int start = 0;
        visited[start] = true;
        Edge* edges = g.getNeighbors(start);
        while (edges != nullptr) {
            pq.push({edges->dest, edges->weight});
            edges = edges->next;
        }

        while (!pq.isEmpty()) {
            Node current = pq.pop();
            int v = current.vertex;
            if (visited[v]) continue;

            visited[v] = true;
            // Find edge from some visited node to v
            for (int u = 0; u < n; u++) {
                if (visited[u]) {
                    Edge* e = g.getNeighbors(u);
                    while (e != nullptr) {
                        if (e->dest == v) {
                            tree->addEdge(u, v, e->weight);
                            break;
                        }
                        e = e->next;
                    }
                }
            }

            Edge* neighbors = g.getNeighbors(v);
            while (neighbors != nullptr) {
                if (!visited[neighbors->dest]) {
                    pq.push({neighbors->dest, neighbors->weight});
                }
                neighbors = neighbors->next;
            }
        }

        delete[] visited;
        return tree;
    }

    // Kruskal
    Graph* Algorithms::kruskal(const Graph& g) {
        int n = g.getNumV();
        Graph* tree = creatEmptyGraph(n);

        // Count total number of edges
        int totalEdges = 0;
        for (int i = 0; i < n; i++) {
            Edge* e = g.getNeighbors(i);
            while (e != nullptr) {
                if (i < e->dest) totalEdges++;
                e = e->next;
            }
        }

        // Create edge list
        struct EdgeItem {
            int u, v, w;
        };
        EdgeItem* edges = new EdgeItem[totalEdges];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            Edge* e = g.getNeighbors(i);
            while (e != nullptr) {
                if (i < e->dest) {
                    edges[idx++] = {i, e->dest, e->weight};
                }
                e = e->next;
            }
        }
        

        // Sort edges by weight (simple bubble sort since STL not allowed)
        for (int i = 0; i < totalEdges - 1; i++) {
            for (int j = 0; j < totalEdges - i - 1; j++) {
                if (edges[j].w > edges[j + 1].w) {
                    EdgeItem temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        UnionFind uf(n);
        for (int i = 0; i < totalEdges; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            if (uf.find(u) != uf.find(v)) {
                uf.unite(u, v);
                tree->addEdge(u, v, w);
            }
        }

        delete[] edges;
        return tree;
    }

}



