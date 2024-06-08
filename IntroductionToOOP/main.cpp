//ООП на языке С++
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------\n"

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

	/*Point()
	{
		x = y = 0;
		cout << "deafultConstr\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgConst\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "DoubleArgConst\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "copyConstr\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor\t" << this << endl;
	}

	void print() const
	{
		cout << "x = " << x << "\tY = " << y << endl;
	}

	double distance(const Point& B) const
	{
		//this->x *= 10;
		return sqrt((pow((B.get_x() - this->x), 2)) + (pow((B.get_y() - this->y), 2)));
	}	

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "operator=\t" << this << endl;

		return *this;
	}
};

double distance(const Point& A, const  Point& B)
{
	return sqrt((pow((B.get_x() - A.get_x()), 2)) + (pow((B.get_y() - A.get_y()), 2)));
}

//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
#define ASSIGNMENT_CHECK

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

#if defined CONSTRUCTORS_CHECK
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

	Point C(2, -5);
	//Point D(-4, 3);
	Point D = C;
	C.print();
	D.print();

	Point E;
	E = D;
	E.print();
		
	//cout << "distanceToPoint = " << C.distance(D) << endl;
	//cout << "distanceBetweenPoints = " << distance(C, D) << endl;

#endif

#if defined DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();

	cout << delimiter << endl;
	cout << "distance from A to B " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "distance from B to A " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "distance between A & B " << distance(A, B) << endl;
	cout << delimiter << endl;

#endif

#if defined ASSIGNMENT_CHECK

	int a;
	int b;
	int c;

	a = b = c = 0;

	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;

	cout << delimiter << endl;

	A = B = C = Point(2, 3); //Point(2, 3) - явный вызов конструктора 
	                         //И создается временный безымянный объект
	                         //этот объект и передается как параметр 
	                         //в первый оператор оператор присваивания

	cout << delimiter << endl;
	
	A.print();
	B.print();
	C.print();

	cout << delimiter << endl;

#endif
}