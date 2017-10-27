//
// Created by 17cty on 10/26/2017.
//

#include "Roman.h"

//This helps with testing, do not modify.
void testConstructor()
{
    //Test to make sure that empty objects are set to zero.
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    Roman a("LXVI");
    checkTest("testConstructor #2", 66, a);

    //Test a bigger number.
    Roman b("MMMDDCCLLXXVVII");
    checkTest("testConstructor #3", 4332, b);
}


//This helps with testing, do not modify.
bool checkTest(string testName, int whatItShouldBe, const Roman& obj )
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
 * Default constructor
 */
Roman::Roman()
{
    value = 0;
}
/*! Constructor with 1 argument
 *  Take in a roman numeral, convert to integer
 */
Roman::Roman(const string &str)
{
    convertFromRoman(str);
}
/*! Function: Convert Roman numerals to integers */
void Roman::convertFromRoman(const string &roman)
{
    cout << "Roman number " << roman << endl;
    // Do logic to transform a roman number to a decimal number
    // LXVI = 66;
    value = 66;
}

/*!
 * Function: Convert integer to roman numeral
 * @return
 */
string Roman::convertToRoman() const
{
    return std::string();
}

/*!
 * Function: Convert integers to roman numerals
 */
/*string Roman::convertToRoman() const
{
    return std::string();
}*/

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