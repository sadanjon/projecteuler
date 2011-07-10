/*
 * main.cpp
 *
 *  Created on: Jul 10, 2011
 *      Author: sadanjon
 */

#include "BitMatrix.h"
#include "guassian.h"

int main(int argc, char **argv) {
	BitMatrix *m = new BitMatrix(7, 5);

	short matrix[7][5] = {
			{0,1,1,0,1},
			{1,0,0,1,1},
			{1,1,0,0,0},
			{0,1,0,1,0},
			{0,1,0,1,1},
			{0,1,1,1,0},
			{0,1,0,0,1}
	};

	m->setRow(0, matrix[0]);
	m->setRow(1, matrix[1]);
	m->setRow(2, matrix[2]);
	m->setRow(3, matrix[3]);
	m->setRow(4, matrix[4]);
	m->setRow(5, matrix[5]);
	m->setRow(6, matrix[6]);

	m->debug_print();

	m->transpose();
	printf("transpose:\n");
	m->debug_print();
	printf("guassian:\n");
	guassianElimination(*m);
	m->debug_print();

	BitVector *sols;
	int n;
	solver(*m, sols, n);

	for (int i = 0; i < n; ++i) {
		printf("solution %d: ", i);
		for (int j = 0; j < m->getCols(); ++j) {
			printf("%d ", sols[i][j]);
		}
		printf("\n");
	}

	delete m;


	return 0;
}


