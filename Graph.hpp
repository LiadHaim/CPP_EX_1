// liadi.haim@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace graph{

   struct Edge{
    int dest;
    int weight;
    Edge* next;

    Edge(int dest, int weight, Edge* next = nullptr):dest(dest),weight(weight),next(next) {}    
   };
   class Graph{
   private:
      int numV;
      Edge** List;
   public:
      Graph(int vertices);
      ~Graph();
      void addEdge(int source, int dest, int weight=1);
      void removeEdge(int source, int dest);
      int getNumV() const;
      Edge* getNeighbors(int vertex) const;
      void printGraph() const;
   };
   
}

#endif
