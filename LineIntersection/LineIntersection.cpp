// LineIntersection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GL/glew.h"
#include <iostream>
#include <vector>
#include <ctime>
#include "Line.h"
#include "BruteForce.h"
#include "SweepLine2.h"

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
	
	BruteForce *bruteForce = new BruteForce(lines);
	std::cout << "BRUTAL FORCE!: " << bruteForce->Result()/2;
	duration = (std::clock() - start) / (long double)CLOCKS_PER_SEC;
	std::cout << "    TIME:" << duration << std::endl;
	
	start = std::clock();

	SweepLine2 *sweepLine = new SweepLine2(lines);
	duration = (std::clock() - start) / (long double)CLOCKS_PER_SEC;
	std::cout <<"    TIME:" << duration << std::endl;

	std::cout << "DONE!";
	int ab;
	std::cin >> ab;
	return 0;
}

