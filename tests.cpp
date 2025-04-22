// liadi.haim@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "Graph.hpp"
#include "ALGO.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"
using namespace graph;

void testGraphBasic() {
    std::cout << "=== Basic Graph Tests ===\n";
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(2,5);
    g.addEdge(3,0);
    g.addEdge(4,3,5);

    std::cout << "Graph:\n";
    g.printGraph();

    std::cout << "Removing edge 0-4:\n";
    g.removeEdge(0, 4);
    g.printGraph();

    try {
        std::cout << "Trying to remove non-existent edge 0-4 again:\n";
        g.removeEdge(0, 4);
    } catch (const std::exception& e) {
        std::cout << "Caught exception as expected: " << e.what() << "\n";
    }
}


void testPriorityQueue() {
    std::cout << "\n=== PriorityQueue Test ===\n";
    PriorityQueue pq;
    pq.push(Node(1, 10));
    pq.push(Node(2, 5));
    pq.push(Node(3, 15));
    pq.push(Node(4, 1));

    while (!pq.isEmpty()) {
        Node n = pq.pop();
        std::cout << "Popped: vertex=" << n.vertex << ", priority=" << n.priority << "\n";
    }
}

void testAlgorithms(Graph& g) {
    std::cout << "\n=== Algorithms Tests ===\n";

    std::cout << "\nBFS Tree:\n";
    Graph* bfsTree = Algorithms::bfs(g, 0);
    bfsTree->printGraph();

    std::cout << "\nDFS Tree:\n";
    Graph* dfsTree = Algorithms::dfs(g, 0);
    dfsTree->printGraph();

    std::cout << "\nDijkstra Tree:\n";
    Graph* dijkstraTree = Algorithms::dijkstra(g, 0);
    dijkstraTree->printGraph();

    std::cout << "\nPrim Tree:\n";
    Graph* primTree = Algorithms::prime(g);
    primTree->printGraph();

    std::cout << "\nKruskal Tree:\n";
    Graph* kruskalTree = Algorithms::kruskal(g);
    kruskalTree->printGraph();
}

int main() {
    testGraphBasic();
    testPriorityQueue();

    // בונים גרף לבדיקה על האלגוריתמים
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 4, 3);
    g.addEdge(4, 3, 4);
    g.addEdge(3, 5, 11);

    testAlgorithms(g);

    return 0;
}