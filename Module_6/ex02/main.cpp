# include <RealType.hpp>

int main()
{
	Base *a = generate();
	Base *b = generate();
	Base *c = generate();
	Base &d = *a;
	Base &e = *b;
	Base &f = *c;

	std::cout << "--- Testing identify() with pointer ---\n";
	identify(a);
	identify(b);
	identify(c);
	std::cout << "--- Testing identify() with reference ---\n";
	identify(d);
	identify(e);
	identify(f);

	
	delete a;
	delete b;
	delete c;

	return 0;
}