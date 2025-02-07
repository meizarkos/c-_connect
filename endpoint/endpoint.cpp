#include "endpoint.hpp"

void EndPoint::start(){
    if(!isRunning){
        isRunning = true;
    }
}

void EndPoint::stop(){
    if(isRunning){
        isRunning = false;
    }
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

