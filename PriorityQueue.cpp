// liadi.haim@gmail.com

#include "PriorityQueue.hpp"

namespace graph{
    // Constructor
    PriorityQueue::PriorityQueue (int size) : capacity(size), count(0){
        data = new Node[capacity];
    }
    // Destructor
    PriorityQueue::~PriorityQueue(){
        delete[] data;
    }
    // Swap function
    void PriorityQueue:: swap(int i, int j){
        Node temp =data[i];
        data[i]= data[j];
        data [j] = temp;
    }
    // Heap up function
    void PriorityQueue::heapUp(int index){
        while (index > 0){
            int dad = (index -1)/2;
            if(data[index].priority < data[dad].priority){
                swap(index, dad);
                index = dad;
            }
            else{
                break;
            }
        }
        
    }
        // Heap down function
    void PriorityQueue:: heapDown(int index){
        while (2* index +1 < count){
            int left = 2*index + 1;
            int right = 2*index + 2;
            int smallest = index;

            if(left < count && data[left].priority < data[smallest].priority) smallest = left;
            if(right < count && data[right].priority < data[smallest].priority) smallest = right;
            if(smallest!= index){
                swap(index, smallest);
                index = smallest;
            }
            else{
                break;
            }
        }
        
    }
    // Push function
    void PriorityQueue:: push(Node node){
        if (count == capacity) return;
        data [count] = node;
        heapUp(count);
        count++;
    }
    // Pop function
    Node PriorityQueue:: pop(){
        if (isEmpty()) return Node (-1, -1);
        Node top = data[0];
        data[0] = data[count -1];
        count--;
        heapDown(0);
        return top;
    }
    // Check if the queue is empty
    bool PriorityQueue:: isEmpty() const{
        return count ==0;
    }

}