#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

enum Color { RED, BLUE, YELLOW };

class Point {
	float x, y;
public:
	Point(const float _x = 0, const float _y = 0) : x(_x), y(_y) {};

	float getX() const { return x; }
	float getY() const { return y; }
	
	float getDistance(const Point& other) const {
		return sqrt( (x-other.x) * (x-other.x) + (y-other.y) * (y-other.y) ) ;
	}
};
ostream& operator << (ostream& os, const Point& p) {
	os << '(' << p.getX() << ", " << p.getY() << ')';
	return os;
}

class Shape {
	Color lineColor;
public:
	Color getLineColor() const { return lineColor; }

	virtual Shape* clone() const = 0;

	virtual void print() const = 0;

	virtual float getLength() const = 0;
};

class ClosedShape : public Shape {
public:
	virtual float getArea() const = 0;
};

class Polygon : public ClosedShape {
protected:
	vector<Point> points;
public:
	void addPoint(const Point& p) { points.push_back(p); }

	virtual Shape* clone() const override {
		Polygon* const clone = new Polygon(*this);
		return clone;
	}
	
	virtual void print() const override {
		cout << "Polygon: ";
		for (const auto& point : points) {
			cout << point;
		}
		cout << endl;
	}
	virtual float getArea() const override {
		float area = 0;
		for (int i = 0; i < points.size() - 2; i++) {
			const int j = (i + 1) % points.size();
			const int k = (i + 2) % points.size();
			const Point & pt1 = points[i];
			const Point & pt2 = points[j];
			const Point & pt3 = points[k];

			const int x1 = pt1.getX();
			const int y1 = pt1.getY();
			const int x2 = pt2.getX();
			const int y2 = pt2.getY();
			const int x3 = pt3.getX();
			const int y3 = pt3.getY();

			float subArea = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
			area += fabs(subArea / 2);
		}
		return area;
	}
	virtual float getLength() const override {
		float length = 0 ;
		for ( int i = 0 ; i < points.size() ; i ++ ) {
			const int j = ( i + 1 ) % points.size() ;
			const Point& pt1 = points[i] ;
			const Point& pt2 = points[j] ;

			length += pt1.getDistance(pt2) ;
		}

		return length ;
	}
};

class Triangle : public Polygon {
public:
	Triangle(const Point& p1, const Point& p2, const Point& p3) : Polygon() {
		addPoint(p1);
		addPoint(p2);
		addPoint(p3);
	}
	virtual void print() const override {
		cout << "Triangle: ";
		for (const auto& point : points) {
			cout << point;
		}
		cout << endl;
	}
};

class Rectangle : public Polygon {
public:
	Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4) : Polygon() {
		addPoint(p1);
		addPoint(p2);
		addPoint(p3);
		addPoint(p4);
	}
	virtual void print() const override {
		cout << "Rectangle: ";
		for (const auto& point : points) {
			cout << point;
		}
		cout << endl;
	}
};


class ClosedShapeList {
	vector<ClosedShape*> shapes;
	
	void removeShapes() {
		for ( auto shape : shapes )
			delete shape;
	}
	void copyShapes(const ClosedShapeList& list) {
		for ( const auto shape: list.getShapes() )
			addShape(shape);
	}
public:
	ClosedShapeList() = default;
	// Copy constructor
	ClosedShapeList(const ClosedShapeList& list) {
		copyShapes(list);
	}
	// Destructor
	~ClosedShapeList() {
		removeShapes();
	}
	// Assignment operator
	ClosedShapeList& operator = (const ClosedShapeList& list) {
		removeShapes();
		copyShapes(list);
	}
	
	vector<ClosedShape*> getShapes() const { return shapes; }
	
	void addShape(ClosedShape* const shape) {
		ClosedShape* const clone = dynamic_cast<ClosedShape*>(shape->clone());
		shapes.push_back(clone);
	}
	void print() const {
		for (const auto shape : shapes)
			shape->print();
	}
	float getTotalArea() const {
		auto totalArea = 0.0F;
		for (const auto shape : shapes)
			totalArea += shape->getArea();
		return totalArea;
	}
	
};


int main() {
	Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30);

	ClosedShape* const r = new Rectangle(p1, p2, p3, p4);
	ClosedShape* const t = new Triangle(p1, p2, p3);

	ClosedShapeList list{};
	list.addShape(r);
	list.addShape(t);
	delete r;
	delete t;

	list.print();
	cout << list.getTotalArea() << endl;
}
