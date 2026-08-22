
template<typename T>
Array<T>::Array()
	: _array(NULL)
	, _size(0)
{}

template<typename T>
Array<T>::Array(unsigned int n)
	: _array(NULL)
	, _size(n)
{
	if (_size != 0)
		_array = new T[_size];
}

template<typename T>
Array<T>::Array(const Array& other)
	: _array(NULL)
	, _size(other.size())
{
	if (_size != 0) {
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;

	delete[] _array;
	_array = NULL;
	_size = other.size();

	if (_size != 0) {
		_array = new T[_size];

		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other[i];
	}

	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::out_of_range("Array: index out of range");
	return _array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw std::out_of_range("Array: index out of range");
	return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
	_size = 0;
}
