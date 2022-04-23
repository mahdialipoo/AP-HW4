template <typename T>
UniquePtr<T>::UniquePtr(T *p) { _p = p; };
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
UniquePtr<T>::UniquePtr(const UniquePtr<T> &p)
{
    if (_p != nullptr)
        delete _p;
    _p = p._p;
}