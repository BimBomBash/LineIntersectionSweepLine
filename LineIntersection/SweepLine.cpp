#include "stdafx.h"
#include <vector>
#include "Line.h"
#include <algorithm>
#include <iostream>
#include "SweepLine.h"


void SweepLine::AddEvents(std::vector <Line*> &line)
{
	for (int i = 0; i < line.size(); i++) {
		if (line[i]->vertexA->y>=line[i]->vertexB->y) {
			events.push_back(Event(START, i, line[i]->vertexA->x,line[i]->vertexA->y));
			events.push_back(Event(END, i, line[i]->vertexB->x, line[i]->vertexB->y));
		}
		else {
			events.push_back(Event(START, i, line[i]->vertexB->x, line[i]->vertexB->y));
			events.push_back(Event(END, i, line[i]->vertexA->x,line[i]->vertexA->y));
		}
	}
	std::sort(events.begin(), events.end());
	std::reverse(events.begin(), events.end());
}

void SweepLine::Sweep(std::vector<Line*>& line)
{
	int number = 0;

	
	for (int i = 0; i < events.size(); i++) {
		if (events[i].type == START) {
			if (!line[events[i].lineIndex]->processed && linesPoll.empty()) linesPoll.push_back(line[events[i].lineIndex]);
			else if (!line[events[i].lineIndex]->processed) {
				for (int n = 0; n < linesPoll.size(); n++) {
					if (n == linesPoll.size() - 1) {
						linesPoll.insert(linesPoll.begin() + n, line[events[i].lineIndex]);
						break;
					}
					else if ((events[i].y + line[events[i].lineIndex]->c()) / abs(line[events[i].lineIndex]->Gradient()) >= (events[i].y + linesPoll[n]->c()) / abs((linesPoll[n]->Gradient()))) {
						linesPoll.insert(linesPoll.begin() + n, line[events[i].lineIndex]);
						break;
					}
				}
			}
		}
	
		else {
			if (linesPoll.size() > 1) {
				for (int j = 0; j < linesPoll.size() - 1; j++) {
					if ((events[i].y + linesPoll[j]->c()) / abs(linesPoll[j]->Gradient()) >= (events[i].y + linesPoll[j + 1]->c()) / abs((linesPoll[j + 1]->Gradient()))) {
						//std::cout << "Line: (" << linesPoll[j]->vertexA->x << ", " << linesPoll[j]->vertexA->y << ") (" << linesPoll[j]->vertexB->x << ", " << linesPoll[j]->vertexB->y << ") and line (" << "(" << linesPoll[j + 1]->vertexA->x << ", " << linesPoll[j + 1]->vertexA->y << ") (" << linesPoll[j + 1]->vertexB->x << ", " << linesPoll[j + 1]->vertexB->y << ")" << std::endl;
						std::swap(linesPoll[j], linesPoll[j + 1]);
						number++;
						std::cout << "Line: (" << linesPoll[j]->vertexA->x << ", " << linesPoll[j]->vertexA->y << ") (" << linesPoll[j]->vertexB->x << ", " << linesPoll[j]->vertexB->y << ") and line (" << "(" << linesPoll[j + 1]->vertexA->x << ", " << linesPoll[j + 1]->vertexA->y << ") (" << linesPoll[j + 1]->vertexB->x << ", " << linesPoll[j + 1]->vertexB->y << ")" << std::endl;
						break;
					}
				}
			}
			for (int iter = 0; iter < linesPoll.size(); ++iter)
			{
				if (linesPoll[iter] == line[events[i].lineIndex])
				{
					std::cout << "Took Out Line: (" << linesPoll[iter]->vertexA->x << ", " << linesPoll[iter]->vertexA->y << ") (" << linesPoll[iter]->vertexB->x << ", " << linesPoll[iter]->vertexB->y << ")" << std::endl; ;
					line[events[i].lineIndex]->processed = true;
					linesPoll.erase(linesPoll.begin()+iter);
					break;
				}
			}
	}
	if (linesPoll.size()>0) std::sort(linesPoll.begin(), linesPoll.end());
	}
	std::cout << std::endl<<"SweepLine: " << number << std::endl;
}

SweepLine::SweepLine()
{
}

SweepLine::SweepLine(std::vector <Line*> &line)
{
	AddEvents(line);
}


SweepLine::~SweepLine()
{
}

Event::Event()
{
}

Event::Event(eventtype _type, int _lineIndex, float _x, float _y)
{
	lineIndex = _lineIndex;
	type = _type;
	x = _x;
	y = _y;
}

Event::~Event()
{
}
