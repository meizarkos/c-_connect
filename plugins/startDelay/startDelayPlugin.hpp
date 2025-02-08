#ifndef _STARTDELAYPLUGIN_HPP_
#define _STARTDELAYPLUGIN_HPP_

#include "../../endpoint/endpoint.hpp"
#include "../../mutex/mutexShared.hpp"
#include <thread>
#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>

template< int S , typename T>
struct StartDelayPlugin{
  private:
    T instance;

  public:
    StartDelayPlugin(){};
    ~StartDelayPlugin(){};

    void start(const std::function<bool(const EndPoint& ep)> condition){
      std::thread background_thread([this, condition]() {  // create background thread
          std::this_thread::sleep_for(std::chrono::seconds(S));
          std::unique_lock<std::mutex> lock(sharedMutex, std::defer_lock);

          lock.lock(); // lock mutex
          auto now = std::chrono::system_clock::now(); // check timestamp of execution
          std::cout << "Executed at " << std::chrono::system_clock::to_time_t(now) << std::endl;
          instance.start(condition);
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

    T& getInstance(){ // return the instance of the controller if we delete & it return a copy
      return instance;
    }
};

#endif