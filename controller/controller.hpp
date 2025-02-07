#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_

#include <vector>
#include <functional>
#include "../endpoint/endpoint.hpp"

struct Controller{
    private:
      std::vector<EndPoint> endPoints;
  
    public:
      Controller(){};
      ~Controller(){
        for(auto& ep : endPoints){
          ep.stop();
        }
      };

      void operator+=(const EndPoint& ep);
      void operator-=(const std::string& id);
      void operator-=(const EndPoint& ep);

      void start(const std::function<bool(const EndPoint&)> condition);
      void stop(const std::function<bool(const EndPoint&)> condition);
      void status()const;
};


#endif