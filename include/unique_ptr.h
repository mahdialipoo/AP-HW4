#ifndef UNIQUE_PTR
#define UNIQUE_PTR
template <typename T>
class UniquePtr
{
public:
    UniquePtr(T *);
    UniquePtr();
    UniquePtr(const UniquePtr<T> &);
    ~UniquePtr();
    T *get();
    T operator*();
    void reset();
    UniquePtr<T> operator=(const UniquePtr<T> &);
    void reset(T *);
    operator bool();
    T *operator->();
    T *release();
    //  UniquePtr(const UniquePtr<T> &);

private:
    T *_p;
};
template <typename T>
T *make_unique(T);
#include "unique_ptr.hpp"
#endif // UNIQUE_PTR
