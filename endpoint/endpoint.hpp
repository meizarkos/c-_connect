#ifndef _ENDPOINT_HPP_
#define _ENDPOINT_HPP_

#include <string>

struct EndPoint{

    private:
        bool isRunning;
        std::string id;
        std::string location;
        std::string type;

    public:
        EndPoint(std::string id, std::string type,std::string location) : 
            isRunning(false), 
            id(id),
            location(location), 
            type(type) {};
        ~EndPoint() {}; // Destructor mais rien n'a besoin d'être détruit

        void start();
        void stop();

        bool status()const;
        std::string getLocation()const;
        std::string getType()const;
        std::string getId()const;
};

#endif
