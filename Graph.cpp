#include <iostream>
#include "Graph.hpp"
#include "Pointer.hpp"

namespace graph{
    Graph :: Graph (int vers){
        numV =vers;
        List = new Edge*[numV];
        for(int i=0; i< numV; ++i){
            List[i]=nullptr;
        }
    }
    Graph :: ~Graph(){
        for (int i=0; i<numV; ++i){
            Edge* current = List[i];
            while (current != nullptr){
                Edge* temp = current;
                current = current-> next;
                delete temp;
            }  
        }
        delete[] List;
    }
    void Graph::addEdge(int source, int dest, int weight){
        if (source < 0 || source >= numV || dest >= numV || dest < 0) return;
        Edge* newEdge1 = new Edge (dest, weight, List[source]);
        List[source] = newEdge1;
        Edge* newEdge2 = new Edge (source, weight, List[dest]);
        List[dest] = newEdge2;
        
    }

    void Graph::removeEdge(int source, int dest){
        if (source < 0 || source >= numV || dest < 0 || dest >= numV) return;
        Edge* current = List[source];
        Edge* prev = nullptr;
        while(current != nullptr){
            if (current -> dest == dest){
                if(prev == nullptr){
                    List[source] = current-> next;
                }
                else{ prev -> next =  current -> next; }
            
            delete current;
            return;
        }
        prev = current;
        current = current-> next;
        }
    
    }
    void Graph::printGraph() const {
        for (int i = 0; i < numV; ++i) {
            std::cout << "Node " << i << ": ";
            Edge* neighbor = List[i];
            while (neighbor != nullptr) {
                std::cout << neighbor->dest << " ";
                neighbor = neighbor->next;
            }
            std::cout << "\n";
        }
    }

    int Graph::getNumV() const {
        return numV;
    }

    Edge* Graph::getNeighbors(int id) const {
       
        if (id < 0 || id >= numV)
            return nullptr;
        return List[id];
    }

}
