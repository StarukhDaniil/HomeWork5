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

	std::string getCurrentTime() const {
		auto now = std::chrono::system_clock::now();
		auto time_t_now = std::chrono::system_clock::to_time_t(now);
		return std::format("{:%H:%M:%S}", *std::localtime(&time_t_now));
	}

};

int main() {

}