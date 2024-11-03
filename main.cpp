#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
	static Logger& getInstance() {
		static Logger logger;
		return logger;
	}
};

int main() {

}