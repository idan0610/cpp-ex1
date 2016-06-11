// IntMatrix.cpp

// --------------------------------------------------------------------------------------
// This file is a driver to the IntMatrix class.
// --------------------------------------------------------------------------------------

#include "IntMatrix.h"
#include <iostream>
#include <assert.h>
#include <sstream>

#define OPERATIONS_LIST "Choose operation:" << std::endl << "1. add" << std::endl << "2. sub" \
						<< std::endl << "3. mul" << std::endl << "4. trans" << std::endl << \
						"5. trace" << std::endl
#define ASK_FOR_MATRICES(OP, NUM, MAT) "Operation " << OP << " requires " << NUM << " operand " \
									   << MAT << "." << std::endl
#define NUM_OF_ROWS "number of rows:"
#define NUM_OF_COLS "number of columns:"
#define MATRIX_INSTRUCTIONS "Now insert the values of the matrix, row by row." << std::endl << \
							"After each cell add the char ',' (including after the last cell of " \
							"a row)." << std::endl << "Each row should be in a separate line." << \
							std::endl
#define INSERT_FIRST "Insert first matrix:" << std::endl
#define INSERT_SECOND "Insert second matrix:" << std::endl
#define SEPERATION "--------" << std::endl
#define GOT_MATRIX "got matrix:" << std::endl
#define GOT_FIRST "Got first matrix:" << std::endl
#define GOT_SECOND "Got second matrix:" << std::endl
#define RESULT_MATRIX "==========" << std::endl << "Resulted matrix:" << std::endl
#define ERROR_DIMENSIONS(OP) "Error: " << OP << " failed - different dimensions." << std::endl
#define ERROR_TRACE "Error: trace failed - The matrix isn't square."
#define PRINT_TRACE(NUM) "The matrix is square and its trace is " << NUM

enum
{
	add = 1,
	sub,
	mul,
	trans,
	trace
};

/**
 * Used to ask for the desired operation to do.
 */
int chooseOperation()
{
	int op = 0;
	while (op < 1 || op > 5)
	{
		std::cout << OPERATIONS_LIST;
		std::cin >> op;
	}

	return op;
}

/**
 * Used to ask for 1 IntMatrix from the use
 * @return the new IntMatrix
 */
IntMatrix getMatrix()
{
	// Asking for rows and cols
	int rows = 0, cols = 0;
	std::cout << NUM_OF_ROWS;
	std::cin >> rows;
	std::cout << NUM_OF_COLS;
	std::cin >> cols;
	std::cout << MATRIX_INSTRUCTIONS;

	assert(rows >= 0 && cols >= 0);
	IntMatrix matrix(rows, cols);
	std::string line, token;
	int i, j, num = 0;

	for (i = 0; i < rows; i++)
	{
		std::cin >> line;
		std::istringstream stream(line);
		for (j = 0; j < cols; j++)
		{
			std::getline(stream, token, ',');
			num = std::stoi(token);
			matrix.setNum(i, j, num);
		}
	}


	return matrix;
}

/**
 * The main method. Runs the driver, asking the user for operation and 1/2 matrices required.
 * Prints the result.
 *
 */
int main()
{
	// Ask for operation
	int op = chooseOperation();
	IntMatrix result;
	IntMatrix matrix1;
	IntMatrix matrix2;
	switch(op)
	{
		case add:
			// Ask for 2 matrices
			std::cout << ASK_FOR_MATRICES("add", 2, "matrices");
			std::cout << INSERT_FIRST;
			matrix1 = getMatrix();
			std::cout << INSERT_SECOND;
			matrix2 = getMatrix();
			std::cout << SEPERATION << GOT_FIRST << std::endl << matrix1 << std::endl;
			std::cout << SEPERATION << GOT_SECOND << std::endl << matrix2 << std::endl;

			// If dimensions are the same, use + operator for result. Otherwise print error.
			if ((matrix1.getRows() != matrix2.getRows()) || matrix1.getCols() != matrix2.getCols())
			{
				std::cout << ERROR_DIMENSIONS("add");
			}
			else
			{
				result = matrix1 + matrix2;
				std::cout << RESULT_MATRIX << std::endl << result << std::endl;
			}
			break;
		case sub:
			// Ask for 2 matrices
			std::cout << ASK_FOR_MATRICES("sub", 2, "matrices");
			std::cout << INSERT_FIRST;
			matrix1 = getMatrix();
			std::cout << INSERT_SECOND;
			matrix2 = getMatrix();
			std::cout << SEPERATION << GOT_FIRST << std::endl << matrix1 << std::endl;
			std::cout << SEPERATION << GOT_SECOND << std::endl << matrix2 << std::endl;

			// If dimensions are the same, use - operator for result. Otherwise print error.
			if ((matrix1.getRows() != matrix2.getRows()) || matrix1.getCols() != matrix2.getCols())
			{
				std::cout << ERROR_DIMENSIONS("sub");
			}
			else
			{
				result = matrix1 - matrix2;
				std::cout << RESULT_MATRIX << std::endl << result << std::endl;
			}
			break;
		case mul:
			// Ask for 2 matrices
			std::cout << ASK_FOR_MATRICES("mul", 2, "matrices");
			std::cout << INSERT_FIRST;
			matrix1 = getMatrix();
			std::cout << INSERT_SECOND;
			matrix2 = getMatrix();
			std::cout << SEPERATION << GOT_FIRST << std::endl << matrix1 << std::endl;
			std::cout << SEPERATION << GOT_SECOND << std::endl << matrix2 << std::endl;

			// If dimensions are matching, use * operator for result. Otherwise print error.
			if (matrix1.getCols() != matrix2.getRows())
			{
				std::cout << ERROR_DIMENSIONS("mul");
			}
			else
			{
				result = matrix1 * matrix2;
				std::cout << RESULT_MATRIX << std::endl << result << std::endl;
			}
			break;
		case trans:
			// Ask for 1 matrix
			std::cout << ASK_FOR_MATRICES("trans", 1, "matrix");
			matrix1 = getMatrix();
			std::cout << SEPERATION << GOT_MATRIX << std::endl << matrix1 << std::endl;

			// Find the transposed matrix
			result = matrix1.trans();
			std::cout << RESULT_MATRIX << std::endl << result << std::endl;
			break;
		case trace:
			// Ask for 1 matrix.
			std::cout << ASK_FOR_MATRICES("trace", 1, "matrix");
			matrix1 = getMatrix();
			std::cout << SEPERATION << GOT_MATRIX << std::endl << matrix1 << std::endl;

			// If the matrix is square, find the trace. Otherwise print error.
			if (matrix1.getCols() != matrix1.getRows())
			{
				std::cout << ERROR_TRACE << std::endl;
			}
			else
			{
				int tr = matrix1.trace();
				std::cout << PRINT_TRACE(tr) << std::endl;
			}
			break;
	}

	return 0;
}
