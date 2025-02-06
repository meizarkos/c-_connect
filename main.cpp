#include <iostream>
#include "./endpoint/endpoint.hpp"
#include "./controller/controller.hpp"


int main(){

  EndPoint ep("Tondeuse", "Essence", "Sous-sol");
  EndPoint ep2("Robinet", "Eau", "Sous-sol");
  EndPoint ep3("Masseur", "Electrique", "Quelque part");
  EndPoint ep4("Four", "Electrique", "Cuisine");
  EndPoint ep5("Lave-linge", "Manuel", "Salle de bain");
  
  Controller controller;
  controller += ep;
  controller += ep2;
  controller += ep3;
  controller += ep4;
  controller += ep5;

  std::cout << std::boolalpha;

  controller.status();

  controller.startBy([](const EndPoint& ep) {
    return ep.getType() == "Electrique";
  });

  controller.status();

  return 0;
}