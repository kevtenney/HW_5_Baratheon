//
// Created by 17cty on 10/26/2017.
//

#ifndef HW_5_BARATHEON_CLASSTESTDONOTUSE_H
#define HW_5_BARATHEON_CLASSTESTDONOTUSE_H

#include <iostream>
using namespace std;

// Class defintion
class Roman
{
private:
    unsigned int value;
public:
    Roman();

    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Roman&);  //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members.
};

// Function Prototypes
void testConstructor();

#endif //HW_5_BARATHEON_CLASSTESTDONOTUSE_H
