//
// Created by Owner on 10/26/2017.
//

#ifndef HW_5_BARATHEON_CLASSROMANNUM_H
#define HW_5_BARATHEON_CLASSROMANNUM_H
#include <string>
#include <iostream>
using namespace std;

class Roman
{
private:
    unsigned int value;  //The roman numeral itself isn't stored.  Instead, we just store the integer that corresponds to it.
    string romanNum;
    string convertToRoman() const;  //The method that helps us take an integer and turn it into a roman numeral
    void convertFromRoman(const string&);  //The method that helps us take an roman numeral in a string and convert it into the integer.
public:
    Roman() : value(0) {}  //The default constructor that allows us to make empty objects.
    Roman(const string&): string(romanNum){stoi(romanNum);}  //The constructor which accepts a string and  converts it internally to an integer.  It actually just forwards it onto convertFromRoman()

    Roman operator+(const Roman&) const;  //The left and right operands are Roman objects
    Roman operator+(const int) const; //The left operand is a Roman object, the right is an int number.
    friend Roman operator +(const int, const Roman&);  //The left operand is an int, the right operand is a Roman object.
    void operator +=(const Roman&);  //The left and right operands are Roman objects, but the left operand can change.
    void operator +=(const int);  //The left operand is a Roman object, the right is an int number.  The left operand can change.
    Roman operator++();  //The prefix ++ operator

    friend ostream& operator <<(ostream&, const Roman&);  //Displays the roman numeral object.
    friend istream& operator >>(istream&, Roman&);  //Loads in the information into the right operand, which is a roman numeral object.

    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Roman&);  //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members
};


#endif //HW_5_BARATHEON_CLASSROMANNUM_H
