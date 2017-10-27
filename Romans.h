//
// Created by Carson on 10/27/2017.
//
#ifndef HW_5_BARATHEON_ROMANS_H
#define HW_5_BARATHEON_ROMANS_H
#include <iostream>
using namespace std;

class Romans
{
private:
    unsigned int value;
public:
    Romans();
    Romans(const string &roman);

    void convertFromRoman(const string &str);
    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Romans&);  //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members.
};

// Function Prototypes
void testConstructor();

#endif //HW_5_BARATHEON_ROMANS_H
