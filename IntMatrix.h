// IntMatrix.h

#ifndef INTMATRIX_H_
#define INTMATRIX_H_

#include <iostream>

/**
 * An integer matrix class.
 * The class represents a matrix with integer number with dynamic 2D int array.
 */
class IntMatrix
{
public:
	/**
	 * A default constructor.
	 * Initiates  _rows and _cols to 0 and _matrix to nullptr.
	 */
	IntMatrix();

	/**
	 * A copy constructor.
	 * Deep copy the data from toCopy to the new IntMatrix.
	 * @param toCopy IntMatrix
	 */
	IntMatrix(const IntMatrix& toCopy);

	/**
	 * Constructor. Initiates _rows and _cols with the given rows and cols parameters, and set
	 * the values of _matrix to 0.
	 * @param rows num of rows
	 * @param cols num of cols
	 */
	IntMatrix(const unsigned int rows, const unsigned int cols);

	/**
	 * A destructor.
	 * Delete the dynamic allocated _matrix to free memory.
	 */
	~IntMatrix();

	/**
	 * Implements the = operator. Deep copy the content of other to this.
	 * @param other IntMatrix to assign.
	 * @Return IntMatrix reference to this
	 */
	IntMatrix& operator=(const IntMatrix& other);

	/**
	 * Implements the + operator. Adding other to this according to adding rule of matrices and
	 * storing the result on a new IntMatrix.
	 * @param other IntMatrix to add.
	 * @Return IntMatrix result of the adding.
	 */
	const IntMatrix operator+(const IntMatrix& other) const;

	/**
	 * Implements the += operator. Adding other to this according to adding rule of matrices.
	 * @param other IntMatrix to add.
	 * @return IntMatrix reference to this.
	 */
	IntMatrix& operator+=(const IntMatrix& other);

	/**
	 * Implements the - operator. Subtracting other from this according to subtracting rule of
	 * matrices and storing the result on a new IntMatrix.
	 * @param other IntMatrix to subtract.
	 * @return IntMartix result of subtracting.
	 */
	const IntMatrix operator-(const IntMatrix& other) const;

	/**
	 * Implements the -= operator. Subtracting other from this according to subtracting rule of
	 * matrices.
	 * @param other IntMatrix to subtract.
	 * @return IntMatrix reference to this.
	 */
	IntMatrix& operator-=(const IntMatrix& other);

	/**
	 * Implements the * operator. Multiplying other to this according to multiplying rule of
	 * matrices and storing the result on a new IntMatrix.
	 * @param other IntMatrix to multiply.
	 * @return IntMartix result of multiplying.
	 */
	const IntMatrix operator*(const IntMatrix& other) const;

	/**
	 * Implements the *= operator. Multiplying other to this according to multiplying rule of
	 * matrices.
	 * @param other IntMatrix to multiply.
	 * @return IntMatrix reference to this.
	 */
	IntMatrix  operator*=(const IntMatrix& other);

	/**
	 * Calculating the transposed matrix of this and storing the result on a new IntMatrix.
	 * @result IntMatrix transposed matrix of this.
	 */
	const IntMatrix trans() const;

	/**
	 * Calculating the trace of this.
	 * @return int the trace.
	 */
	int trace() const;

	/**
	 * Adding printing rule to IntMatrix objects to the << operator of std::ostream.
	 * @param os std::ostream referene.
	 * @param mat IntMatrix reference.
	 * @return std::ostream the os object.
	 */
	friend std::ostream& operator<<(std::ostream& os, const IntMatrix& mat);

	/**
	 * Setting the given num on the given row and col.
	 * @param row
	 * @param col
	 * @param num
	 */
	void setNum(const unsigned int row, const unsigned int col, int num);

	/**
	 * @return the number of rows of this matrix.
	 */
	unsigned int getRows() const;

	/**
	 * @return the number of columns of this matrix.
	 */
	unsigned int getCols() const;

	/**
	 * @return pointer to the matrix.
	 */
	int** getMatrix() const;

private:
	unsigned int _rows; /**< number of rows. */
	unsigned int _cols; /**< number of columns. */
	int** _matrix; /**< 2D array represents the matrix. */

	/**
	 * Allocates a new 2D array representing the matrix into _matrix.
	 */
	void _createMatrix();

	/**
	 * Deleting the allocated 2D array that _matrix pointing to.
	 */
	void _deleteMatrix();
};

#endif /* INTMATRIX_H_ */
