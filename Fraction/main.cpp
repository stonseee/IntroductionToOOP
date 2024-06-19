#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

class Fraction;

Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
private:

    int integer;         //целая часть
    int numerator;       //числитель
    int denominator;     //знаменатель

public:

    int get_integer() const
    {
        return this->integer;
    }
    int get_numerator() const
    {
        return this->numerator;
    }
    int get_denominator() const
    {
        return this->denominator;
    }

    void set_integer(int integer)
    {
        this->integer = integer;
    }
    void set_numerator(int numerator)
    {
        this->numerator = numerator;
    }
    void set_denominator(int denominator)
    {
        if (denominator == 0)denominator = 1;
        this->denominator = denominator;
    }

    //constructors
    Fraction()
    {
        integer = 0;
        numerator = 0;
        set_denominator(1);
        cout << "defaultConstr\t" << this << endl;
    }
    explicit Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        set_denominator(1);
        cout << "singleArgConstructor\t" << this << endl;
    }
    explicit Fraction(double number)
    {
        this->integer = (int)number;
        this->numerator = (number - (int)number) * 1000;
        set_denominator(1000);
        cout << "singleArgConstructor\t" << this << endl;
    }
    Fraction(int numerator, int denominator)
    {
        this->integer = 0;
        this->numerator = numerator;
        set_denominator(denominator);
        cout << "constructor\t" << this << endl;
    }
    Fraction(int integer, int numerator, int denominator)
    {
        set_integer(integer);
        set_numerator(numerator);
        set_denominator(denominator);
        cout << "constructor\t" << this << endl;
    }
    Fraction(const Fraction& other)
    {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        cout << "copyConstructor\t" << this << endl;
    }
    ~Fraction()
    {
        cout << "destructor\t" << this << endl;
    }

    //operators
    Fraction& operator=(const Fraction& other)
    {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        cout << "copyAssignment\t" << this << endl;
        return *this;
    }
    Fraction& operator*=(Fraction& other)
    {        
        return *this = *this * other;
    }
    Fraction& operator/=(Fraction& other)
    {
        return *this = *this / other;
    }
    /*friend istream& operator>>(istream& input, Fraction& obj)
    {
        cout << "input integer:";
        input >> obj.integer;

        cout << "input numerator:";
        input >> obj.numerator;

        cout << "input denominator:";
        input >> obj.denominator;
        return input;
    }*/

    //methods
    Fraction& to_improper()
    {
        this->numerator += this->integer * this->denominator;
        integer = 0;
        return *this;
    }
    Fraction& to_proper()
    {
        this->integer += this->numerator / this->denominator;
        this->numerator %= this->denominator;
        return *this;
    }
    Fraction inverted() const
    {
        Fraction inverted = *this;
        inverted.to_improper();
        swap(inverted.numerator, inverted.denominator);
        return inverted;
    }
    Fraction& reduce()
    {
        int more, less, rest;
        if (numerator > denominator)more = numerator, less = denominator;
        else less = numerator, more = denominator;
        do
        {
            rest = more % less;
            more = less;
            less = rest;            
        } while (rest);
        int GCD = more; //greatest common divisor
        numerator /= GCD;
        denominator /= GCD;
        return *this;
    }
    void print() const
    {
        if (integer)cout << integer;
        if (numerator != 0)
        {
            if (integer)cout << "(";
            cout << numerator << "/" << denominator;
            if (integer)cout << ")";
        }
        else if (integer == 0)cout << 0;
        cout << endl;
    }    
};

Fraction operator*(Fraction left, Fraction right)
{
    /*Fraction result;
    left.to_improper();
    right.to_improper();
    result.set_numerator(left.get_numerator() * right.get_numerator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result.to_proper();*/

    /*left.to_improper();
    right.to_improper();
    Fraction result
    (
        left.get_numerator() * right.get_numerator(),
        left.get_denominator() * right.get_denominator()
    );
    result.to_proper();
    return result;*/

    left.to_improper();
    right.to_improper();
    return Fraction
    (
        left.get_numerator() * right.get_numerator(),
        left.get_denominator() * right.get_denominator()
    ).to_proper().reduce();
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
    return left * right.inverted();
}

// comparison operators
bool operator==(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return
        left.get_numerator() * right.get_denominator() == 
        right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{   
    return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return
        left.get_numerator() * right.get_denominator() > 
        right.get_numerator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return
        left.get_numerator() * right.get_denominator() <
        right.get_numerator() * left.get_denominator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
    return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
    return !(left > right);
}

//std::ostream& operator<<(std::ostream& os, const Fraction& obj)
//{
//    if (obj.get_integer() && (obj.get_numerator() == 0))return os << obj.get_integer() << endl;
//    if (obj.get_numerator() != 0)
//    {
//        if (obj.get_integer())return os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")" << endl;
//        else if (obj.get_integer() == 0)return os << obj.get_numerator() << "/" << obj.get_denominator() << endl;
//    }
//    else if (obj.get_integer() == 0)return os << 0 << endl;
//}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
    if (obj.get_integer())os << obj.get_integer();
    if (obj.get_numerator())
    {
        if (obj.get_integer())os << "(";
        os << obj.get_numerator() << "/" << obj.get_denominator();
        if (obj.get_integer())os << ")";
    }
    else if (obj.get_integer() == 0)os << 0;
    return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
    /*int integer, numerator, denominator;
    is >> integer >> numerator >> denominator;
    obj = Fraction(integer, numerator, denominator);*/
    const int SIZE = 256;
    char buffer[SIZE] = {};
    //is >> buffer;
    is.getline(buffer, SIZE);

    int numbers[3] = {};
    int n = 0;
    const char delimiters[] = " /()";
    for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
        numbers[n++] = atoi(pch);
    //for (int i = 0; i < n; i++) cout << numbers[i] << "\t"; cout << endl;

    switch (n)
    {
    case 1: obj = Fraction(numbers[0]); break;
    case 2: obj = Fraction(numbers[0], numbers[1]); break;
    case 3: obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
    }

    return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define IOSTREAM_CHECK
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
#define CONVERSIONS_HOME_WORK


void main()
{
    setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK

    Fraction A;  //default constuctor
    A.print();

    Fraction B = 5; //single-arg constructor
    B.print();

    Fraction C(1, 2);
    C.print();

    Fraction D(2, 3, 4);
    D.print();

#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
    Fraction A(2, 3, 4);
    A.print();

    Fraction B(3, 4, 5);
    B.print();   

    Fraction C = A * B;
    C.print();

    A *= B;
    A.print();
    A /= B;
    A.print();

#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef IOSTREAM_CHECK

    Fraction pupa;
    cout << (Fraction(1, 2) <= Fraction(5, 10)) << endl;
    cout << Fraction(1, 2) << endl;
    cin >> pupa;
    cout << pupa << endl;

#endif // IOSTREAM_CHECK

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS

    Fraction A = (Fraction)5;
    cout << A << endl;

    cout << delimiter << endl;

    Fraction B;
    cout << delimiter << endl;
    B = Fraction(8);
    cout << delimiter << endl;
    cout << B << endl;

    cout << delimiter << endl;

#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSIONS_HOME_WORK

    Fraction A = Fraction(2.75).reduce();

    cout << A << endl;

#endif // CONVERSIONS_HOME_WORK


};