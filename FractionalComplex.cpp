//
// Created by Jonathan on 5/4/2019.
//this is the .cpp file for the fractionalcomplex object. it houses all of the code for that class.
//i seperated it into a few different sections, imports and namespace, constructors, methods, operators, and the deconstructor
//it was actually a pretty fun assignment, i learned a lot specifically about the pre/post incriment operators. that was kind of a pain at first
//then i realized "I'm being an idiot" and I fixed it.
//

//*****************************Imports and namespace**************************
#include "FractionalComplex.h"
#include <iostream>

using namespace std;

//***************************CONSTRUCTORS***************************************

//this is the default constructor
FractionalComplex::FractionalComplex()
{
    //defines the basic a,b,c,d values
    a = 0;
    b = 1;
    c = 0;
    d = 1;
}

//this is the two int constructor (x = a, y = c in the form a/b + c/d)
FractionalComplex::FractionalComplex(int x, int y)
{
    //defines the a,b,c,d values
    a = x;
    b = 1;
    c = y;
    d = 1;
}

//this is the 4 int constructor
FractionalComplex::FractionalComplex(int A, int B, int C, int D)
{
    //checks if the denominators are either negative or equal to zero. if they're zero it'll set em to 1 as default
    if (B == 0)
    {
        B = 1;
    }
    if (D == 0)
    {
        D = 1;
    }

    //reduces the fractional values with the reduceFraction method (passes by reference)
    FractionalComplex::reduceFraction(A, B);
    FractionalComplex::reduceFraction(C, D);

    //checks if the denominator is negative or not, then will move the negative from the denominator to the numerator
    if (B < 0)
    {
        A *= -1;
        B *= -1;
    }

    if (D < 0)
    {
        C *= -1;
        D *= -1;
    }

    //sets the values of a,b,c,d
    a = A;
    b = B;
    c = C;
    d = D;
}

//**********************************METHODS********************************************
//uses the GCF to reduce the fractional values, then returns then by passing by reference
//passes the values by reference so it's all encapsulated
void FractionalComplex::reduceFraction(int &a, int &b)
{
//temporary copies of A and B to prevent data error
    int tempA = a;
    int tempB = b;
    bool run = true;

    //runs the loop with a boolean run condtion
    while (run)
    {
        tempA = tempA % tempB;
        if (tempA == 0)
        {
            a = a / tempB;
            b = b / tempB;
            run = false;
        }

        //prevents this part from runing again if the first part finished so it won't error out
        if (run)
        {
            tempB = tempB % tempA;
            if (tempB == 0)
            {
                a = a / tempA;
                b = b / tempA;
                run = false;
            }
        }
    }
}

//the printout method
void FractionalComplex::printme()
{
    cout << "[(" << a << "/" << b << ") + (" << c << "/" << d << ")i]" << endl;
}

//finds the length of a complex number
double FractionalComplex::length(const FractionalComplex &myFraction) const
{
    double firstPart = pow((1.0*myFraction.a / myFraction.b), 2);
    double secondPart = pow((1.0*myFraction.c / myFraction.d),2);
    double length = sqrt(firstPart + secondPart);
    return length;
}

//*************************************OPERATORS***************************************************
FractionalComplex FractionalComplex::operator+(const FractionalComplex& firstFraction) const
{
    FractionalComplex temporary; //tmp obj
    
    int tmp1 = this->a * firstFraction.b; //numerator of first fraction (for the first one being added)
    int tmp2 = this->b * firstFraction.a; //numerator of second fraction (for the first one being added)
    int tmp3 = this->c * firstFraction.d; //numerator of first fraction (for the second one being added)
    int tmp4 = this->d * firstFraction.c; //numerator of second fraction (for the second one being added)

    //adds the numerators together, applies the new common denominator
    temporary.a = tmp1+tmp2;
    temporary.b = this->b * firstFraction.b;

    temporary.c = tmp3+tmp4;
    temporary.d = this->d * firstFraction.d;

    //reduces the values
    temporary.reduceFraction(temporary.a, temporary.b);
    temporary.reduceFraction(temporary.c, temporary.d);

    //checks where the negative is (if there is one) then places it in correct position
    if (temporary.b < 0)
    {
        temporary.a *= -1;
        temporary.b *= -1;
    }

    if (temporary.d < 0)
    {
        temporary.c *= -1;
        temporary.d *= -1;
    }

    return temporary;
}

