#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <algorithm>

using namespace zich;
using namespace std;

vector<double> a = {1,2,3,4};


TEST_CASE ("Bad input - minus") {
CHECK_THROWS (Matrix(a, -1,2));
}

TEST_CASE ("Bad input - minus") {
CHECK_THROWS (Matrix(a, 1,-2));
}

TEST_CASE ("Bad input - size") {
CHECK_THROWS (Matrix(a, 1,2));
}

TEST_CASE ("Bad input - size") {
CHECK_THROWS (Matrix(a, 4,0));
}

TEST_CASE ("Bad operator - size") {
Matrix m1(a, 2,2);
vector<double> b = {1,2,3,4,5,6};
vector<double> c = {1,1,-1,-1};
Matrix m2(b, 2,3);
Matrix m3(c, 2,2);
Matrix m4(c, 4,1);

CHECK_THROWS (m1+m2);
CHECK_THROWS (m2+m1);
CHECK_THROWS (m2-m1);
CHECK_THROWS (m1-m2);
CHECK_THROWS (m1+=m2);
CHECK_THROWS (m2+=m1);
CHECK_THROWS (m2-=m1);
CHECK_THROWS (m1-=m2);
CHECK_THROWS (m2 = m3+m1);
CHECK_THROWS (m2 = m1-m3);
CHECK_THROWS(bool ans = m1 != m2);
CHECK_THROWS(bool ans = m1 != m4);
CHECK_THROWS(bool ans = m1 < m2);
CHECK(m1 != m3);
CHECK(m1 > m3);
}

TEST_CASE ("result") {
Matrix m1(a, 2,2);
vector<double> b = {2,4,6,8};
vector<double> c = {-1,-2,-3,-4};
vector<double> d = {4,8,12,16};
vector<double> e = {3,6,9,12};
Matrix m3(c, 2,2);
Matrix m4(b, 2,2);
Matrix m8(d, 2,2);
Matrix m9(e, 2,2);

CHECK(-m1 == m3);
CHECK(2*m3 == m4);
CHECK(m4 + m4 == m8);
m8 -= m3;
CHECK(m8 == m9);
}