#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <algorithm>

using namespace zich;
using namespace std;

vector<double> a = {1,2,3,4};
Matrix m(a, 2,2);

TEST_CASE ("Bad input") {
    for (int i=0; i<30; i++){
        CHECK_THROWS (Matrix(a, 1,2));
    }
}