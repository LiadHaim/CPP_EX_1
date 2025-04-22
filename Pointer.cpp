#include <iostream>
#include "Pointer.hpp"
namespace graph {
/// Constructor
int Pointer::GetId() const {
    return id;
}
/// Destructor
void Pointer::SetId(int newId) {
    id = newId;
}
/// Destructor
bool Pointer::operator==(const Pointer& other) const {
    return id == other.id;
}
/// Print function
void Pointer::print() const{
    std::cout << "(" << id << ")";
}

}