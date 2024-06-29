#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

//объявление класса

class String
{
private:

	int size;
	char* str;

public:

	int get_size()const;
	const char* get_str()const;
	char* get_str();
	
	//constructors
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other)noexcept;
	~String();

	//operators
	String& operator=(const String& other);
	String& operator=(String&& other)noexcept;

	const char& operator[](int idx) const;
	char& operator[](int idx);

	//methods
	void print()const;
};

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

//#define NO_NAME
//#define OPERATOR_PLUS_CHECK
#define CALLING_CONSTRUCTORS

void main()
 {
    setlocale(LC_ALL, "");

#ifdef NO_NAME
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
	//cout << str5 << endl;
#endif // NO_NAME

#ifdef OPERATOR_PLUS_CHECK

	String str1 = "Hello";
	String str2 = "World";

	cout << delimiter << endl;	
	String str3;
	cout << delimiter << endl;
	str3 = str1 + str2;	
	cout << delimiter << endl;	
	cout << str3 << endl;

#endif //OPERATOR_PLUS_CHECK

#ifdef CALLING_CONSTRUCTORS
	
	String str1;
	str1.print();

	//String str2 = 8;
	String str2(8);
	str2.print();

	String str3 = "Hello";
	str3.print();

	String str4(); //no constructor объявляется функция str4() которая возвращает значение типа 'String'
	//str4.print(); 

	String str5{}; //defaultConstructor
	str5.print();

	//любой конструктор можно вызвать () или {}

	//String str6 = str3;
	//String str6(str3);
	String str6{ str3 };
	str6.print();

#endif // CALLING_CONSTRUCTORS



}
