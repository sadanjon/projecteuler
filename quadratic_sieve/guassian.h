/*
 * guassian.h
 *
 *  Created on: Jul 10, 2011
 *      Author: sadanjon
 */

#ifndef GUASSIAN_H_
#define GUASSIAN_H_

#include <cstring>
#include "BitMatrix.h"

void guassianElimination(BitMatrix &m);
void solver(BitMatrix &reducedM, BitVector *&solVec, int &numSolutions);

#endif /* GUASSIAN_H_ */
