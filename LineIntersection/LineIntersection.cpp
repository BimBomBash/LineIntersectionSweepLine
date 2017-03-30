// LineIntersection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GL/glew.h"
#include <iostream>
#include <vector>
#include <ctime>
#include "Line.h"
#include "SweepLine2.h"

bool isInrange(float _target, float _a, float _b) {
	if (_a > _b) {
		float c = _a;
		_a = _b;
		_b = c;
	}

	if (_target >= _a && _target <= _b) return true;
	return false;
}

float XIntersection(Line &_lineA, Line &_lineB) {
	float xIntersection;
	xIntersection = _lineA.Gradient() - _lineB.Gradient();
	xIntersection = (-_lineA.c() + _lineB.c()) / xIntersection;
	return xIntersection;
}

bool IsIntersect(Line &_lineA, Line &_lineB) {
	float xIntersection = XIntersection(_lineA, _lineB);
	float yIntersection = _lineA.Gradient()*xIntersection + _lineA.c();
	if (isInrange(yIntersection, _lineA.vertexA->y, _lineA.vertexB->y) && isInrange(yIntersection, _lineB.vertexA->y, _lineB.vertexB->y)){
		return true;
	}
	return false;
}

int SweepLineIntersections(Line *a, Line *b) {
	int number = 0;
	std::vector<Line*>lines;
	lines.push_back(a);
	lines.push_back(b);                                                                                                                                                                                                                         
	return number;
}

int cekpersamaan(Line &line) {
	float x[10][10];
	int j = 0;
	float c = line.c();
	float m = line.Gradient() * -1;
	int x1 = line.vertexA->x;
	int y1 = line.vertexA->y;
	int x2 = line.vertexB->x;
	int y2 = line.vertexB->y;

	if (y1 > y2) {
		int temp = y2;
		y2 = y1;
		y1 = temp;
	}

	return 0;
}
int main()
{
	std::vector<Line*> lines;
	lines.push_back(new Line(new Vertex(1.0f, 1.0f), new Vertex(3.0f, 4.0f)));
	lines.push_back(new Line(new Vertex(2.0f, 3.0f), new Vertex(4.0f, 1.0f)));
	lines.push_back(new Line(new Vertex(2.0f, 6.0f), new Vertex(5.0f, 5.0f)));
	lines.push_back(new Line(new Vertex(2.0f, 1.0f), new Vertex(8.0f, 4.0f)));
	lines.push_back(new Line(new Vertex(5.0f, 7.0f), new Vertex(7.0f, 2.0f)));
	
	std::clock_t start;
	long double duration;

	start = std::clock();

	int jumlah = 0;
	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines.size(); j++) {
			if (IsIntersect(*lines[i], *lines[j])) { 
				jumlah++; 
			}
		}
	}
	for (int i = 0; i < lines.size(); i++) {
		cekpersamaan(*lines[i]);
	}
	duration = (std::clock() - start) / (long double)CLOCKS_PER_SEC;
	std::cout <<"BRUTAL FORCE!: "<<jumlah/2<<"    TIME:"<<duration <<std::endl;
	start = std::clock();
	SweepLine2 *sweepLine = new SweepLine2(lines);
	duration = (std::clock() - start) / (long double)CLOCKS_PER_SEC;
	std::cout <<"    TIME:" << duration << std::endl;

	std::cout << "DONE!";
	int ab;
	std::cin >> ab;
	return 0;
}

