/*
 * BitMatrix.h
 *
 *  Created on: Jul 10, 2011
 *      Author: sadanjon
 */

#ifndef BITMATRIX_H_
#define BITMATRIX_H_

#include <cstdio>
#include "BitVector.h"

class BitMatrix {

public:
	BitMatrix(int numOfRows, int numOfCols);
	~BitMatrix();

	void setRow(int i, BitVector v);
	BitVector getRow(int i);

	void swapRows(int i, int j);
	void addToRow(int row, BitVector otherRow);

	void transpose();

	int getRows() const {
		return m_rows;
	}

	int getCols() const {
		return m_cols;
	}

	void debug_print() {
		printf("debug print:\n");
		for (int i = 0; i < m_rows; ++i) {
			for (int j = 0; j < m_cols; j++) {
				printf("%d ", m_matrix[i][j]);
			}
			printf("\n");
		}
	}

	BitVector operator[](int i) {
		return m_matrix[i];
	}

private:
	BitVector *m_matrix;
	int m_rows, m_cols;

};

#endif /* BITMATRIX_H_ */
