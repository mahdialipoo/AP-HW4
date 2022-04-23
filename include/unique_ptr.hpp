template <typename T>
UniquePtr<T>::UniquePtr(T *p) { _p = p; };
// Uniqueptr::Uniqueptr(*T _p) : ptr{_p} {}