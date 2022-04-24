template <typename T>
SharedPtr<T>::SharedPtr(T *p) : _p{p} { cn++; }
template <typename T>
T *make_shared(T x) { return new T{x}; }
template <typename T>
SharedPtr<T>::SharedPtr() : SharedPtr<T>(nullptr) {}
template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (_p != nullptr && cn == 1)
    {
        delete _p;
        cn = 0;
    }
} /*
 template <typename T>
 SharedPtr<T>::SharedPtr(const SharedPtr<T> &p)
 {
     throw std::logic_error("error");
 }
 template <typename T>
 SharedPtr<T> SharedPtr<T>::operator=(const SharedPtr<T> &p)
 {
     delete p;
     return p;
 }*/
template <typename T>
T *SharedPtr<T>::get()
{
    return _p;
}
template <typename T>
void SharedPtr<T>::reset()
{
    if (_p != nullptr)
    {
        delete _p;
        cn--;
    }
    _p = nullptr;
}
template <typename T>
void SharedPtr<T>::reset(T *x)
{
    _p = x;
}
template <typename T>
T *SharedPtr<T>::operator->()
{
    return _p;
}
template <typename T>
T SharedPtr<T>::operator*()
{
    return *_p;
}
template <typename T>
SharedPtr<T>::operator bool()
{
    return _p;
}
