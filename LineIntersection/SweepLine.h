#pragma once

enum eventtype { START, END };

struct Event {
	Event();
	Event(eventtype _type, int _lineIndex,float _x ,float _y);
	~Event();

	eventtype type;

	int lineIndex;
	float y;
	float x;

	bool operator <(const Event &b) const
	{
		if (b.y!= y) return y < b.y;
		else if (b.x != x) return type < b.type;
		else return x < b.x;
	}
};

class SweepLine
{
private:
	std::vector <Event> events;
	std::vector <Line*> linesPoll;
public:
	void AddEvents(std::vector <Line*> &line);
	void Sweep(std::vector <Line*> &line);

	SweepLine();
	SweepLine(std::vector <Line*> &line);
	~SweepLine();
};

