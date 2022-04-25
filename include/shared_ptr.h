#ifndef SHARED_PTR
#define SHARED_PTR
#include <map>
template <typename T>
class SharedPtr
{
public:
    SharedPtr(T *);
    SharedPtr();
    ~SharedPtr();
    T *&get();
    T operator*();
    void reset(T * = nullptr);
    operator bool();
    SharedPtr(const SharedPtr<T> &);
    SharedPtr<T> &operator=(const SharedPtr<T> &);
    T *operator->();
    size_t use_count();

private:
    T *_p;
    inline static std::map<T *, size_t> cnts;
};
template <typename T>
T *make_shared(T);
#include "shared_ptr.hpp"

#endif // SHARED_PTR