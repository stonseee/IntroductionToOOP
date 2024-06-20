#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

class String
{
private:

	int SIZE;
	char* str;

public:

	int get_size()
	{
		return this->SIZE;
	}
	char* get_string()
	{
		return this->str;
	}

	void set_size(int SIZE)
	{
		this->SIZE = SIZE;
	}
	void set_string(const char* str)
	{		
		this->SIZE = strnlen_s(str, INT_MAX) + 1;			
		delete[] this->str;
	    this->str = new char[this->SIZE];
		strcpy_s(this->str, SIZE, str);	
	}

	//constructors
	String() : String(80)
	{
		cout << "defaultConstructor\t" << this << endl;
	}
	String(int SIZE)
	{
		this->SIZE = SIZE + 1;
		this->str = new char[this->SIZE];
		cout << "sizeArgumentConstructor\t" << this << endl;
	}
	String(const char* str) : String(strnlen_s(str, INT_MAX))
	{		
		strcpy_s(this->str, this->SIZE, str);
		cout << "charArgumentConstructor\t" << this << endl;
	}	
	~String()
	{
		delete[] str;
		cout << "destructor\t" << this << endl;
	}	
};

//operators
String operator+(String& left, String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	strcpy_s(result.get_string(), left.get_size(), left.get_string());
	strcpy_s(result.get_string() + left.get_size() - 1, right.get_size(), right.get_string());
	return result;
}

std::ostream& operator<<(ostream& output, String& obj)
{
	output << "(" << obj.get_string() << ")";
	return output;
}

std::istream& operator>>(istream& input, String& obj)
{
	input >> obj.get_string();
	return input;
}

void main()
{
    setlocale(LC_ALL, "");

	String str1;		
	cout << str1 << endl;

	String str2(8);
	cout << str2 << endl;

	String str3 = "Hello";		
	cout << str3 << endl;
	
	String str4 = "World";
	cout << str4 << endl;

	String str5 = str3 + str4;
	cout << str5 << endl;
}
