#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

class String
{
private:

	int size;
	char* str;

public:

	int get_size()const
	{
		return this->size;
	}
	const char* get_str()const
	{
		return this->str;
	}
	char* get_str()
	{
		return this->str;
	}
	
	//constructors
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "defaultConstructor\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "constructor\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "copyConstructor" << this << endl;

	}
	~String()
	{		
		delete[] str;
		cout << "destructor\t\t" << this << endl;
	}

	//operators
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];		
		cout << "copyAssignment\t\t" << this << endl;
		return *this;
	}

	char operator[](const int idx) const
	{
		return this->str[idx];
	}

	char& operator[](const int idx)
	{
		return this->str[idx];
	}

	//methods
	void print()const
	{
		cout << "obj:\t\t\t" << this << endl;
		cout << "size:\t\t\t" << size << endl;
		cout << "addr:\t\t\t" << &str << endl;
		cout << "str:\t\t\t" << str << endl;
		cout << delimiter << endl;
	}
};

String operator+(const String& left, const String& right)
{
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

void main()
{
    setlocale(LC_ALL, "");

	String str1;
	str1.print();

	//String str2 = 8;
	String str2(8);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = "World";
	str4.print();

	cout << str3 << endl;
	cout << str4 << endl;

	//String str5 = str3 + str4;
	String str5;
	str5 = str3 + str4;
	str5.print();
	cout << str5 << endl;
}