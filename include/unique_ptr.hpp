template <typename T>
UniquePtr<T>::UniquePtr(T *p) : _p{p} {}
template <typename T>
T *make_unique(T x) { return new T{x}; }
template <typename T>
UniquePtr<T>::UniquePtr() : UniquePtr<T>(nullptr) {}
template <typename T>
UniquePtr<T>::~UniquePtr()
{
    if (_p != nullptr)
        delete _p;
}
template <typename T>
T *UniquePtr<T>::get()
{
    return _p;
}
template <typename T>
void UniquePtr<T>::reset()
{
    if (_p != nullptr)
        delete _p;
    _p = nullptr;
}
template <typename T>
void UniquePtr<T>::reset(T *x)
{
    _p = x;
}
template <typename T>
T *UniquePtr<T>::operator->()
{
    return _p;
}
template <typename T>
T UniquePtr<T>::operator*()
{
    return *_p;
}
template <typename T>
UniquePtr<T>::operator bool()
{
    return _p;
}
template <typename T>
T *UniquePtr<T>::release()
{
    T *s{_p};
    _p = nullptr;
    return s;
}