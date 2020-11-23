//
// Created by Jonathan on 5/4/2019.
//

#ifndef PROJECT4_FRACTIONALCOMPLEX_H
#define PROJECT4_FRACTIONALCOMPLEX_H

#include <iostream>
using namespace std;

class FractionalComplex
{

private:
    //private variables
    int a, b, c, d;

    //private methods
    void reduceFraction(int &, int &);

public:
    //these are the constructors
    FractionalComplex();
    FractionalComplex(int, int);
    FractionalComplex(int, int, int, int);

    //these are the public methods
    void printme();
    double length(const FractionalComplex&) const;

    //operators
    FractionalComplex operator+(const FractionalComplex&) const;
    FractionalComplex operator-(const FractionalComplex&) const;
    bool operator==(const FractionalComplex&) const;
    bool operator<(const FractionalComplex &) const;
    bool operator>(const FractionalComplex &) const;
    FractionalComplex operator*(const FractionalComplex&) const; //if multiplied by another complex fraction (overloaded)
    FractionalComplex operator*(int); //if multiplied by an integer value (overloaded)

    //this is for the pre-incriment operator (++a)
    FractionalComplex& operator++();


    //this is for the post-incriment operator (a++)
    const FractionalComplex operator++(int);


    //uses a friend so it can be accessed from outside of the actual object (such as cout)
    friend ostream &operator<<(ostream &, const FractionalComplex &);

    //destructor
    virtual ~FractionalComplex();
};



#endif //PROJECT4_FRACTIONALCOMPLEX_H
