/**
* @brief Assignment 8 Algorithms
* @name Adam Jennings
*/

#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <vector>

struct Region{
    int ID;
    std::string cityName;
    std::string state;
    std::string toString();
};

struct PriceRecord{
    int ID;
    std::string date;
    double value;
    std::string toString();
};

void printPartHeader(std::string title);

void CSVtoVector(std::string fileName, std::vector<Region>& regions);
void CSVtoVector(std::string fileName, std::vector<PriceRecord>& priceRecords);

int binaryFind(int id, std::vector<Region>& regions);

void slideToPosition(std::vector<Region>& regions, size_t index);
void sortRegionsByID(std::vector<Region> &regions);

void sortByName(std::vector<Region>& vec);
std::vector<Region> merge(const std::vector<Region>& vec1, const std::vector<Region>& vec2);
std::vector<Region> slice(const std::vector<Region>& vec, size_t startLoc, size_t endLoc);
#endif