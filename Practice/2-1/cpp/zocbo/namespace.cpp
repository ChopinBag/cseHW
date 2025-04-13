# include <string>
# include <iostream>
# include <typeinfo>

using namespace std;

namespace shape {
	class Shape {
		public:
			virtual void draw() const = 0;
			virtual bool isEqual(Shape* s) const = 0;
			virtual Shape* clone() const = 0;
	};
	
	class Rectangle : public Shape {
		int x1, y1, x2, y2;
	public:
		Rectangle(const int x1=0, const int y1=0, const int x2=0, const int y2=0) {
			this->x1 = x1; this->y1 = y1;
			this->x2 = x2; this->y2 = y2;
		}
		virtual void draw() const override {
			cout << "Rectangle: " << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")" << endl;
		}
		virtual bool isEqual(Shape* s) const override {
			if ( typeid(*this) != typeid(*s) ) return false;
			Rectangle* r = dynamic_cast<Rectangle*>(s);
			
			return x1 == r->x1 && y1 == r->y1 && x2 == r->x2 && y2 == r->y2 ;
		}
		virtual Shape* clone() const override {
			return new Rectangle(*this);
		}	
	};
	
	class Circle : public Shape {
		int x, y;
		int radius;
	public:
		Circle(const int x=0, const int y=0, const int radius=0) {
			this->x = x; this->y = y;
			this->radius = radius;
		}	
		
		virtual void draw() const override {
			cout << "Circle: " << "(" << x << ", " << y << "), " << radius << endl;
		}
		virtual bool isEqual(Shape* s) const override {
			if ( typeid(*this) != typeid(*s) ) return false;
			
			Circle* c = dynamic_cast<Circle*>(s);
			
			return x == c->x && y == c->y && radius == c->radius ;
	
		}
		virtual Shape* clone() const override {
			return new Circle(*this);
		}	
	};
}

namespace mystl {
	template <class T, int size>
	class MyArrayList {
		T* data[size];
	public:
		MyArrayList() {
			for ( int i=0; i < size; i++ )
				data[i] = nullptr;
		}
		~MyArrayList() {
			for ( int i=0; i < size; i++ )
				if ( data[i] != nullptr ) {
					delete data[i];
				}	
		}
		// copy constructor, assignment operator
		
		bool addElement(T* element) {
			for ( int i=0; i < size; i++ )
				if ( data[i] == nullptr ) {
					data[i] = element->clone();
					return true;
				}
			return false;
		}
		bool removeElement(T* element) {
			for ( int i=0; i < size; i++ ) {
				if ( data[i] == nullptr ) continue;
				
				if ( element->isEqual(data[i]) ) {
					data[i] = nullptr;
					return true;
				}
			}
			return false;
		}
		int getSize() const { return size; }
		T* getElement(const int index) { return data[index];}
	};
}

int main() {
	
	shape::Shape* r1 = new shape::Rectangle(0, 0, 10, 10);
	shape::Shape* r2 = new shape::Rectangle(0, 0, 20, 20);

	shape::Shape* c1 = new shape::Circle(0, 0, 10);
	shape::Shape* c2 = new shape::Circle(10, 10, 20);
	
	mystl::MyArrayList<shape::Shape, 5> list;
	
	list.addElement(r1);
	list.addElement(r2);
	list.addElement(c1);
	list.addElement(c2);
	
	delete r2; delete c2;
	
	for ( int i=0; i < list.getSize(); i ++ ) {
		shape::Shape* s = list.getElement(i);
		if (  s == nullptr ) continue;
			
		s->draw();
	}
	
	list.removeElement(r1);
	list.removeElement(c1);

	for ( int i=0; i < list.getSize(); i ++ ) {
		shape::Shape* s = list.getElement(i);
		if (  s == nullptr ) continue;
		
		s->draw();
	}
}
