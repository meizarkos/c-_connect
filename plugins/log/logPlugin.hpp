#ifndef _LOGPLUGIN_HPP_
#define _LOGPLUGIN_HPP_

//https://www.reddit.com/r/cpp_questions/comments/pumi9r/does_c20_not_support_string_literals_as_template/

#include "../../endpoint/endpoint.hpp"
#include <functional>
#include <string>
#include <chrono>
#include <fstream>
#include <iostream>

template <auto N>
struct StringLitteral {
    constexpr StringLitteral(const char (&str)[N]) { 
      std::copy(str, str + N, value);
    }

    char value[N];
    auto operator<=>(const StringLiteral&) const = default;
    bool operator==(const StringLiteral&) const  = default;
};

template<StringLitteral LABEL, typename T>
struct LogPlugin{
  private:
    T instance;

    void writeLineinFile(const std::string endpointNewStatus)const{
      auto now = std::chrono::system_clock::now();
      std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
      char buffer[100];
      strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", nowTime); // convert timestamp to date

      std::ofstream file("output.txt", std::ios::app); //append mode
      if (file.is_open()) {
        file << LABEL <<" "<< buffer << " : " << endpointNewStatus << std::endl;  //comme pour cout mais dans un fichier
        std::cout << "Time written to file: " << buffer << std::endl;
      } else {
          std::cerr << "Error opening file!" << std::endl;
      }
    };

  public:
    LogPlugin(){};
    ~LogPlugin(){};

    void start(const std::function<bool(const EndPoint& ep)> condition){
      writeLineinFile("Start");
      instance.start(condition);
      //instance.status();
    }

    void stop(const std::function<bool(const EndPoint& ep)> condition){
      writeLineinFile("Stop");
      instance.stop(condition);
    }

    void operator+=(const EndPoint& ep){
      instance += ep;
    }

    void operator-=(const EndPoint& ep){
      instance -= ep;
    }

    void operator-=(const std::string& id){
      instance -= id;
    }

    T& getInstance(){ // return the instance of the controller if we delete & it return a copy
      return instance;
    }
};

#endif