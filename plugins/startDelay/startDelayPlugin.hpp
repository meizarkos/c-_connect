#ifndef _STARTDELAYPLUGIN_HPP_
#define _STARTDELAYPLUGIN_HPP_

#include "../../endpoint/endpoint.hpp"
#include <thread>
#include <chrono>
#include <functional>

template< int S , typename T>
struct StartDelayPlugin{
  private:
    T instance;

  public:
    StartDelayPlugin(){};
    ~StartDelayPlugin(){};

    void start(const std::function<bool(const EndPoint& ep)> condition){
      std::this_thread::sleep_for(std::chrono::seconds(S));
      instance.start(condition);
      instance.status();
    }

    void stop(const std::function<bool(const EndPoint& ep)> condition){
      instance.stop(condition);
      instance.status();
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
};

#endif