#ifndef pointH
#define pointH
#include <string>

namespace graph{


class Pointer{
    
    public:
        int id;
        Pointer(int id){};
        ~Pointer(){};
        int GetId() const;
        void SetId(int NEWid);

        bool operator == (const Pointer& other) const; 

        void print() const;

};
}
#endif;