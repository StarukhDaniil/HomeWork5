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
	Logger& logger = Logger::getInstance();
	ConfigManager& config_manager = ConfigManager::getInstance();
	return 0;
}