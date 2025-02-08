#ifndef _LOGPLUGIN_HPP_
#define _LOGPLUGIN_HPP_

//https://www.reddit.com/r/cpp_questions/comments/pumi9r/does_c20_not_support_string_literals_as_template/

#include "../../endpoint/endpoint.hpp"
#include "../../utils/utils.cpp"
#include <functional>
#include <string>
#include <chrono>
#include <fstream>
#include <iostream>

template<size_t N>
struct StringLiteral {
    constexpr StringLiteral(const char (&str)[N]) { // the value of str can be evaluate at compile time due to constexpr     
      std::copy_n(str, N, value); 
    }

    char value[N];
    
    friend std::ostream& operator<<(std::ostream& os, const StringLiteral<N>& sl){
      os << sl.value;
      return os;
    }
};

template<StringLiteral LABEL, typename T> // Since StringLiteral is evaluate at compile time, it can be used as a template parameter
struct LogPlugin{
  private:
    T instance;

    void writeLineinFile(const std::string endpointNewStatus)const{
      
      std::string date = convertNowtoLocalTime();

      std::ofstream file("output.txt", std::ios::app); //append mode
      if (file.is_open()) {
        file << LABEL <<" "<< date << " : " << endpointNewStatus << std::endl;  //comme pour cout mais dans un fichier
        std::cout << "Time written to file: " << date << std::endl;
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