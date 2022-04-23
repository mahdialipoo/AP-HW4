#ifndef UNIQUE_PTR
#define UNIQUE_PTR
template <typename T>
class UniquePtr
{
public:
    UniquePtr(T *);
    /* UniquePtr();
     ~UniquePtr();
     friend T *make_unique(T);*/

private:
    T *_p;
};
#include "unique_ptr.hpp"
#endif // UNIQUE_PTR
