#!/bin/bash

g++ main.cpp $(find ./mutex -name "*.cpp") $(find ./endpoint -name "*.cpp") $(find ./controller -name "*.cpp") $(find ./plugins -name "*.cpp")

