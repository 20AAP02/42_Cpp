#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{

	public:

		Array() {
			this->_len = 0;
			this->_arr = NULL;
		}

		Array(unsigned int n) {
			this->_arr = new T(n);
			this->_len = n;
		}

		Array( Array const & src ) {
			this->_len = src.size();
			this->_arr = new T(this->_len);
			for (std::size_t i = 0; i < this->_len; i++)
				this->_arr[i] = src[i];
		}

		~Array() {
			delete[] this->_arr;
		}

		Array &		operator=( Array const & rhs ) {
			if ( this != &rhs )
			{
				delete[] this->_arr;
				this->_len = rhs.size();
				this->_arr = new T(this->_len);
				for (std::size_t i = 0; i < this->_len; i++)
					this->_arr[i] = rhs[i];
			}
			return *this;
		}

		T & 		operator[](std::size_t index) {
			if (static_cast<int>(index) < 0 || index >= this->_len)
				throw Array::OutOfBoundsIndexException();
			else
				return this->_arr[index];
		}

		const T & 		operator[](std::size_t index) const {
			if (static_cast<int>(index) < 0 || index >= this->_len)
				throw Array::OutOfBoundsIndexException();
			else
				return this->_arr[index];
		}

		std::size_t size() const {
			return this->_len;
		}

		class OutOfBoundsIndexException : public std::exception {
			public: virtual const char* what() const throw() {
				return "Index out of bounds!";
			}
		};

	private:
		T *_arr;
		std::size_t _len;
};

#endif /* *********************************************************** ARRAY_H */