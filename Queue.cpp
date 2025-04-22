// liadi.haim@gmail.com

#include "Queue.hpp"

Queue::Queue(int startcapacity) {
    capacity = startcapacity;
    data = new graph::Pointer*[startcapacity];
    for (int i = 0; i < startcapacity; ++i) {
        data[i] = nullptr;  // אתחול חשוב מאוד
    }
    head = 0;
    tail = 0; 
    size = 0;
}
// Destructor
Queue::~Queue() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;

    }
}
// Resize function
void Queue::resize() {
    int newCapacity = capacity * 2;
    graph::Pointer** newData = new graph::Pointer*[newCapacity];
    for (int i = 0; i < newCapacity; ++i) {
        newData[i] = nullptr;
    }

    for (int i = 0; i < size; i++) {
        newData[i] = data[(head + i) % capacity];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
    head = 0;
    tail = size;
}
// Add to the end function
void Queue ::endQ(graph::Pointer *p)
{
    if (size == capacity)
    {
        resize();
    }
    data[tail] = p;
    tail = (tail + 1) % capacity;
    size++;
}
// Pool from the start function
graph::Pointer *Queue::startQ()
{
    if (isEmpty())
    {
        return nullptr;
    }
    graph::Pointer *p = data[head];
    head = (head + 1) % capacity;
    size--;
    return p;
}
// Check if empty function
bool Queue::isEmpty() const
{
    return size == 0;
}
// Get size function
int Queue::getSize() const
{
    return size;
}