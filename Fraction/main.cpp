#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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
    Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        set_denominator(1);
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
    ~Fraction()
    {
        cout << "destructor\t" << this << endl;
    }

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

Fraction& operator*(Fraction& left, Fraction& right)
{
    Fraction result;
    left.to_improper();
    right.to_improper();
    result.set_numerator(left.get_numerator() * right.get_numerator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result.to_proper();
}

Fraction operator/(Fraction& left, Fraction& right)
{
    Fraction result;
    left.to_improper();
    right.to_improper();
    result.set_numerator(left.get_numerator() * right.get_denominator());
    result.set_denominator(left.get_denominator() * right.get_numerator());
    return result.to_proper();
}

Fraction operator+(Fraction& left, Fraction& right)
{
    Fraction result;
    left.to_improper();
    right.to_improper();
    result.set_numerator((left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()));
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result.to_proper();
}

Fraction operator-(Fraction& left, Fraction& right)
{
    Fraction result;
    left.to_improper();
    right.to_improper();
    result.set_numerator((left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()));
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result.to_proper();
}

bool operator==(const Fraction& left, const Fraction& right)
{   
    return (double)left.get_numerator() / (double)left.get_denominator() == (double)right.get_numerator() / (double)right.get_denominator();
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
    if (obj.get_integer() && (obj.get_numerator() == 0))return os << obj.get_integer() << endl;
    if (obj.get_numerator() != 0)
    {
        if(obj.get_integer())return os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")" << endl;
        else if(obj.get_integer() == 0)return os << obj.get_numerator() << "/" << obj.get_denominator() << endl;
    }    
    else if (obj.get_integer() == 0)return os << 0 << endl;
}

//#define CONSTRUCTORS_CHECK

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

    Fraction A(2, 3, 4);
    A.print();

    Fraction B(3, 4, 5);
    B.print();

    A.to_improper().print();
    A.to_proper().print();
    
    Fraction C = A + B;
    C.print();

    Fraction D(1, 2, 3);
    Fraction E(10, 4);
    D.print();
    E.print();

    cout << (D == E) << endl;

    cout << D << endl;
};