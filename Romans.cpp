//
// Created by Carson on 10/27/2017.
//
#include "Romans.h"

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
void Romans::convertFromRoman(const string& str)
{
    //cout << "Roman number " << str << endl;
    unsigned int i = 0, amount = 0;

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
                amount += 1000;
                break;
            default:
                cout << " ERROR ";
        }
    }
    value = amount;
    //cout << "Decimal value: " << amount << endl;
}

/*!
 * Converts the value into Roman Numeral form
 * @return: Returns the string of Roman Numerals
 */
//Convert TO Roman
string Romans::convertToRoman()
{
    string roman;
    int i = 0, temp = value;

    while(temp >= 1000)
    {
        roman.insert(i, "M");
        temp -= 1000;
        i++;
    }
    while(temp >= 500)
    {
        roman.insert(i, "D");
        temp -= 500;
        i++;
    }
    while (temp >= 100)
    {
        roman.insert(i, "C");
        temp -= 100;
        i++;
    }
    while (temp >= 50)
    {
        roman.insert(i, "L");
        temp -= 50;
        i++;
    }
    while (temp >= 10)
    {
        roman.insert(i, "X");
        temp -= 10;
        i++;
    }
    while (temp >= 5)
    {
        roman.insert(i, "V");
        temp -= 5;
        i++;
    }
    while (temp >= 1)
    {
        roman.insert(i, "I");
        temp -= 1;
        i++;
    }
    return roman;
}

/*!
 * Overloads + operator to add two different roman values
 * @param r1 Passes in
 * @return
 */
Romans Romans::operator+(const Romans& r1) const
{
    Romans r2;
    r2.value = value + r1.value;
    return r2;
}

/*!
 * Adds a Roman with a decimal/int number
 * @return Return the calculated value
 */
Romans operator+(const Romans& r1, const int dec)
{
    Romans r2;
    r2.value = r1.value + dec;
    return r2;
}

/*!
 * Adds a decimal/int number with a Roman
 * @param dec: decimal number
 * @param r1: Roman number
 * @return: return the calculated value
 */
Romans operator+(const int dec, const Romans& r1)
{
    Romans r2;
    r2.value = dec + r1.value;
    return r2;
}

/*!
 * Plus-Equals Operator. Adds an object to itself
 * @param r1 : the given object
 */
void Romans:: operator+=(const Romans& r1)
{
    value += r1.value;

}

/*!
 * Plus-Equals Operator. Adds a decimal number to itself
 * @param dec : the given decimal
 */
void Romans:: operator+=(const int dec)
{
    value += dec;
}

/*!
 * Increment Operator. Adds 1 to itself as a prefix
 * @return: returns new class
 */
Romans Romans:: operator ++()
{
    Romans r2;
    r2.value = ++value;
    return r2;
}





// Below are tests to ensure the code works.
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
 * @param testName Name/number of test. Used for identification
 * @param whatItShouldBe The expected result
 * @param whatItIs What is return
 * @return Whether whatItIs = whatItShouldBe or not
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
 * Tests adding a roman to a roman and a roman to a decimal number
 */
void testOperatorPlus()
{
    //Test adding two roman objects
    Romans a("XVI");
    Romans b("MDCLXVI");
    Romans c = a + b;
    checkTest("testOperatorPlus #1", 1682, c);
    //make sure the left and right operands weren't modified
    checkTest("testOperatorPlus #2", 16, a);
    checkTest("testOperatorPlus #3", 1666, b);
    //Test adding an object with an int
    c = a + 52;
    checkTest("testOperatorPlus #4", 68, c);
    //make sure the left operand wasn't modified
    checkTest("testOperatorPlus #5", 16, a);
    //Test adding an int with an object
    c = 578 + a;
    checkTest("testOperatorPlus #6", 594, c);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlus #7", 16, a);
}
/*!
 * Tests concatenating two roman numerals together
 */
void testOperatorPlusEqual()
{
    //Test adding two roman objects
    Romans a("MLII");
    Romans b("DDCCI");
    a += b;
    checkTest("testOperatorPlusEqual #1", 2253, a);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlusEqual #2", 1201, b);
    //Test adding on an integer
    b += 17;
    checkTest("testOperatorPlusEqual #3", 1218, b);
}
/*!
 * Test incrementing a roman value by 1
 */
void testOperatorIncrement()
{
    //Test prefix increment
    Romans a("MLII");
    Romans b("DDCCI");
    b = ++a;
    checkTest("testOperatorIncrement #1", 1053, a);
    checkTest("testOperatorIncrement #2", 1053, b);
}
/*!
 * Tests converting TO roman numeral
 */
void testOutput()
{
    Romans a("MDCLXVI");
    string b = a.convertToRoman();
    checkTest("testOutput #1", "MDCLXVI", b);
    //This is really the value 7.  Your code should correctly read this in and convert it back to VII.
    Romans c("IIIIIII");
    b = c.convertToRoman();
    checkTest("testOutput #2", "VII", b);
}