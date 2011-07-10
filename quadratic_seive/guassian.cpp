/*
 * guassian.cpp
 *
 *  Created on: Jul 11, 2011
 *      Author: sadanjon
 */

#include "guassian.h"

void guassianElimination(BitMatrix &m) {
	if (m.getCols() <= m.getRows()) {
		// no answer, or just the trivial one.
	}

	for (int col = 0; col < m.getCols(); ++col) {
		// find the first with a 1
		int row = col;
		while (row < m.getRows() && !m[row][col])
			++row;

		if (row >= m.getRows()) {
			continue;
		}

		m.swapRows(row, col);

		// subtract from all other rows with one in them
		// on that column
		for (int i = col + 1; i < m.getRows(); ++i) {
			if (m[i][col]) {
				m.addToRow(i, m[col]);
			}
		}
	}

	//m.debug_print();
}

void solver(BitMatrix &reducedM, BitVector *&solVec, int &numSolutions) {
	BitVector *lockedVars = new BitVector[reducedM.getCols()];
	memset(lockedVars, 0, reducedM.getCols()*sizeof(BitVector));

	int lockedVarsCount = 0;

	// fill out lockedVars
	for (int row = reducedM.getRows() - 1; row >= 0; --row) {
		int col;
		for (col = 0; col < reducedM.getCols(); ++col) {
			if (reducedM[row][col] == 1)
				break;
		}

		if (col < reducedM.getCols()) {
			lockedVars[col] = reducedM[row];

			lockedVarsCount++;
		}
	}

	numSolutions = 1 << (reducedM.getCols() - lockedVarsCount);


	// fill out solutions!
	solVec = new BitVector[numSolutions];
	for (int i = 0; i < numSolutions; ++i) {
		int freeVarCount = 0;
		solVec[i] = new short[reducedM.getCols()];
		for (int var = reducedM.getCols() - 1; var >= 0; --var) {
			if (lockedVars[var] == NULL) {
				solVec[i][var] = (i & (1 << freeVarCount)) != 0;
				freeVarCount++;
			} else {
				solVec[i][var] = 0;
				for (int k = var + 1; k < reducedM.getCols(); ++k) {
					solVec[i][var] += lockedVars[var][k]*solVec[i][k];
				}
				// now modulu 2
				solVec[i][var] &= 1;
			}
		}
	}

	delete[] lockedVars;
}
