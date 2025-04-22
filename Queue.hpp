#pragma once
#include "Pointer.hpp"

class Queue{
    private:
    /// Pointer to the data
    graph::Pointer ** data;
    int capacity;
    int head;
    int tail;
    int size;
/// Resize function
    void resize ();

public:
        Queue (int startcapacity = 16);
        ~Queue();

        void endQ(graph::Pointer* p); //add to the end
        graph::Pointer* startQ (); //pool from the start
        bool isEmpty() const;
        int getSize () const;
    
};