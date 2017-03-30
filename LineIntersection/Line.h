#pragma once
class Vertex {
public:
	Vertex();
	Vertex(float _x, float _y);

	float x;
	float y;
};

class Line
{
public:
	float Gradient();
	float c();
	Vertex *vertexA;
	Vertex *vertexB;
	bool processed = false;
	Line();
	Line(Vertex *_vertexA, Vertex *_vertexB);
	~Line();
};

