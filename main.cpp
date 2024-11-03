#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

class Logger {
public:
	static Logger& getInstance() {
		static Logger logger;
		return logger;
	}

};

int main() {

}