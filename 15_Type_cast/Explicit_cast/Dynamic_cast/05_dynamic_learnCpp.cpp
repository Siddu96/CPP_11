#include <iostream>
#include <string>
 
class Base
{
protected:
	int m_value;
 
public:
	Base(int value)
		: m_value(value)
	{
		std::cout << "Base::m_value : " << value << std::endl;
	}
	
	virtual ~Base() {}
};
 
class Derived : public Base
{
protected:
	std::string m_name;
 
public:
	Derived(int value, std::string name)
		: Base(value), m_name(name)
	{
		std::cout << "Derived::m_name : " << m_name << std::endl;
	}
 
	const std::string& getName() { return m_name; }
};
 
Base* getObject(bool bReturnDerived)
{
	if (bReturnDerived)
		return new Derived(1, "Apple");
	else
		return new Base(2);
}
 
int main()
{
	Base *b = getObject(true);
 
	// how do we print the Derived object's name here, having only a Base pointer?
 	Derived *d = dynamic_cast<Derived*> (b);
	std::cout << "The name of the derived is : " << d->getName() << "\n";
	delete b;
 
	return 0;
}
