#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

class Logger {
private:
	std::string getCurrentTime() const {
		auto now = std::chrono::system_clock::now();
		auto time_t_now = std::chrono::system_clock::to_time_t(now);
		return std::format("{:%H:%M:%S}", *std::localtime(&time_t_now));
	}

	Logger() = default;
public:
	static Logger& getInstance() {
		static Logger logger;
		return logger;
	}

	void log(std::string message) const {
		std::ofstream logFile("log.txt", std::ios::app);
		if (logFile.is_open()) {
			logFile << getCurrentTime() << " - " << message << std::endl;
		}
		else {
			std::cerr << "File opening is unsuccesful :(" << std::endl;
		}
	}

	Logger(const Logger&) = delete;
	Logger operator=(const Logger&) = delete;
	~Logger() = default;
};

int main() {
	int a;
	Logger::getInstance().log("asd");
	std::cin >> a;
	Logger::getInstance().log("asdfg");
	return 0;
}