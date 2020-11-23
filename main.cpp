/*
 * CS 145 Assignment 4
 * Primary File for use with the FractionalComplex class
 *
 * This file is the primary file for use with the student created
 * class FractionalComplex class.   It is designed to test
 * all of the possible operators needed for that class.
 *
 * it is divded into pieces so that it can be done in sections.
 * each "section" contains different parts of the requirement.
 *
 * Students may only alter this file by removing commented sections
 * as they implement more and more parts of their code.
 * The primary code should be untouched
 */


#include <iostream>
#include "FractionalComplex.h"

using namespace std;

void intro();
void section1();
void section2();
void section3();
void section4();
void section5();
void section6();
void section7();
void section8();

int main()
{
    intro();
	//Uncomment these as you complete various sections.
    section1();
    section2();
    section3();
    section4();
    section5();
    section6();
    section7();
    section8();
}




void intro()
{

    cout << "* Welcome to the testing class for the FractionalComplex number.";
    cout << endl;
    cout << "* By the end of the assignment, every line below must work, but to begin";
    cout << endl;
    cout << "* most of the sections are commented off.  Uncomment each section as you";
    cout << endl;
    cout << "* get more and more to work : Good Luck!" << endl;
    cout << "************************************************************************"<< endl << endl;
}

void section1()
{
    cout << "** Section 1" << endl;
    cout << "Basic creation and printing" << endl << endl;
    FractionalComplex a;
    FractionalComplex b(5, 10);
    FractionalComplex c(1,2,3,4);
    a.printme();
    b.printme();
    c.printme();
}

void section2()
{

    cout << endl << endl;
    cout << "** Section 2" << endl;
    cout << "Reductions " << endl << endl;

    FractionalComplex a;

    a = FractionalComplex(20, 6, 10, 8);
    a.printme();
    a = FractionalComplex(-45, 105, 60, 54);
    a.printme();
    a = FractionalComplex(-2, -4, -12, -8);
    a.printme();
    a = FractionalComplex(1, -4, 2, -10);
    a.printme();

}

void section3()
{

    cout << endl << endl;
    cout << "** Section 3" << endl;
    cout << "Addition " << endl << endl;

    FractionalComplex a, b, c;

    cout << "Sample 1" << endl;
    a = FractionalComplex(1, 2, 3, 4);
    a.printme();
    b = FractionalComplex(1, 3, 5, 4);
    b.printme();

    c = a + b;
    cout << "The sum is : " ;
    c.printme();

    cout << endl << "Sample 2" << endl;
    a = FractionalComplex(1, 6, 2, 8);
    a.printme();
    b = FractionalComplex(-1, 4, 7, 11);
    b.printme();

    c = a + b;
    cout << "The sum is : " ;
    c.printme();
}

void section4()
{

    cout << endl << endl;
    cout << "** Section 4" << endl;
    cout << "Subtraction " << endl << endl;

    FractionalComplex a, b, c;

    cout << "Sample 1" << endl;
    a = FractionalComplex(1, 2, 4, 5);
    a.printme();
    b = FractionalComplex(1, 3, 2, 3);
    b.printme();

    c = a - b;
    cout << "The difference is : " ;
    c.printme();

    cout << endl << "Sample 2" << endl;
    a = FractionalComplex(2, 5, 3, 7);
    a.printme();
    b = FractionalComplex(1, 4, 7, 11);
    b.printme();

    c = a - b;
    cout << "The difference is : " ;
    c.printme();
}

void section5()
{

    cout << endl << endl;
    cout << "** Section 5" << endl;
    cout << "Comparisons " << endl << endl;

    FractionalComplex a, b, c, d;
    a = FractionalComplex(2, 5, 3, 7);
    b = FractionalComplex(2, 5, 3, 7);
    c = FractionalComplex(10, 25, 15, 35);
    d = FractionalComplex(10, 25, 35, 36);

    a.printme();
    b.printme();
    cout << endl << "Test 1: Are they equal? (They should be) : " ;
    if (a == b) {cout << "TRUE!" << endl;}
    else        {cout << "FALSE - Error" << endl;}

    cout << endl;

    a.printme();
    c.printme();
    cout << endl << "Test 2: Are they equal? (They should be) : " ;
    if (a == c) {cout << "TRUE!" << endl;}
    else        {cout << "FALSE - Error" << endl;}

    cout << endl;

    c.printme();
    d.printme();
    cout << endl << "Test 3: Are they equal? (They should not be) : " ;
    if (c == d) {cout << "TRUE - Error" << endl;}
    else        {cout << "FALSE!" << endl;}

    cout << endl;

    a.printme();
    d.printme();

    cout <<endl << "Test 4: Which is bigger? " ;
    if (d < a) {cout << "The First one!  Error" << endl;}
    else if (a < d) {cout << "The second one!  Good Work" << endl;}
    else {cout << "They are equal?? This is an error" << endl;}

    cout << endl;

    a.printme();
    d.printme();

    cout <<endl << "Test 5: Which is smaller? " ;
    if (a > d) {cout << "The second one!  Error" << endl;}
    else if (d > a) {cout << "The first one!  Good Work" << endl;}
    else {cout << "They are equal?? This is an error" << endl;}

}

void section6()
{

    cout << endl << endl;
    cout << "** Section 6" << endl;
    cout << "Cout Println " << endl << endl;

    FractionalComplex a, b;
    a = FractionalComplex(6,4,12,9);
    b = FractionalComplex(1,5,5,6);

    cout << "Testing cout a = " << a;
    cout << endl;
    cout << "Testing a chain b = " << b << " It worked! " << endl;
    cout << endl;
    cout << "Testing inline addition " << a + b << endl;
}

void section7()
{
    cout << endl << endl;
    cout << "** Section 7" << endl;
    cout << "Multiplication " << endl << endl;

    FractionalComplex a, b;
    a = FractionalComplex(1,2,3,5);
    b = FractionalComplex(1,3,2,5);

    cout << "Test #1 " << endl;
    cout << "a = " << a << endl << "b = " << b << endl;
    cout << "a * b = " << a * b << endl;

    a = FractionalComplex(-1,1,2,9);
    b = FractionalComplex(3,5,1,5);

    cout << endl << "Test #2 " << endl;
    cout << "a = " << a << endl << "b = " << b << endl;
    cout << "a * b = " << a * b << endl;

    cout << endl << "Test #3 " << endl;
    cout << "b = " << b << endl;
    cout << "b * 10 = " << b * 10 << endl;


}

void section8()
{
    cout << endl << endl;
    cout << "** Section 8" << endl;
    cout << "Pre and Post increment " << endl << endl;

    FractionalComplex a,b;
    a = FractionalComplex(1,2,1,4);

    cout << "PostFix Test" << endl;
    cout << "a = " << a << endl;
    cout << "a = " << a++ << " This should match above" << endl;
    cout << "a = " << a++ << " This should be one bigger" << endl;
    cout << "a = " << a   << " This should be one bigger" << endl;

    b = FractionalComplex(1,3,1,5);
    cout << "Prefix Test" << endl;
    cout << "b = " << b<< endl;
    cout << "b = " << ++b << " This should be one bigger" << endl;
    cout << "b = " << ++b << " This should be one bigger" << endl;
    cout << "b = " << b   << " This should match above" << endl;
}