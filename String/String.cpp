#include"String.h"
//определение класса

int String::get_size()const
{
	return this->size;
}
const char* String::get_str()const
{
	return this->str;
}
char* String::get_str()
{
	return this->str;
}

//constructors
String::String(int size) : size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "defaultConstructor\t" << this << endl;
}
String::String(const char str[]) : String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "constructor\t\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "copyConstructor\t\t" << this << endl;
}
String::String(String&& other)noexcept : size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;

	other.size = 0;
	other.str = nullptr;
	cout << "moveConstructor\t\t" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "destructor\t\t" << this << endl;
}

//operators
String& String::operator=(const String& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "copyAssignment\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)noexcept
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "moveAssignment\t\t" << this << endl;
	return *this;
}

const char& String::operator[](int idx) const
{
	return this->str[idx];
}
char& String::operator[](int idx)
{
	return this->str[idx];
}

//methods
void String::print()const
{
	cout << "obj:\t\t\t" << this << endl;
	cout << "size:\t\t\t" << size << endl;
	cout << "addr:\t\t\t" << &str << endl;
	cout << "str:\t\t\t" << str << endl;
	cout << delimiter << endl;
}

String operator+(const String& left, const String& right)
{
	cout << "operator+" << endl;
	String buffer(left.get_size() + right.get_size() - 1);

	for (int i = 0; i < left.get_size(); i++)
	{
		buffer[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
		buffer[i + left.get_size() - 1] = right[i];
	return buffer;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
