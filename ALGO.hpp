// liadi.haim@gmail.com

#pragma once
#include "Graph.hpp"

namespace graph{

    class Algorithms{
        public:
        static Graph* bfs(const Graph& g, int startV);
        static Graph* dfs(const Graph& g, int startV);
        static Graph* dijkstra(const Graph& g, int startV);
        static Graph* prime(const Graph& g);
        static Graph* kruskal(const Graph& g);
        private:
        static void dfsUtil(const Graph& g, int v, bool* visited, Graph* tree);
    };       

}