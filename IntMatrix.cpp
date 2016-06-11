// IntMatrix.cpp

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class IntMatrix.
// --------------------------------------------------------------------------------------

#include <assert.h>
#include "IntMatrix.h"

// ------------------ Private Methods -----------------------
/**
 * Allocates a new 2D array representing the matrix into _matrix.
 */
void IntMatrix::_createMatrix()
{
	_matrix = new int*[_rows];
	unsigned int i, j;

	for (i = 0; i < _rows; i++)
	{
		_matrix[i] = new int[_cols];
		for (j = 0; j < _cols; j++)
		{
			_matrix[i][j] = 0;
		}
	}
}

/**
 * Deleting the allocated 2D array that _matrix pointing to.
 */
void IntMatrix::_deleteMatrix()
{
	unsigned int i;
	if (_matrix != nullptr)
	{
		for (i = 0; i < _rows; i++)
		{
			delete[] _matrix[i];
		}

		delete[] _matrix;
		_matrix = nullptr;
	}
}

// ------------------ Constructors --------------------------
/**
 * A default constructor.
 * Initiates  _rows and _cols to 0 and _matrix to nullptr.
 */
IntMatrix::IntMatrix() : _rows(0), _cols(0), _matrix(nullptr)
{
}

/**
 * A copy constructor.
 * Deep copy the data from toCopy to the new IntMatrix.
 * @param toCopy IntMatrix
 */
IntMatrix::IntMatrix(const IntMatrix& toCopy) : _rows(toCopy._rows), _cols(toCopy._cols)
{
	*this = toCopy;
}

/**
 * Constructor. Initiates _rows and _cols with the given rows and cols parameters, and set
 * the values of _matrix to 0.
 * @param rows num of rows
 * @param cols num of cols
 */
IntMatrix::IntMatrix(const unsigned int rows, const unsigned int cols) : _rows(rows), _cols(cols)
{
	_createMatrix();
}

// ------------------ Destructor ----------------------------
/**
 * A destructor.
 * Delete the dynamic allocated _matrix to free memory.
 */
IntMatrix::~IntMatrix()
{
	_deleteMatrix();
}

// ------------------ Operators -----------------------------
/**
 * Implements the = operator. Deep copy the content of other to this.
 * @param other IntMatrix to assign.
 * @Return IntMatrix reference to this
 */
IntMatrix& IntMatrix::operator=(const IntMatrix& other)
{
	if (this == &other)
	{
		return *this;
	}

	_deleteMatrix();

	_rows = other._rows;
	_cols = other._cols;

	_createMatrix();

	unsigned int i, j;
	for (i = 0; i < _rows; i++)
	{
		for (j = 0; j < _cols; j++)
		{
			_matrix[i][j] = other._matrix[i][j];
		}
	}

	return *this;
}

/**
 * Implements the + operator. Adding other to this according to adding rule of matrices and
 * storing the result on a new IntMatrix.
 * @param other IntMatrix to add.
 * @Return IntMatrix result of the adding.
 */
const IntMatrix IntMatrix::operator+(const IntMatrix& other) const
{
	assert(_rows == other._rows && _cols == other._cols);
	IntMatrix res(_rows, _cols);
	unsigned int i, j;

	for (i = 0; i < _rows; i++)
	{
		for (j = 0; j < _cols; j++)
		{
			res._matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
		}
	}

	return res;
}

/**
 * Implements the += operator. Adding other to this according to adding rule of matrices.
 * @param other IntMatrix to add.
 * @return IntMatrix reference to this.
 */
IntMatrix& IntMatrix::operator+=(const IntMatrix& other)
{
	assert(_rows == other._rows && _cols == other._cols);
	*this = *this + other;
	return *this;
}

/**
 * Implements the - operator. Subtracting other from this according to subtracting rule of
 * matrices and storing the result on a new IntMatrix.
 * @param other IntMatrix to subtract.
 * @return IntMartix result of subtracting.
 */
