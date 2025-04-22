// liadi.haim@gmail.com
#include <iostream>
#include "Graph.hpp"
#include "ALGO.hpp"
#include "Pointer.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"

using namespace graph;

void addRandomEdges(Graph& g, int numEdges) {
    // הוספת קשתות אקראיות לגרף
    for (int i = 0; i < numEdges; ++i) {
        int source = rand() % g.getNumV();
        int dest = rand() % g.getNumV();
        int weight = rand() % 10 + 1;  // משקל אקראי בין 1 ל-10
        g.addEdge(source, dest, weight);
    }
}

void printGraphDetails(const Graph& g) {
    std::cout << "Graph Details:\n";
    g.printGraph();
    std::cout << "Number of Vertices: " << g.getNumV() << "\n";
}

int main() {
    std::cout << "=============================\n";
    std::cout << "     Demo of Graph Project   \n";
    std::cout << "=============================\n\n";

    // יצירת גרף עם 5 קודקודים
    Graph g(5);
    
    // הוספת קשתות אקראיות
    addRandomEdges(g, 7);  // הוספת 7 קשתות אקראיות

    // הצגת הגרף
    std::cout << "Original Graph with Random Edges:\n";
    printGraphDetails(g);
    std::cout << "\n";

    // חיפוש BFS
    std::cout << "=== BFS Tree from Node 0 ===\n";
    Graph* bfsTree = Algorithms::bfs(g, 0);
    bfsTree->printGraph();
    std::cout << "\n";

    // חיפוש DFS
    std::cout << "=== DFS Tree from Node 0 ===\n";
    Graph* dfsTree = Algorithms::dfs(g, 0);
    dfsTree->printGraph();
    std::cout << "\n";

    // חיפוש דייקסטרה
    std::cout << "=== Dijkstra Tree from Node 0 ===\n";
    Graph* dijkstraTree = Algorithms::dijkstra(g, 0);
    dijkstraTree->printGraph();
    std::cout << "\n";

    // עץ מינימלי של פרים
    std::cout << "=== Prim's Minimum Spanning Tree ===\n";
    Graph* primTree = Algorithms::prime(g);
    primTree->printGraph();
    std::cout << "\n";

    // עץ מינימלי של קרוסקאל
    std::cout << "=== Kruskal's Minimum Spanning Tree ===\n";
    Graph* kruskalTree = Algorithms::kruskal(g);
    kruskalTree->printGraph();
    std::cout << "\n";

    // ניקוי זיכרון
    delete bfsTree;
    delete dfsTree;
    delete dijkstraTree;
    delete primTree;
    delete kruskalTree;

    std::cout << "Demo finished successfully.\n";
    return 0;
}
