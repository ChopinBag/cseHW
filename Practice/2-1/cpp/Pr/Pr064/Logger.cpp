#include "Logger.h"
#include <iostream>

using namespace std;

int Logger::logLevel = LogLevel::DEBUG;
// Implememt your code
//private:

// Helper function to convert LogLevel to string representation
// std::string Logger::levelToString(LogLevel level){}


//public:

void Logger::setLogLevel(LogLevel level){
    logLevel = level;
}

// Logging methods (all static)
void Logger::debug(const std::string& message, const std::string& tag){
    if(logLevel <= LogLevel::DEBUG){
        cout << "[DEBUG][" << tag << "] " << message << endl;
    }
    return;
}
void Logger::info(const std::string& message, const std::string& tag){
    if(logLevel <= LogLevel::INFO){
        cout << "[INFO][" << tag << "] " << message << endl;
    }
    return;
}
void Logger::warning(const std::string& message, const std::string& tag){
    if(logLevel <= LogLevel::WARNING){
        cout << "[WARNING][" << tag << "] " << message << endl;
    }
    return;
}
void Logger::error(const std::string& message, const std::string& tag){
    if(logLevel <= LogLevel::ERROR){
        cout << "[ERROR][" << tag << "] " << message << endl;
    }
    return;
}