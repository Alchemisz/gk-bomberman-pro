#include "LineSegment.h"

LineSegment::LineSegment(Point2D points[2]) {
	this->beggining = points[0];
	this->end = points[1];
}

LineSegment::LineSegment(Point2D beggining, Point2D end) {
	this->beggining = beggining;
	this->end = end;
}

void LineSegment::translate(float x, float y)
{
	this->beggining.translate(x, y);
	this->end.translate(x, y);
}

void LineSegment::rotate(float alpha)
{
	this->beggining.rotate(alpha);
	this->end.rotate(alpha);
}

void LineSegment::scale(float factor)
{
	this->beggining.scale(factor);
	this->end.scale(factor);
}

void LineSegment::setBeggining(Point2D point) {
	this->beggining = point;
}

void LineSegment::setEnd(Point2D point) {
	this->beggining = end;
}

Point2D LineSegment::getBeggining() {
	return this->beggining;
}

Point2D LineSegment::getEnd()
{
	return this->end;
}
