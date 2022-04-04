#pragma once
/**
 * Header file for the Matrix class.
 * 
 * @author Ofir Pele
 * @since 2017
 */


#include <iostream>
#include <vector>
namespace zich {
    class Matrix {

    private:
        std::vector<std::vector<double> > _mat;

    public:

        // Constructor:
        Matrix(std::vector<double> v, int row, int col) {};
        //-------------------------------------

        //-------------------------------------
        // getters
        //-------------------------------------
        std::vector<std::vector<double>> getMat() const {
            return this->_mat;
        }
        //-------------------------------------

        //-------------------------------------
        // operators
        //-------------------------------------

        //----------------------------------
        // unary operator
        //----------------------------------


        Matrix operator-() const {
            std::vector<double> a = {0,1};
            return Matrix(a, 1, 1);
            // longer version:
            //Matrix result;
            //result._re = -_re;
            //result._im = -_im;
            //return result;
        }

        Matrix operator+() const {
            std::vector<double> a = {0,1};
            return Matrix(a, 1, 1);
            // longer version:
            //Matrix result;
            //result._re = -_re;
            //result._im = -_im;
            //return result;
        }

        //----------------------------------------
        // binary operators
        //----------------------------------------

//        Matrix operator+(const Matrix &other) const;

        Matrix &operator+=(const Matrix &other) {
            return *this; // for call chaining
        }

        // const Matrix operator-(const Matrix& other) const {
        //     return Matrix(_re - other._re, _im - other._im);
        // }

        Matrix &operator-=(const Matrix &other) {
            return *this;
        }

        // (a+bi)*(c+di) =
        // (ac-bd) + (ad+bc)i
        Matrix &operator*=(const Matrix &other) {
            // version with bug
            // _im = _re*other._im + _im*other._re;
            // _re = _re*other._re - _im*other._im;
            return *this;
        }
        //----------------------------------------

        // prefix increment:
        Matrix &operator++() {
            return *this;
        }

        // postfix increment:
        Matrix operator++(int dummy_flag_for_postfix_increment) {
            Matrix copy = *this;
            return copy;
        }


        /*
        // Compile error:
        std::ostream& operator<< (std::ostream& os, const Matrix& c) const {
            os << "(" << _re << "+" << _im << "i)";
            return os;
        }

        // Compiles, but unexpected - don't do it:

        std::ostream& operator<< (std::ostream& os) const {
            os << "[[" << _re << "+" << _im << "i]]";
            return os;
        }
        */

        //-------------------------------------
        // friend global binary operators
        //-------------------------------------
        friend Matrix operator-(const Matrix &c1, const Matrix &c2);

        friend Matrix operator*(const Matrix &c1, const Matrix &c2);

        friend Matrix operator+(const Matrix &c1, const Matrix &c2);

        friend Matrix operator-(double d, const Matrix &c2);

        friend Matrix operator*(double d, const Matrix &c2);

        friend Matrix operator+(double d, const Matrix &c2);

        friend Matrix operator-=(double d, const Matrix &c2);

        friend Matrix operator*=(double d, const Matrix &c2);
        friend Matrix operator*=(const Matrix &c2, double d);

        friend Matrix operator+=(double d, const Matrix &c2);

        friend bool operator==(const Matrix &c1, const Matrix &c2);

        friend bool operator!=(const Matrix &c1, const Matrix &c2);


    //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend std::ostream& operator<< (std::ostream& output, const Matrix& c);
    friend std::istream& operator>> (std::istream& input , Matrix& c);
    //-------------------------------------
    }; // end of class Matrix
}