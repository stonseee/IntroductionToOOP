#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

//объ€вление класса
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

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

