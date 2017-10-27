//
// Created by 17cty on 10/26/2017.
//

#ifndef HW_5_BARATHEON_CLASSTESTDONOTUSE_H
#define HW_5_BARATHEON_CLASSTESTDONOTUSE_H

#include <iostream>
using namespace std;

// Class definition
class Roman
{
private:
    unsigned int value;
    string convertToRoman() const;  //The method that helps us take an integer and turn it into a roman numeral
    void convertFromRoman(const string &str);  //The method that helps us take an roman numeral in a string and convert it into the integer.

public:
    Roman();
    Roman(const string &roman);  //The constructor which accepts a string and  converts it internally to an integer.  It actually just forwards it onto convertFromRoman()

    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Roman&);  //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members.
};

// Function Prototypes
void testConstructor();

#endif //HW_5_BARATHEON_CLASSTESTDONOTUSE_H
