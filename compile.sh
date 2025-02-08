#!/bin/bash

g++ -std=c++20 main.cpp $(find ./utils -name "*.cpp") $(find ./mutex -name "*.cpp") $(find ./endpoint -name "*.cpp") $(find ./controller -name "*.cpp") $(find ./plugins -name "*.cpp")

