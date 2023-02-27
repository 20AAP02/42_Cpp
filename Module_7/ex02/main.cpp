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

int main()
{
	Array<int> a;
	Array<int> b(5);
	Array<int> c(8);

	std::cout << "--- Check current state of the arrays ---\n";
	std::cout << "Array a: ";
	printArray(a);
	std::cout << std::endl;
	std::cout << "Array b: ";
	printArray(b);
	std::cout << std::endl;
	std::cout << "Array c: ";
	printArray(c);
	std::cout << std::endl;
	

	return 0;
}