FractionalComplex FractionalComplex::operator-(const FractionalComplex &firstFraction) const
{
    FractionalComplex temporary; //tmp obj

    int tmp1 = this->a * firstFraction.b; //numerator of first fraction (for the first one being added)
    int tmp2 = this->b * firstFraction.a; //numerator of second fraction (for the first one being added)
    int tmp3 = this->c * firstFraction.d; //numerator of first fraction (for the second one being added)
    int tmp4 = this->d * firstFraction.c; //numerator of second fraction (for the second one being added)

    //adds the numerators together, applies the new common denominator
    temporary.a = tmp1-tmp2;
    temporary.b = this->b * firstFraction.b;

    temporary.c = tmp3-tmp4;
    temporary.d = this->d * firstFraction.d;

    //reduces the values
    temporary.reduceFraction(temporary.a, temporary.b);
    temporary.reduceFraction(temporary.c, temporary.d);

    //checks where the negative is (if there is one) then places it in correct position
    if (temporary.b < 0)
    {
        temporary.a *= -1;
        temporary.b *= -1;
    }

    if (temporary.d < 0)
    {
        temporary.c *= -1;
        temporary.d *= -1;
    }

    return temporary;
}

//returns if they're equal or not
bool FractionalComplex::operator==(const FractionalComplex &firstFraction) const
{
    return (this->a == firstFraction.a) && (this->b == firstFraction.b) && (this->c == firstFraction.c) &&
           (this->d == firstFraction.d);
}

//checks if the first is smaller than the second. i just called it firstfraction, but when it's ran it's actually the second fraction (so this is the first, firstFraction is the second)
bool FractionalComplex::operator<(const FractionalComplex &firstFraction) const
{
    return this->length(*this) < length(firstFraction);
}

//checks if the first is greater than the second
bool FractionalComplex::operator>(const FractionalComplex &firstFraction) const
{
    return this->length(*this) > length(firstFraction);
}

//this returns a fractionalcomplex so it can be used in a cout command
ostream& operator<<(ostream &out, const FractionalComplex &firstFraction)
{
    out << "[(" << firstFraction.a << "/" << firstFraction.b << ") + (" << firstFraction.c << "/" << firstFraction.d << ")i]" << endl;
    return out;
}

//operators for multiplication, overloaded
FractionalComplex FractionalComplex::operator*(const FractionalComplex &firstFraction) const
{
    //multiplies all the terms together so that there can be two seperate temporary complex fractions created
    int tmpA1 = this->a * firstFraction.a;
    int tmpB1 = this->b * firstFraction.b;
    int tmpC1 = this->c * firstFraction.c;
    int tmpD1 = this->d * firstFraction.d;

    int tmpA2 = -1 * this->c * firstFraction.c;
    int tmpB2 = this->d * firstFraction.d;
    int tmpC2 = this->c * firstFraction.a;
    int tmpD2 = this->d * firstFraction.b;

    //stores the terms in two temporary ComplexFractions. by doing this it reduces their values
    FractionalComplex temporary1(tmpA1, tmpB1, tmpC1, tmpD1);
    FractionalComplex temporary2(tmpA2, tmpB2, tmpC2, tmpD2);

    //adds the two temporary complexFractions together
    FractionalComplex temporary = temporary1 + temporary2;

    //returns the final result
    return temporary;
}

//when multiplied by an integer constant
FractionalComplex FractionalComplex::operator*(const int x)
{
    FractionalComplex temporary;

    temporary.a = this->a * x;
    temporary.b = this->b;
    temporary.c = this->c*x;
    temporary.d = this->d;

    //reduces the values
    reduceFraction(temporary.a, temporary.b);
    reduceFraction(temporary.c, temporary.d);

    return temporary;
}

//this is for ++FC
FractionalComplex& FractionalComplex::operator++()
{
    //adds one by simply adding the value of the denominator to the numerator
    this->a = this->a + this->b;
    this->c = this->c + this->d;

    //reduces it
    reduceFraction(this->a, this->b);
    reduceFraction(this->c, this->d);

    return *this;
}

//this is for FC++
const FractionalComplex FractionalComplex::operator++(int)
{
    FractionalComplex temporary(*this);
    operator++();
    return temporary;
}

//***********************************DECONSTRUCTOR********************************************
FractionalComplex::~FractionalComplex()
= default;