//
// Created by Carson on 10/27/2017.
//
#include "Romans.h"

/*!
 * Checks for compatibility of constructors
 */
void testConstructor()
{
    //Test to make sure that empty objects are set to zero.
    Romans blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    Romans a("LXVI");
    checkTest("testConstructor #2", 66, a);

    //Test a bigger number.
    Romans b("MMMDDCCLLXXVVII");
    checkTest("testConstructor #3", 4332, b);

}
/*!
 * Checks if constructors pass/work
 * @param testName Test 1, 2, or 3
 * @param whatItShouldBe The expected result
 * @param obj Class variable
 * @return Whether it passes
 */
//This helps with testing, do not modify.
bool checkTest(string testName, int whatItShouldBe, const Romans& obj )
{
    if (whatItShouldBe == obj.value)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< obj.value << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}
/*!
 * Helps with testing the constructor
 * @param testName
 * @param whatItShouldBe
 * @param whatItIs
 * @return
 */
//This helps with testing, do not modify.
bool checkTest(string testName, string whatItShouldBe, string whatItIs )
{
    if (whatItShouldBe == whatItIs)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< whatItIs << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}

/*!
 * Default constructor
 * Set value to zero
 */
Romans::Romans()
{
    value = 0;
}

/*!
 *
 * @param roman
 */
Romans::Romans(const string &roman)
{
    convertFromRoman(roman);
}

/*!
 * Convert the roman numeral to an decimal number
 * @param str The roman numeral string being passed in
 */
void Romans::convertFromRoman(const string &str)
{
    cout << "Roman number " << str << endl;
    int i =0, amount= 0;

    // Do logic to transform a roman number to a decimal number
    // LXVI = 66;
    i = str.length();
    for (int j = 0; j < i; j++)
    {
        char c = str.at(j);
        switch (c)
        {
            case 'I':
                amount += 1;
                break;
            case 'V':
                amount += 5;
                break;
            case 'X':
                amount += 10;
                break;
            case 'L':
                amount += 50;
                break;
            case 'C':
                amount += 100;
                break;
            case 'D':
                amount += 500;
                break;
            case 'M':
                amount +=1000;
                break;
            default:
                cout << " ERROR ";
        }
    }
    value = amount;
    cout << "Decimal value: " << amount << endl;


    //value = 66;
}
