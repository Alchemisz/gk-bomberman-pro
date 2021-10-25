#include "Point2D.h"

class LineSegment {
	private:
		Point2D beggining;
		Point2D end;
	public:
		LineSegment(Point2D points[2]);
		LineSegment(Point2D beggining, Point2D end);
		void setBeggining(Point2D point);
		void setEnd(Point2D point);
};