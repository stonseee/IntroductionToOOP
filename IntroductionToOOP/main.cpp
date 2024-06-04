//��� �� ����� �++
#include<iostream>
using namespace std;

class Point
{
private:

	double x;
	double y;

public:

	double get_x() const
	{
		return x;
	}

	double get_y() const
	{
		return y;
	}

	void set_x(double x)
	{
		this->x = x;
	}

	void set_y(double y)
	{
		this->y = y;
	}

	Point()
	{
		x = y = 0;
		cout << "deafultConstr\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgConst\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "DoubleArgConst\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor\t" << this << endl;
	}

	void print() const
	{
		cout << "x = " << x << "\tY = " << y << endl;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
	
#if defined STRUCT_POINT
	Point A;
	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;

	cout << pA->x << "\t" << pA->y << endl;
#endif

	Point A;
	//A.set_x(2);
	//A.set_y(3);	
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	/*for (int i = 0; i < 10; ++i)
	{
		cout << i << "\t";
	}*/

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();
}