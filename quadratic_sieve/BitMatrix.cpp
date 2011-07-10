/*
 * BitMatrix.cpp
 *
 *  Created on: Jul 10, 2011
 *      Author: sadanjon
 */
#include <cstring>
#include "BitMatrix.h"

BitMatrix::BitMatrix(int numOfRows, int numOfCols) :
	m_rows(numOfRows), m_cols(numOfCols) {
	m_matrix = new BitVector[numOfRows];

	for (int i = 0; i < m_rows; ++i) {
		m_matrix[i] = new short[m_cols];
	}
}

BitMatrix::~BitMatrix() {
	for (int i = 0; i < m_rows; ++i) {
		delete[] m_matrix[i];
	}

	delete[] m_matrix;
}

void BitMatrix::setRow(int i, BitVector v) {
	memcpy(m_matrix[i], v, m_cols * sizeof(short));
}

BitVector BitMatrix::getRow(int i) {
	return m_matrix[i];
}

void BitMatrix::swapRows(int i, int j) {
	if (i == j) {
		return;
	}
	BitVector temp = m_matrix[i];
	m_matrix[i] = m_matrix[j];
	m_matrix[j] = temp;
}

void BitMatrix::addToRow(int row, BitVector otherRow) {
	for (int i = 0; i < m_cols; ++i) {
		if (otherRow[i] != 0) {
			m_matrix[row][i] = 1 - m_matrix[row][i];
		}
	}

}

void BitMatrix::transpose() {
	// create the new matrix
	BitVector *newMatrix = new BitVector[m_cols];
	for (int i = 0; i < m_cols; ++i)
		newMatrix[i] = new short[m_rows];

	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < m_cols; ++j) {
			newMatrix[j][i] = m_matrix[i][j];
		}
	}

	// delete the old matrix
	for (int i = 0; i < m_rows; ++i) {
		delete[] m_matrix[i];
	}
	delete[] m_matrix;

	// apply the new matrix
	m_matrix = newMatrix;
	int temp = m_rows;
	m_rows = m_cols;
	m_cols = temp;
}
