#include "command_handler.h"
#include "word_manager.h"
#include <sstream>
#include <iostream>

using namespace std;

CommandType parseCommand(const string& cmd) {
    if (cmd == "FIND") return CommandType::FIND;
    if (cmd == "UPDATE") return CommandType::UPDATE;
    if (cmd == "DELETE") return CommandType::DELETE;
    if (cmd == "PRINT") return CommandType::PRINT;
    if (cmd == "QUIT") return CommandType::QUIT;
    else return CommandType::QUIT;
}

bool processCommand(map<string, size_t>& words, const string& line) {
    string str;
    stringstream ss(line);
    ss >> str;

    switch (parseCommand(str)) {
        case CommandType::FIND:
            ss >> str;
            findWord(words, str);
        break;
        case CommandType::UPDATE:
            int val;
            ss >> str;
            ss >> val;
            updateWord(words, str, val);
        break;
        case CommandType::DELETE:
            ss >> str;
            deleteWord(words, str);
        break;
        case CommandType::PRINT:
            printWords(words);
        break;
        case CommandType::QUIT:
            cout << "Bye!" << endl;
            return false;

    }
    return true;
}
