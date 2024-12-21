#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <shared_mutex>

class ConfigManager {
private:
	struct Config {
		std::string key;
		std::string value;

		Config(std::string key, std::string value) {
			this->key = key;
			this->value = value;
		}
	};

	std::vector<Config> config;
	static ConfigManager* instance;
	static std::shared_mutex mutex;

	ConfigManager() = default;
public:
	void setConfig(const std::string key, const std::string value) {
		std::lock_guard<std::shared_mutex> lock(mutex);
		config.push_back(Config(key, value));
	}

	std::string getConfig(const std::string key) {
		std::shared_lock<std::shared_mutex> slock(mutex);
		for (int i = 0; i < config.size(); i++) {
			if (key == config[i].key) {
				return config[i].value;
			}
		}
		throw std::runtime_error("Key is not found");
	}

	ConfigManager(const ConfigManager&) = delete;
	ConfigManager operator=(const ConfigManager&) = delete;
	~ConfigManager() = default;
	static ConfigManager& getInstance() {
		std::lock_guard<std::shared_mutex> lock(mutex);
		if (!instance) {
			instance = new ConfigManager();
			std::atexit([]() {delete instance; });
		}
		return *instance;
	}
};

ConfigManager* ConfigManager::instance = nullptr;
std::shared_mutex ConfigManager::mutex;