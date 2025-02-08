#include "endpoint.hpp"

#include <chrono>
#include <iostream>

void EndPoint::start(){
    if(!isRunning){
        isRunning = true;
        startedAt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        //std::cout << startedAt << std::endl;
    }
}

void EndPoint::stop(){
    if(isRunning){
        isRunning = false;
        timeOn += std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - startedAt;
        startedAt = -1;
        //std::cout << timeOn << std::endl;
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

int EndPoint::getTimeOn()const{
    return timeOn;
}

int EndPoint::getStartedAt()const{
    return startedAt;
}

