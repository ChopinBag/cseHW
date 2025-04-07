// Implement your code
#include "input.h"
#include "bmi.h"
#include <iostream>
#include <sstream>


using namespace std;

Command parseCommand(const std::string& cmdStr) {
    if (cmdStr == "CREATE") return Command::CREATE;
    else if(cmdStr == "PRINT") return Command::PRINT;
    else if(cmdStr == "DELETE") return Command::DELETE;
    else if(cmdStr == "QUIT") return Command::QUIT;
    else return Command::UNKNOWN;
}

bool processCreateCommand(std::vector<int>& bmis, std::istringstream& iss) {
    int n,w,h;
    iss >> n;
    for (int i=0; i<n; i++) {
        iss >> w >> h;
        addBMI(bmis,w,h);
    }
    cout << bmis.size() << endl;
    return true;
}

bool processDeleteCommand(std::vector<int>& bmis, std::istringstream& iss) {
    int target;
    iss >> target;
    deleteByValue(bmis, target);
    cout << bmis.size() << endl;
    return true;
}

bool processCommand(std::vector<int>& bmis, const std::string& commandLine) {
    istringstream iss(commandLine);
    string s;
    iss >> s;
    if (parseCommand(s) == Command::CREATE) {
        return processCreateCommand(bmis, iss);
    }else if (parseCommand(s) == Command::PRINT) {
        return displayBMIs(bmis);
    }else if (parseCommand(s) == Command::DELETE) {
        return processDeleteCommand(bmis, iss);
    }else if (parseCommand(s) == Command::QUIT){
        cout << "Bye!" << endl;
        return false;
    }
    return false;
}