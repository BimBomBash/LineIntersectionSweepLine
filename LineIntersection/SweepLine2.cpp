#include "stdafx.h"
#include "Line.h"
#include <vector>
#include "SweepLine2.h"
#include <iostream>
#include <cmath>
using namespace std;

SweepLine2::SweepLine2()
{
}

SweepLine2::SweepLine2(std::vector<Line*> &_line)
{
	line = _line;
	cout << "SWEEPLINE!:" <<NotBruteForceIntersection(line.size());
}

SweepLine2::~SweepLine2()
{
}

int number = 0;
int SweepLine2::NotBruteForceIntersection(int NumberOfLine) {
	float **ar = new float *[NumberOfLine];

	for (int n = 0; n < NumberOfLine; n++) {
		ar[n] = new float[10];
	}
	for (int i = 0; i<NumberOfLine; i++) {
		for (int j = 0; j<10; j++) {
			ar[i][j] = 0;
		}
	}
	int Intersection = 0;
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<NumberOfLine; j++) {
			float KoordinatXdiI = ((i - line[j]->c()) / line[j]->Gradient());
			float KoordinatXdiIMinSatu = ((i - 1 - line[j]->c()) / line[j]->Gradient());
			if (line[j]->Gradient()>0) {
				if (KoordinatXdiI >= line[j]->vertexA->x && KoordinatXdiI <= line[j]->vertexB->x) {
					ar[j][i] = KoordinatXdiI;
				}
			}
			if (line[j]->Gradient()<0) {
				if (KoordinatXdiI <= line[j]->vertexB->x && KoordinatXdiI >= line[j]->vertexA->x) {
					ar[j][i] = KoordinatXdiI;
				}
			}
		}
	}
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<NumberOfLine; j++) {
			for (int k = j + 1; k<NumberOfLine; k++) {
				if (ar[j][i] == 0 || ar[k][i] == 0 || ar[j][i - 1] == 0 || ar[k][i - 1] == 0) {
					continue;
				}
				float SelisihSekarang = ar[j][i] - ar[k][i];
				float SelisihLalu = ar[j][i - 1] - ar[k][i - 1];
				if (SelisihSekarang>0 && SelisihLalu<0) {
					cout << "Garis (" << line[j]->vertexA->x << "," << line[j]->vertexA->y << ") , (" << line[j]->vertexB->x << "," << line[j]->vertexB->y << ") dengan garis ("  << line[k]->vertexA->x << "," << line[k]->vertexA->y << ") , (" << line[k]->vertexB->x << "," << line[k]->vertexB->y << ")"<< endl;
					Intersection++;
				}
				if (SelisihSekarang<0 && SelisihLalu>0) {
					cout << "Garis (" << line[j]->vertexA->x << "," << line[j]->vertexA->y << ") , (" << line[j]->vertexB->x << "," << line[j]->vertexB->y << ") dengan garis (" << line[k]->vertexA->x << "," << line[k]->vertexA->y << ") , (" << line[k]->vertexB->x << "," << line[k]->vertexB->y << ")" << endl;
					Intersection++;
				}
			}
		}
	}
	return Intersection;
}
