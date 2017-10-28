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
    Romans(const string &roman);

    void convertFromRoman(const string &str);

    Romans operator+(const Romans &r1) const; //The left and right operands are Roman objects
    Romans operator+(const int dec) const; //The left operand is a Roman object, the right is an int number.

    //These two are for testing purposes only
    friend bool checkTest(string, int, const Romans&);
    friend void testOutput();

};

// Function Prototypes
void testConstructor();
void testOperatorPlus();

#endif //HW_5_BARATHEON_ROMANS_H
