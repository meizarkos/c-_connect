#ifndef _CHRONOPLUGIN_HPP_
#define _CHRONOPLUGIN_HPP_

#include "../../endpoint/endpoint.hpp"
#include "../../controller/controller.hpp"
#include "../../utils/utils.cpp"
#include <functional>
#include <string>
#include <chrono>
#include <iostream>
#include <thread>

template<typename T>
struct ChronoPlugin{

  private:

    T instance;

    void calculateUpTime(const EndPoint& ep){
      std::cout << "The endpoint " << ep.getId() << " has been running for " << ep.getTimeOn() << " seconds" << std::endl;
      if(ep.getStartedAt() != -1){
        auto now = std::chrono::system_clock::now();
        int onSince = std::chrono::system_clock::to_time_t(now) - ep.getStartedAt();
        std::cout << "It has been on without interrupt for :" << onSince << std::endl;
      }
    }

  public:
    ChronoPlugin(){};
    ~ChronoPlugin(){};

    void start(const std::function<bool(const EndPoint& ep)> condition){
      auto actu = instance;
      std::cout << std::string(type(actu)) << std::endl;
      while(1){
        actu = actu.getInstance();
        std::cout << std::string(typeid(actu).name()) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      }
      this->getInstance().getInstance().start(condition);
      instance.start(condition);
    }

    void stop(const std::function<bool(const EndPoint& ep)> condition){
      
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

    T operator=(const T& c){
      return c;
    }

    T& getInstance(){ // return the instance of the controller if we delete & it return a copy
      return instance;
    }
};

#endif