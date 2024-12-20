#pragma once

#include <string>
#include <vector>
#include <iostream>

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
	ConfigManager() = default;
public:
	void setConfig(const std::string key, const std::string value) {
		config.push_back(Config(key, value));
	}

	std::string getConfig(const std::string key) {
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
		static ConfigManager configManager;
		return configManager;
	}
};