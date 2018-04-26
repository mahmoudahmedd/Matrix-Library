/*
****************************************************************************
*                        FCI – Programming 2 – 2018                        *
** Project Name: Matrix  Library                                           *
** Last Modification Date: 18/02/2018                                      *
** Author: Mahmoud Ahmed Tawfik                                            *
****************************************************************************
*/

#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	Matrix M1(2,1); // Declare and initialize matrix with 2 rows and 1 columns.
	Matrix M2(1,2); // Declare and initialize matrix with 1 rows and 2 columns.
	Matrix M3(2,2); // Declare and initialize matrix with 2 rows and 2 columns.
	cin>>M1;        // Initialize matrix M1.
	cin>>M2;        // Initialize matrix M2.
	M3 = M2 * M1;   // M3 = M2 * M1.
	cout<<M3<<endl; // Display M3 on screen.
    return 0;
}