const IntMatrix IntMatrix::operator-(const IntMatrix& other) const
{
	assert(_rows == other._rows && _cols == other._cols);
	IntMatrix res(_rows, _cols);
	unsigned int i, j;

	for (i = 0; i < _rows; i++)
	{
		for (j = 0; j < _cols; j++)
		{
			res._matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
		}
	}

	return res;
}

/**
 * Implements the -= operator. Subtracting other from this according to subtracting rule of
 * matrices.
 * @param other IntMatrix to subtract.
 * @return IntMatrix reference to this.
 */
IntMatrix& IntMatrix::operator-=(const IntMatrix& other)
{
	assert(_rows == other._rows && _cols == other._cols);
	*this = *this - other;
	return *this;
}

/**
 * Implements the * operator. Multiplying other to this according to multiplying rule of
 * matrices and storing the result on a new IntMatrix.
 * @param other IntMatrix to multiply.
 * @return IntMartix result of multiplying.
 */
const IntMatrix IntMatrix::operator*(const IntMatrix& other) const
{
	assert(_cols == other._rows);
	IntMatrix res(_rows, other._cols);
	unsigned int i, j, k;
	int mult = 0;

	for (i = 0; i < res._rows; i++)
	{
		for (j = 0; j < res._cols; j++)
		{
			for (k = 0; k < _cols; k++)
			{
				mult += (_matrix[i][k] * other._matrix[k][j]);
			}
			res._matrix[i][j] = mult;
			mult = 0;
		}
	}

	return res;
}

/**
 * Implements the *= operator. Multiplying other to this according to multiplying rule of
 * matrices.
 * @param other IntMatrix to multiply.
 * @return IntMatrix reference to this.
 */
IntMatrix IntMatrix::operator*=(const IntMatrix& other)
{
	assert(_cols == other._rows);
	*this = *this * other;
	return *this;
}

/**
 * Calculating the transposed matrix of this and storing the result on a new IntMatrix.
 * @result IntMatrix transposed matrix of this.
 */
const IntMatrix IntMatrix::trans() const
{
	IntMatrix res(_cols, _rows);
	unsigned int i, j;

	for (i = 0; i < res._rows; i++)
	{
		for (j = 0; j < res._cols; j++)
		{
			res._matrix[i][j] = _matrix[j][i];
		}
	}

	return res;
}

/**
 * Calculating the trace of this.
 * @return int the trace.
 */
int IntMatrix::trace() const
{
	assert(_rows == _cols);
	int tr = 0;
	unsigned int i;

	for (i = 0; i < _rows; i++)
	{
		tr += _matrix[i][i];
	}

	return tr;
}

/**
 * Adding printing rule to IntMatrix objects to the << operator of std::ostream.
 * @param os std::ostream referene.
 * @param mat IntMatrix reference.
 * @return std::ostream the os object.
 */
std::ostream& operator<<(std::ostream& os, const IntMatrix& mat)
{
	if (mat._rows == 0 || mat._cols == 0)
	{
		os << std::endl;
	}
	else
	{
		unsigned int i, j;
		for (i = 0; i < mat._rows; i++)
		{
			for (j = 0; j < mat._cols; j++)
			{
				os << mat._matrix[i][j];
				if (j != mat.getCols() - 1)
				{
					os << " ";
				}
			}
			os << std::endl;
		}
	}

	return os;
}

// ------------------ Access methods ------------------------
/**
 * Setting the given num on the given row and col.
 * @param row
 * @param col
 * @param num
 */
void IntMatrix::setNum(const unsigned int row, const unsigned int col, int num)
{
	assert(row < _rows && col < _cols);
	_matrix[row][col] = num;
}

/**
 * @return the number of rows of this matrix.
 */
unsigned int IntMatrix::getRows() const
{
	return _rows;
}

/**
 * @return the number of columns of this matrix.
 */
unsigned int IntMatrix::getCols() const
{
	return _cols;
}

/**
 * @return pointer to the matrix.
 */
int** IntMatrix::getMatrix() const
{
	return _matrix;
}
