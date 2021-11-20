#pragma once
#include "Point2D.h"

class LineSegment : public TransformableObject {
	private:
		Point2D beggining;
		Point2D end;
	public:
		LineSegment(Point2D points[2]);
		LineSegment(Point2D beggining, Point2D end);
		virtual void translate(float x, float y);
		virtual void rotate(float alpha);
		virtual void scale(float factor);
		void setBeggining(Point2D point);
		void setEnd(Point2D point);
		Point2D getBeggining();
		Point2D getEnd();
};