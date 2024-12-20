#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <vector>
#pragma warning(disable: 4996)

#include "Logger.h"
#include "ConfigManager.h"

int main() {
	Logger::getInstance().log("asd", LogLevels::info);
	Logger::getInstance().log("fgh", LogLevels::warning);
	ConfigManager::getInstance().setConfig("1", "qwerty");
	try {
		std::cout << ConfigManager::getInstance().getConfig("1") << std::endl;
		std::cout << ConfigManager::getInstance().getConfig("12") << std::endl;
	}
	catch (std::runtime_error error) {
		std::cerr << error.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown error" << std::endl;
	}

	return 0;
}