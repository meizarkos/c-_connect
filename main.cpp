#include <iostream>
#include "./endpoint/endpoint.hpp"
#include "./controller/controller.hpp"
#include "./plugins/startDelay/startDelayPlugin.hpp"
#include <chrono>

int main(){

  EndPoint ep("Tondeuse", "Essence", "Sous-sol");
  EndPoint ep2("Robinet", "Eau", "Sous-sol");
  EndPoint ep3("Masseur", "Electrique", "Quelque part");
  EndPoint ep4("Four", "Electrique", "Cuisine");
  EndPoint ep5("Lave-linge", "Manuel", "Salle de bain");
  
  /*Controller controller;
  controller += ep;
  controller += ep2;
  controller += ep3;
  controller += ep4;
  controller += ep5;*/

  std::cout << std::boolalpha;
  StartDelayPlugin<1, Controller> startDelayPlugin;

  startDelayPlugin += ep;
  startDelayPlugin += ep2;
  startDelayPlugin += ep3;

  auto now = std::chrono::system_clock::now();
  std::cout << "Starting at " << std::chrono::system_clock::to_time_t(now) << std::endl;
  startDelayPlugin.start([](const EndPoint& ep){
    return ep.getLocation() == "Sous-sol";
  });
  now = std::chrono::system_clock::now();
  std::cout << "Started at " << std::chrono::system_clock::to_time_t(now) << std::endl;

  startDelayPlugin.stop([](const EndPoint& ep){
    return ep.getLocation() == "Sous-sol";
  });

  return 0;
}