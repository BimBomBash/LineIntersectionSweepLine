#include "stdafx.h"
#include "Line.h"


float Line::Gradient()
{
	if ((vertexB->x - vertexA->x) == 0) return 0;
	else return ((vertexB->y - vertexA->y) / (vertexB->x - vertexA->x));
}

float Line::c()
{
	return (vertexA->y - Gradient()*vertexA->x);
}

Line::Line()
{
	processed = false;
}

Line::Line(Vertex *_vertexA, Vertex *_vertexB)
{
	vertexA = _vertexA;
	vertexB = _vertexB;
}


Line::~Line()
{
}

Vertex::Vertex()
{
}

Vertex::Vertex(float _x, float _y)
{
	x = _x;
	y = _y;
}
