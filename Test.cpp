/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	
    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
													 "$+$\n"
													 "$+$\n\n"
													 "$+$\n\n"
													 "$$$"));

    CHECK(nospaces(mat(5, 15, 'm', 't')) == nospaces("mmmmm\n"
                                                     "mtttm\n"
                                                     "mtmtm\n"
                                                     "mtmtm\n"
                                                     "mtmtm\n"
                                                     "mtmtm\n"
                                                     "mtmtm\n"
                                                     "mtmtm\n"
                                                     "mtmtm\n"
                                                     "mtmtm\n"
                                                     "mtmtm\n"
                                                     "mtmtm\n"
                                                     "mtmtm\n"
                                                     "mtttm\n"
                                                     "mmmmm"));
                                                     
    CHECK(nospaces(mat(1, 1, '#', '-')) == nospaces("#"));
    
    CHECK(nospaces(mat(3, 3, '@', '*')) == nospaces("@@@\n"
                                                     "@*@\n"
                                                     "@@@"));

    CHECK(nospaces(mat(5, 5, '&', '^')) == nospaces("&&&&&\n"
                                                     "&^^^&\n"
                                                     "&^&^&\n"
                                                     "&^^^&\n"
                                                     "&&&&&"));
    
    CHECK(nospaces(mat(11, 9, '+', '^')) == nospaces("+++++++++++\n"
                                                     "+^^^^^^^^^+\n"
                                                     "+^+++++++^+\n"
                                                     "+^+^^^^^+^+\n"
                                                     "+^+^+++^+^+\n"
                                                     "+^+^^^^^+^+\n"
                                                     "+^+++++++^+\n"
                                                     "+^^^^^^^^^+\n"
                                                     "+++++++++++"));

    CHECK(nospaces(mat(15, 3, '2', 'f')) == nospaces("222222222222222\n"
                                                     "2fffffffffffff2\n"
                                                     "222222222222222"));


    CHECK(nospaces(mat(11, 1, '+', '^')) == nospaces("+++++++++++")); 

    CHECK(nospaces(mat(3, 1, '$', '^')) == nospaces("$$$")); 

    CHECK(nospaces(mat(9, 1, 'a', '1')) == nospaces("aaaaaaaaa"));

    CHECK(nospaces(mat(15, 1, '1', 'a')) == nospaces("111111111111111"));

    CHECK(nospaces(mat(1, 9, '^', '&')) == nospaces("^\n"
                                                     "^\n"
                                                     "^\n"
                                                     "^\n"
                                                     "^\n"
                                                     "^\n"
                                                     "^\n"
                                                     "^\n"
                                                     "^"));

    CHECK(nospaces(mat(1, 3, '#', '^')) == nospaces("#\n"
                                                     "#\n"
                                                     "#"));
    
    CHECK(nospaces(mat(1, 1, 'a', '1')) == nospaces("a"));

}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(5, 6, '$', '%'));
    CHECK_THROWS(mat(4, 6, '$', '%'));

    CHECK_THROWS(mat(-5, 5, '$', '%'));
    CHECK_THROWS(mat(3, -5, '$', '%'));
    CHECK_THROWS(mat(-1, 6, '$', '%'));
    CHECK_THROWS(mat(-9, -3, '$', '%'));

    CHECK_THROWS(mat(0, 5, '$', '%'));
    CHECK_THROWS(mat(7, 0, '$', '%'));

    CHECK_THROWS(mat(0, 0, '$', '%'));

    CHECK_THROWS(mat(0, 4, '$', '%'));
    CHECK_THROWS(mat(6, 0, '$', '%'));

    CHECK_THROWS(mat(3, 5, ' ', '%'));
    CHECK_THROWS(mat(3, 5, '\t', '%'));
    CHECK_THROWS(mat(3, 5, '\n', '%'));
    CHECK_THROWS(mat(3, 5, '\r', '%'));

    CHECK_THROWS(mat(3, 5, ' ', ' '));
    CHECK_THROWS(mat(3, 5, '\t', '\t'));
    CHECK_THROWS(mat(3, 5, '\n', '\n'));
    CHECK_THROWS(mat(3, 5, '\r', '\r'));

    CHECK_THROWS(mat(3, 5, '%', ' '));
    CHECK_THROWS(mat(3, 5, '$', '\t'));
    CHECK_THROWS(mat(3, 5, '#', '\n'));
    CHECK_THROWS(mat(3, 5, '%', '\r'));
}
