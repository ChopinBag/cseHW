# include <string>
# include <iostream>
# include <limits>
# include <map>

using namespace std;

char toLowerCase(const char ch) {
	char lowerCh;
	if ( ch >= 'A' && ch <= 'Z') // portability
		lowerCh = ch + ( 'a' - 'A' );
	else
		lowerCh = ch;
	return lowerCh;
}
string toLowerCase(const string& str) { // stack
	string lowerCase{str}; // copy constructor
	for ( int i{0}; i < str.length(); i ++ ) {
		const char ch = str.at(i);
		
		lowerCase[i] = toLowerCase(ch);
	}
	return lowerCase;
}

int getIndex(const string& typeName) {
	static string typeNames[] = {"int", "float"};
	for ( int i = 0; i < 2; i ++ )
		if ( typeNames[i] == typeName ) return i;
	return -1;
}
void printInt() {
	cout << numeric_limits<int>::min() << '\t';
	cout << numeric_limits<int>::max() << endl;
}
void printFloat() {
	cout << numeric_limits<float>::min() << '\t';
	cout << numeric_limits<float>::max() << endl;
}

void (*getFunction(const string& typeName)) () {
	// version 1: use two arrays
	static string typeNames[] = {"int", "float"};
	static void (*fps[2])() = {printInt, printFloat};

	for ( int i = 0; i < 2; i ++ ) {
		if ( typeNames[i] == typeName ) return fps[i];
	}	
	return nullptr;

	// version 2 : use map

//	map<string, void (*)()> fpMap;
//	fpMap.insert(pair<string, void (*)()>("int", printInt));
//	fpMap.insert(pair<string, void (*)()>("float", printFloat));
//
//	for (auto it = fpMap.begin(); it != fpMap.end(); ++it )
//    	if ( it->first == typeName ) return it->second;
//    	
//    return nullptr;
}

int main() {
	string typeString;
	cin >> typeString; // 1K
	
	string lowerCase = toLowerCase(typeString);
	cout << lowerCase << endl;
	
	void (*fp)() = getFunction(lowerCase);
	fp();
}
