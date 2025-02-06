#include "endpoint.hpp"

void EndPoint::start(){
    isRunning = true;
}

void EndPoint::stop(){
    isRunning = false;
}

bool EndPoint::status()const{
    return isRunning;
}

std::string EndPoint::getLocation()const{
    return location;
}

std::string EndPoint::getType()const{
    return type;
}

std::string EndPoint::getId()const{
    return id;
}

