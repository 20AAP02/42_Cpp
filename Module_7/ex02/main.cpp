#include <Array.hpp>

template <typename T>
void printArray(Array<T> arr)
{
	std::cout << "{";
	for (std::size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i];
		if (i != (arr.size() - 1))
			std::cout << ";";
	}
	std::cout << "}";
}

Array<int> a;
Array<int> b(5);
Array<int> c(8);

void printArrays()
{
	std::cout << "Array a: ";
	printArray(a);
	std::cout << std::endl;
	std::cout << "Array b: ";
	printArray(b);
	std::cout << std::endl;
	std::cout << "Array c: ";
	printArray(c);
	std::cout << std::endl;
}

int main()
{
	std::cout << "--- Check current state of the arrays ---\n";
	printArrays();
	std::cout << "--- Update values to zero ---\n";
	for (std::size_t i = 0; i < a.size(); i++)
		a[i] = 0;
	for (std::size_t i = 0; i < b.size(); i++)
		b[i] = 0;
	for (std::size_t i = 0; i < c.size(); i++)
		c[i] = 0;
	printArrays();

	return 0;
}