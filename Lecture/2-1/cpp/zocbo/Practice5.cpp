#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

struct Rectangle {
	int width;
	int height;
};

enum class CommandKind { ADD, SORT, PRINT, CLEAR, EXIT, INVALID };

string toLowerCase(const string& str) {
	string lowerCase(str);
	for ( char& character : lowerCase ) {
		if (character >= 'A' && character <= 'Z') {
			character += 'a' - 'A';
		}
	}
	return lowerCase;
}

CommandKind getCommandKind(const string& commandString) {
	const string& commandLower = toLowerCase(commandString);
	CommandKind command;

	if (commandLower == "add") {
		command = CommandKind::ADD;
	}
	else if (commandLower == "sort") {
		command = CommandKind::SORT;
	}
	else if (commandLower == "print") {
		command = CommandKind::PRINT;
	}
	else if (commandLower == "clear") {
		command = CommandKind::CLEAR;
	}
	else if (commandLower == "exit") {
		command = CommandKind::EXIT;
	}
	else {
		command = CommandKind::INVALID;
	}
	return command;
}

Rectangle getRectangle() {
	Rectangle rectangle;
	int width, height;
	cin >> width >> height;
	rectangle.width = width;
	rectangle.height = height;

	return rectangle;
}

int getRectangleArea(const Rectangle& rectangle) {
	return rectangle.width * rectangle.height;
}

void print(const vector<Rectangle>& rectangles) {
	cout << "Rectangle Count: " << rectangles.size() << endl;
	for (vector<Rectangle>::const_iterator rectangleIterator = rectangles.begin(); rectangleIterator != rectangles.end(); ++rectangleIterator) {
		const Rectangle& rectangle = *rectangleIterator;
		cout << "\t" << rectangle.width << " " << rectangle.height << " " << getRectangleArea(rectangle) << endl;
	}
}

void swap(Rectangle& rectangle1, Rectangle& rectangle2) {
	Rectangle tempRectangle = rectangle1;
	rectangle1 = rectangle2;
	rectangle2 = tempRectangle;
}

void sort(vector<Rectangle>& rectangles) {
	for (vector<Rectangle>::iterator iteratorLeft = rectangles.begin(); iteratorLeft != rectangles.end() - 1; ++iteratorLeft) {
		for (vector<Rectangle>::iterator iteratorRight = iteratorLeft + 1; iteratorRight != rectangles.end(); ++iteratorRight) {
			Rectangle& rectangleLeft = *iteratorLeft;
			Rectangle& rectangleRight = *iteratorRight;
			if ( getRectangleArea(rectangleLeft) > getRectangleArea(rectangleRight) ) { 
				swap(rectangleLeft, rectangleRight);
			}
		}
	}
}

int main() {
	vector<Rectangle> rectangles;
	while (true) {
		string commandString;
		cin >> commandString;
		const CommandKind command = getCommandKind(commandString);
		
		switch (command) {
			case CommandKind::ADD: {
				const Rectangle& newRectangle = getRectangle();
				rectangles.push_back(newRectangle);
				break;
			}
			case CommandKind::PRINT:
				print(rectangles);
				// use const_iterator in print()
				// define and call print(const Rectangle&)
				break;
			case CommandKind::SORT: {
				sort(rectangles); // define and call swap in sort()
				print(rectangles);
				break;
			}
			case CommandKind::CLEAR: {
				break;
				rectangles.clear();
			}
			case CommandKind::EXIT: break;
			default: assert(false); break;
		}
		if (command == CommandKind::EXIT) break;
	}
}
