#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#pragma warning(disable: 4996)

enum class LogLevels {
	info = 0,
	warning = 1,
	error = 2,
};

class Logger {
private:
	std::string getCurrentTime() const {
		auto now = std::chrono::system_clock::now();
		auto time_t_now = std::chrono::system_clock::to_time_t(now);
		std::tm* tm_now = std::localtime(&time_t_now);

		std::ostringstream oss;
		oss << std::put_time(tm_now, "%H:%M:%S");
		return oss.str();
	}

	Logger() = default;
public:
	static Logger& getInstance() {
		static Logger logger;
		return logger;
	}

	void log(std::string message, LogLevels logLevel) const {
		std::ofstream logFile("log.txt", std::ios::app);
		if (logFile.is_open()) {
			switch (logLevel) {
			case LogLevels::info:
				logFile << "Info: " << getCurrentTime() << " - " << message << std::endl;
				break;
			case LogLevels::warning:
				logFile << "Warning: " << getCurrentTime() << " - " << message << std::endl;
				break;
			case LogLevels::error:
				logFile << "Error: " << getCurrentTime() << " - " << message << std::endl;
				break;
			default:
				std::cerr << "Wrong LogLevel catched :(" << std::endl;
			}
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
	Logger::getInstance().log("asd", LogLevels::info);
	Logger::getInstance().log("asd", LogLevels::warning);
	return 0;
}