#include "./endpoint/endpoint.hpp"
#include "./controller/controller.hpp"
#include "./plugins/startDelay/startDelayPlugin.hpp"
#include "./plugins/timeOut/timeOutPlugin.hpp"
#include "./plugins/log/logPlugin.hpp"
#include "./mutex/mutexShared.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

int main(){

  EndPoint ep("Tondeuse", "Essence", "Sous-sol");
  EndPoint ep2("Robinet", "Eau", "Sous-sol");
  EndPoint ep3("Masseur", "Electrique", "Quelque part");
  EndPoint ep4("Four", "Electrique", "Cuisine");
  EndPoint ep5("Lave-linge", "Manuel", "Salle de bain");

  /*
  ep.start();

  std::this_thread::sleep_for(std::chrono::milliseconds(5990));

  ep.stop();
  ep.start();

  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  ep.stop();
  */

  /*Controller controller;
  controller += ep;
  controller += ep2;
  controller += ep3;
  controller += ep4;
  controller += ep5;*/

  std::cout << std::boolalpha;

  /*
  StartDelayPlugin<1, Controller> startDelayPlugin;
  startDelayPlugin += ep;
  startDelayPlugin += ep2;
  startDelayPlugin += ep3;

  auto now = std::chrono::system_clock::now();
  std::cout << "Starting at " << std::chrono::system_clock::to_time_t(now) << std::endl;

  startDelayPlugin.start([](const EndPoint& ep){
    return ep.getLocation() == "Sous-sol";
  });

  startDelayPlugin.stop([](const EndPoint& ep){
    return ep.getLocation() == "Sous-sol";
  });

  std::this_thread::sleep_for(std::chrono::milliseconds(1)); //wait for the thread to finish

  std::unique_lock<std::mutex> lock(sharedMutex, std::defer_lock); //is theorically useless
  lock.lock();
  now = std::chrono::system_clock::now();
  std::cout << "Ended at " << std::chrono::system_clock::to_time_t(now) << std::endl;
  startDelayPlugin.getInstance().status();
  lock.unlock();

  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  startDelayPlugin.getInstance().status();
  */

  /*
  TimeOutPlugin<1, Controller> timeOutPlugin;
  timeOutPlugin += ep;
  timeOutPlugin += ep2;
  timeOutPlugin += ep3;

  timeOutPlugin.getInstance().start([](const EndPoint& ep){
    return ep.getLocation() == "Sous-sol";
  });

  timeOutPlugin.getInstance().status();

  timeOutPlugin.start([](const EndPoint& ep){ // stop sous-sol after 1 seconds
    return ep.getLocation() == "Sous-sol";
  });

  std::this_thread::sleep_for(std::chrono::milliseconds(500)); //wait for the thread to finish

  std::unique_lock<std::mutex> lock(sharedMutex, std::defer_lock); //is theorically useless
  lock.lock();
  auto now = std::chrono::system_clock::now();
  std::cout << "Ended at " << std::chrono::system_clock::to_time_t(now) << std::endl;
  timeOutPlugin.getInstance().status();
  lock.unlock();

  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  */

  StartDelayPlugin<1, LogPlugin<"TEST", Controller>> logDelayPlugin;
  logDelayPlugin += ep;
  logDelayPlugin += ep2;
  logDelayPlugin += ep3;

  return 0;
}