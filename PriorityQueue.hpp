#pragma once
#define MAX_SIZE 1000
namespace graph{
    /// PriorityQueue class for managing nodes with priorities
    struct Node{
        int vertex;
        int priority;
        Node(int v = 0, int p = 0): vertex(v), priority(p){}
    };
    /// PriorityQueue class
    class PriorityQueue{
        private:
        Node* data;
        int capacity;
        int count;
        
        void swap(int i, int j);
        void heapUp (int index);
        void heapDown(int index);
    //helper functions
    public:
    PriorityQueue(int size =100);
    ~PriorityQueue();
        
    void push (Node node);
    Node pop();
    bool isEmpty() const;
};

}