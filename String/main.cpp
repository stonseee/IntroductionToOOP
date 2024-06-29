#include"String.h"
//#define NO_NAME
#define OPERATOR_PLUS_CHECK
//#define CALLING_CONSTRUCTORS

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
