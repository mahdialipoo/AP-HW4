#ifndef UNIQUE_PTR
#define UNIQUE_PTR
template <typename T>
class UniquePtr
{
public:
    UniquePtr(T *);
    UniquePtr();
    ~UniquePtr();

private:
    T *_p;
};
template <typename T>
T *make_unique(T);
#include "unique_ptr.hpp"
#endif // UNIQUE_PTR
