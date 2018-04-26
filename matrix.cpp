/*
****************************************************************************
*                        FCI – Programming 2 – 2018                        *
** Project Name: Matrix  Library                                           *
** Last Modification Date: 18/02/2018                                      *
** Author: Mahmoud Ahmed Tawfik                                            *
****************************************************************************
*/

#include "matrix.h"
int Matrix::counter = 0;


/*Constructors*/

Matrix::Matrix()
{                      
    cout<<"Enter the number of rows: ";
	cin>>row;
    cout<<"Enter the number of columns: ";
	cin>>column;

    matrix = new double*[row];
    for(int i=0; i<row; i++)
		matrix[i] = new double[column];

    counter++;
}

Matrix::Matrix(int _row,int _column)
{
    row    = _row;
	column = _column;
    matrix = new double*[_row];
	for(int i = 0;i < _row;i++)
		matrix[i] = new double[_column];

	for(int i = 0; i < row;i++)
		for(int j = 0; j < column;j++)
			matrix[i][j] = 0; 

	counter++;
}

Matrix::Matrix(const Matrix &_m)
{      
    row    = _m.row;
	column = _m.column;
	matrix = new double*[row];
	for(int i = 0;i < row;i++)
		matrix[i] = new double[column];

	for(int i = 0;i < row;i++)
		for(int j = 0;j < column;j++)
			matrix[i][j] = _m.matrix[i][j];

	counter++;
}
                 

/*cin operator >> and cout operator <<*/

istream&operator>>(istream &input , const Matrix& obj)
{
    cout<<"Enter elements: "<<endl;
    for(int i=0; i< obj.row; i++)
	{
		for(int j=0; j < obj.column; j++)
            input>>obj.matrix[i][j];
    }
    return input;
}

ostream&operator<<(ostream &output ,const Matrix& obj)
{  
    for(int i = 0; i < obj.row; i++)
	{
		for(int j = 0; j < obj.column; j++)
            output<<obj.matrix[i][j]<<" ";
        output<<endl;
    }
    return output;
}



/*addition operator*/
Matrix Matrix::operator+(const Matrix &obj)
{
    Matrix m(row,column);
    for(int i = 0; i < m.row; i++)
	{
        for(int j = 0; j < m.column; j++)
            m.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
    }
    return m;
}

/*subtraction operator*/
Matrix Matrix::operator-(const Matrix &obj)
{   
    Matrix m(row,column);
    for(int i = 0; i < m.row; i++)
	{
        for(int j = 0; j < m.column; j++)
            m.matrix[i][j] = matrix[i][j] - obj.matrix[i][j];
    }
    return m;
}
 
/*multiplication operator*/
Matrix Matrix::operator*(const Matrix &obj)
{    
    Matrix m(row, obj.column);
    for(int i = 0; i < row; i++)
	{
        for(int j = 0; j < obj.column; j++)
		{ 
			m.matrix[i][j] = 0;
            for(int k = 0; k < column; k++)
			{
                m.matrix[i][j] += matrix[i][k] * obj.matrix[k][j];
            }
        }
    }
    return m;
}

/*Equal operator*/
void Matrix::operator=(Matrix _m)
{

	for(int i = 0; i < row; ++i)
			delete [] matrix[i];
	delete [] matrix;

	row    = _m.row;
	column = _m.column;
	matrix = new double*[_m.row];
	for(int i = 0;i < _m.row;i++)
		matrix[i] = new double[_m.column];

	for(int i = 0;i < _m.row;i++)
		for(int j = 0;j < _m.column;j++)
			matrix[i][j] = _m.matrix[i][j];
}

/*Access operator*/
double*Matrix::operator[](const int& index)
{       
    return matrix[index];
}


/*Transpose method*/
void Matrix::transpose()
{
   Matrix transpose(column, row);
		for (int i = 0; i < row; ++i) 
		{
			for (int j = 0; j < column; ++j) 
			{
				transpose.matrix[j][i] = matrix[i][j];
			}
		}
	*this = transpose  ;
}

int Matrix::getCounter(){return counter;}

/*Destructor*/
Matrix::~Matrix()
{
	for(int i = 0; i < row; ++i)
			delete [] matrix[i];
		 delete [] matrix;
	counter--;
}

