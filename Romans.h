//
// Created by Carson on 10/27/2017.
//
#ifndef HW_5_BARATHEON_ROMANS_H
#define HW_5_BARATHEON_ROMANS_H
#include <iostream>
#include <string>
using namespace std;

class Romans
{
private:
    unsigned int value;
public:
    Romans();
    Romans(const string& roman);

    void convertFromRoman(const string &str);
    string convertToRoman();

    // Operators
    Romans operator+(const Romans& r1) const; //The left and right operands are Roman objects
    friend Romans operator+(const Romans& r1, const int dec); //The left operand is a Roman object, the right is an int number.
    friend Romans operator+(const int dec, const Romans& r1);

    void operator+=(const Romans&);
    void operator+=(const int);

    Romans operator++();

    // Testing purposes
    friend bool checkTest(string, int, const Romans&);
    friend void testOutput(); //Another test function that needs to access private class members.
};

// Function Prototypes
void testConstructor();
void testOperatorPlus();
void testOperatorPlusEqual();
void testOperatorIncrement();
void testOutput();
#endif //HW_5_BARATHEON_ROMANS_H
