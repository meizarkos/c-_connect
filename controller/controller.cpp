#include "controller.hpp"

#include <iostream>
#include <iomanip>

void Controller::operator+=(const EndPoint& ep){
  endPoints.push_back(ep);
}

void Controller::operator-=(const std::string& id){
  for(auto it = endPoints.begin(); it != endPoints.end(); ++it){
    if(it->getId() == id){
      endPoints.erase(it);
      std::cout<<"EndPoint "<<id<<" removed"<<std::endl;
      break;
    }
  }
}

void Controller::operator-=(const EndPoint& toDelete){
  *this -= toDelete.getId();
}

void Controller::start(const std::function<bool(const EndPoint& ep)> condition) {
  for (auto& ep : endPoints) {
      if (condition(ep)) {  // condition is test for each enpoint ( it is a function )
          std::cout<<"Starting"<<std::endl;
          ep.start();
      }
  }
}

void Controller::stop(const std::function<bool(const EndPoint& ep)> condition) {
  for (auto& ep : endPoints) {
      if (condition(ep)) {
          ep.stop();
      }
  }
}

void Controller::status() const {
  if(endPoints.empty()){
    std::cout<<"No EndPoint in the controller"<<std::endl;
    return;
  }
  const int fieldWidth = 15;
  for (const auto& ep : endPoints) {
      std::cout << std::setw(fieldWidth) << ep.getId() << " |"
                << std::setw(fieldWidth) << ep.getLocation() << " |"
                << std::setw(fieldWidth) << ep.getType() << " |"
                << std::setw(fieldWidth) << ep.status() << std::endl;
  }
}