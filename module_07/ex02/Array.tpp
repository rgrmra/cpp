/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:54:09 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 19:04:06 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

template <typename T> 
Array<T>::Array()
    : _data(new T[0]()), _size(0) {

}

template <typename T>
Array<T>::Array(const unsigned int &size)
    : _data(new T[size]()), _size(size) {

}

template <typename T>
Array<T>::Array(const Array &src)
    : _data(new T[src._size]), _size(src._size) {

    *this = src;
}

template <typename T>
Array<T>::~Array() {

    delete[] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {

    if (this == &rhs)
        return *this;

    delete[] _data;

    _data = new T[rhs._size];
    _size = rhs._size;

    for (std::size_t i = 0; i < rhs._size; ++i)
        _data[i] = rhs._data[i];

    return *this;
}

template <typename T>
unsigned int Array<T>::size() const {

    return this->_size;
}

template <typename T>
T &Array<T>::operator[](const unsigned int &index) {

    if (index < _size)
        return _data[index];

    throw std::out_of_range("Index out of bounds");
}

template <typename T>
T const &Array<T>::operator[](const unsigned int &index) const {

    if (index < _size)
        return _data[index];

    throw std::out_of_range("Index out of bounds");
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &src) {
    std::size_t size = src.size() - 1;

    os << "[ ";
    for (std::size_t i = 0; i < src.size(); i++) {
        os << src[i];
        if (size != i)
            os << ", ";
    }

    return os << " ]";
}
