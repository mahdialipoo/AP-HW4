#ifndef SHARED_PTR
#define SHARED_PTR
template <typename T>
class SharedPtr
{
public:
    SharedPtr(T *);
    SharedPtr();
    ~SharedPtr();
    T *get();
    T operator*();
    void reset();
    void reset(T *);
    operator bool();
    T *operator->();

private:
    T *_p;
    size_t cn;
};
template <typename T>
T *make_shared(T);
#include "shared_ptr.hpp"

#endif // SHARED_PTR