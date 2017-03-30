#pragma once
class SweepLine2
{
	int NotBruteForceIntersection(int NumberOfLine);

	std::vector<Line*> line;
public:
	SweepLine2();
	SweepLine2(std::vector<Line*> &_line);
	~SweepLine2();

};

