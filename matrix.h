/*
****************************************************************************
*                        FCI – Programming 2 – 2018                        *
** Project Name: Matrix  Library                                           *
** Last Modification Date: 18/02/2018                                      *
** Author: Mahmoud Ahmed Tawfik                                            *
****************************************************************************
*/

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>
using namespace std ;

class Matrix
{
private:
	/*Attributes*/
    int row,column;
	double **matrix;
    static int counter;
public:

	/*Constructors*/
    Matrix();
    Matrix(int _row,int _column);
    Matrix(const Matrix &_m);

	/*cin operator >> and cout operator <<*/
    friend istream&operator>>(istream &input , const Matrix& obj);
    friend ostream&operator<<(ostream &output ,const Matrix& obj);

	/*addition operator, subtraction operator, multiplication operator, and equal operator*/
    Matrix operator+(const Matrix &obj);
    Matrix operator-(const Matrix &obj);
    Matrix operator*(const Matrix &obj);
	void   operator=(Matrix _m);

	/*Access operator*/
    double*operator[](const int& index);
	
	/*Transpose method*/
    void transpose();

	/*Return counter*/
	int getCounter();

	/*Destructor*/
    ~Matrix();
 };

#endif // MATRIX_H_INCLUDED


