#ifndef _TIMEOUTPLUGIN_HPP_
#define _TIMEOUTPLUGIN_HPP_

#include "../../endpoint/endpoint.hpp"
#include "../../mutex/mutexShared.hpp"
#include <thread>
#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>

template< int S , typename T>
struct TimeOutPlugin{
  private:
    T instance;

  public:
    TimeOutPlugin(){};
    ~TimeOutPlugin(){};

    void start(const std::function<bool(const EndPoint& ep)> condition){ // stop everything after S seconds
      std::thread background_thread([this, condition]() {  // create background thread
          std::this_thread::sleep_for(std::chrono::seconds(S));
          std::unique_lock<std::mutex> lock(sharedMutex, std::defer_lock);

          lock.lock(); // lock mutex
          auto now = std::chrono::system_clock::now(); // check timestamp of execution
          std::cout << "Executed at " << std::chrono::system_clock::to_time_t(now) << std::endl;
          this->stop(condition);
          
          lock.unlock(); // unlock mutex
      });

      background_thread.detach();  // could be join() if you want to simplify
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

    T& getInstance(){
      return instance;
    }
};

#endif