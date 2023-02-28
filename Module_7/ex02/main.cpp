#include <Array.hpp>

// Int
Array<int> a;
Array<int> b(5);
Array<int> c(8);

// String
Array<std::string> d;
Array<std::string> e(5);
Array<std::string> f(8);


void printIntArrays()
{
	std::cout << "Array a: ";
	std::cout << "{";
	for (std::size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i];
		if (i != (a.size() - 1))
			std::cout << ";";
	}
	std::cout << "}";
	std::cout << std::endl;
	std::cout << "Array b: ";
	std::cout << "{";
	for (std::size_t i = 0; i < b.size(); i++)
	{
		std::cout << b[i];
		if (i != (b.size() - 1))
			std::cout << ";";
	}
	std::cout << "}";
	std::cout << std::endl;
	std::cout << "Array c: ";
	std::cout << "{";
	for (std::size_t i = 0; i < c.size(); i++)
	{
		std::cout << c[i];
		if (i != (c.size() - 1))
			std::cout << ";";
	}
	std::cout << "}";
	std::cout << std::endl;
}

void printStringArrays()
{
	std::cout << "Array d: ";
	std::cout << "{";
	for (std::size_t i = 0; i < d.size(); i++)
	{
		std::cout << d[i];
		if (i != (d.size() - 1))
			std::cout << ";";
	}
	std::cout << "}";
	std::cout << std::endl;
	std::cout << "Array e: ";
	std::cout << "{";
	for (std::size_t i = 0; i < e.size(); i++)
	{
		std::cout << e[i];
		if (i != (e.size() - 1))
			std::cout << ";";
	}
	std::cout << "}";
	std::cout << std::endl;
	std::cout << "Array f: ";
	std::cout << "{";
	for (std::size_t i = 0; i < f.size(); i++)
	{
		std::cout << f[i];
		if (i != (f.size() - 1))
			std::cout << ";";
	}
	std::cout << "}";
	std::cout << std::endl;
}

int main()
{
	{
		std::cout << "__________Int_Arrays___________\n";
		std::cout << "--- Check current state of the arrays ---\n";
		printIntArrays();
		std::cout << "--- Check value assignment ---\n";
		b[2] = 6;
		b[3] = 5;
		c[1] = 3;
		try
		{
			a[0] = 7;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		printIntArrays();
		std::cout << "--- Check copy assignments ---\n";
		a = b;
		c = b;
		printIntArrays();
	}
	{
		std::cout << "_________String_Arrays__________\n";
		std::cout << "--- Check current state of the arrays ---\n";
		printStringArrays();
		std::cout << "--- Check value assignment ---\n";
		e[2] = "ola";
		e[3] = "mundo";
		f[1] = "hello";
		try
		{
			d[0] = "luis";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		printStringArrays();
		std::cout << "--- Check copy assignments ---\n";
		d = e;
		f = e;
		printStringArrays();
	}

	return 0;
}