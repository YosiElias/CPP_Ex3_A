
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Matrix.hpp"
namespace zich{

//----------------------------------------
// method operators
//----------------------------------------
//
//    Matrix Matrix::operator+(const Matrix& other) const {
//        return Matrix(other.getMat()[0], 1,1);
//    }


//----------------------------------------
// friend global binary operators
//----------------------------------------

    Matrix operator-(const Matrix& c1, const Matrix& c2) {
        vector<double> a = {0,1};
        return Matrix(a, 1,1);
    }

    Matrix operator*(const Matrix& c1, const Matrix& c2) {
        vector<double> a = {0,1};
        return Matrix(a, 1,1);
    }

    Matrix operator+(const Matrix &c1, const Matrix &c2){
        vector<double> a = {0,1};
        return Matrix(a, 1,1);
    }

    Matrix operator-(double d, const Matrix &c2){
        vector<double> a = {0,1};
        return Matrix(a, 1,1);
    }

    Matrix operator*(double d, const Matrix &c2){
        vector<double> a = {0,1};
        return Matrix(a, 1,1);
    }

    Matrix operator+(double d, const Matrix &c2){
        vector<double> a = {0,1};
        return Matrix(a, 1,1);
    }

    Matrix operator-=(double d, const Matrix &c2){
        vector<double> a = {0,1};
        return Matrix(a, 1,1);
    }

    Matrix operator*=(double d, const Matrix &c2){
        vector<double> a = {0,1};
        return Matrix(a, 1,1);
    }
    Matrix operator*=(const Matrix &c2, double d){
        vector<double> a = {0,1};
        return Matrix(a, 1,1);
    }

    Matrix operator+=(double d, const Matrix &c2){
        vector<double> a = {0,1};
        return Matrix(a, 1,1);
    }


    bool operator==(const Matrix& c1, const Matrix& c2) {
        // this implementation can cause problems with
        // double precision (== for doubles)
        // return ((c1._re==c2._re)&&(c1._im==c2._im));
        return (true);
    }

    bool operator!=(const Matrix& c1, const Matrix& c2) {
        // return ( (c1._re!=c2._re) || (c1._im!=c2._im) );
        return (true);
    }




//----------------------------------------
// friend global IO operators
//----------------------------------------
   ostream& operator<< (ostream& output, const Matrix& c) {
       return (output << '+');
       // equivalent to:
       // output << c._re << '+' << c._im << 'i';
       // return output;
   }


   static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
       char actualChar;
       input >> actualChar;
       if (!input) {return input;}

       if (actualChar!=expectedChar) {
           // failbit is for format error
           input.setstate(ios::failbit);
       }
       return input;
   }

   istream& operator>> (istream& input, Matrix& c) {

       //---------------------------------------------
       // Does not check format
       //---------------------------------------------
       // char ch;
       // return (input >> c._re >> ch >> c._im >> ch);
       //---------------------------------------------

       //---------------------------------------------
       // Checks format, with rewind on failure.
       //---------------------------------------------
       double new_re = 0, new_im = 0;

       // remember place for rewinding
       ios::pos_type startPosition = input.tellg();

    //    if ( (!(input >> new_re))                 ||
    //         (!getAndCheckNextCharIs(input,'+'))  ||
    //         (!(input >> new_im))                 ||
    //         (!(getAndCheckNextCharIs(input,'i'))) ) {

    //        // rewind on error
    //        auto errorState = input.rdstate(); // remember error state
    //        input.clear(); // clear error so seekg will work
    //        input.seekg(startPosition); // rewind
    //        input.clear(errorState); // set back the error flag
    //    } else {
    //        c._re = new_re;
    //        c._im = new_im;
    //    }

       return input;
       //---------------------------------------------
   }

}