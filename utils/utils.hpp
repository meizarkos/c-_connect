#ifndef UTILS_HPP
#define UTILS_HPP

#include <chrono>
#include <ctime>
#include <string>

inline std::string convertNowtoLocalTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
    std::tm* nowTimeLocal = std::localtime(&nowTime);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", nowTimeLocal);
    return std::string(buffer);
}

#endif 