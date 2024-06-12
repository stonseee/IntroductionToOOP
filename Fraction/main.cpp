#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction
{
private:

    double num;       //числитель
    double denom;     //знаменатель

public:

    double get_num() const
    {
        return this->num;
    }

    double get_denom() const
    {
        return this->denom;
    }

    void set_num(double num)
    {
        this->num = num;
    }

    void set_denom(double denom)
    {
        this->denom = denom;
    }

    Fraction(double num = 0, double denom = 0)
    {
        this->num = num;
        this->denom = denom;
        cout << "DoubleArgConst\t" << this << endl;
    }

    Fraction(const Fraction& other)
    {
        this->num = other.num;
        this->denom = other.denom;
        cout << "copyConstr\t" << this << endl;
    }

    ~Fraction()
    {
        cout << "Destructor\t" << this << endl;
    }

    void print() const
    {
        cout << this->num << "/" << this->denom << endl;
    }

    Fraction& operator=(const Fraction& other)
    {
        this->num = other.num;
        this->denom = other.denom;
        cout << "operator=\t" << this << endl;

        return *this;
    }
    
    Fraction& operator++()
    {
        this->num = this->num + this->denom;       

        return *this;
    }

    Fraction operator++(int)
    {
        Fraction old = *this;
        this->num = this->num + this->denom;
        
        return old;
    }
        
    //const Fraction& operator-(const Fraction& f);
    //const Fraction& operator/(const Fraction& f);
    //const Fraction& operator*(const Fraction& f);
    //const Fraction& operator+=(const Fraction& f);
    //const Fraction& operator-=(const Fraction& f);
    //const Fraction& operator*=(const Fraction& f);
    //const Fraction& operator/=(const Fraction& f);
    //Fraction operator-();    
    //friend istream& operator>> (istream& input, Fraction& fr);

};

Fraction operator+(const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.set_num((left.get_num() * right.get_denom()) + (right.get_num() * left.get_denom()));
    result.set_denom(left.get_denom() * right.get_denom());
    return result;
}

bool operator==(const Fraction& left, const Fraction& right)
{ 
    return left.get_num() / left.get_denom() == right.get_num() / right.get_denom();
}


std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
    return os << obj.get_num() << "/" << obj.get_denom();
}

void main()
{
    setlocale(LC_ALL, "");

    Fraction chicago(5, 8);
    Fraction blazer(5, 8);
    Fraction johnny(chicago);
    Fraction starship;     

    //++chicago;
    johnny++;

    starship = chicago + johnny;

    chicago.print();
    johnny.print();
    starship.print();

    cout << (chicago == johnny) << endl;
    cout << (chicago == blazer) << endl;

    cout << chicago << endl;
}