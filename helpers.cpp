/**
* @brief Assignment 8 Algorithms
* @name Adam Jennings
*/

#include "helpers.h"
#include <fstream>

using namespace std;

string Region::toString(){
    return to_string(ID) + " " + cityName + " " + state;
}

string PriceRecord::toString(){
    return to_string(ID) + " " + date + " " + to_string(value);
}

void printPartHeader(string title){
    cout << endl;
    cout << "----------------" << title << "----------------" << endl;
    cout << endl;
}

void CSVtoVector(std::string fileName, vector<Region>& regions){
    fstream inFile;
    inFile.open(fileName);

    if (inFile.is_open()){
        string line;
        while ( getline (inFile,line) ){
            Region region;
            size_t start = 0;
            size_t end = line.find(',', start);
            region.ID = stoi(line.substr(start, end));
            
            start = end+1;
            end = line.find(',', start);
            region.cityName = line.substr(start, end - start);

            start = end+1;
            end = line.size() - start;
            region.state = line.substr(start, end);
            regions.push_back(region);
        }
        inFile.close();
    } 
}

void CSVtoVector(std::string fileName, vector<PriceRecord>& priceRecords){
    fstream inFile;
    inFile.open(fileName);

    if (inFile.is_open()){
        string line;
        while ( getline (inFile,line) ){
            PriceRecord priceRecord;
            size_t start = 0;
            size_t end = line.find(',', start);
            priceRecord.ID = stoi(line.substr(start, end));
            
            start = end+1;
            end = line.find(',', start);
            priceRecord.date = line.substr(start, end - start);

            start = end+1;
            end = line.size() - start;
            priceRecord.value = stod(line.substr(start, end));
            priceRecords.push_back(priceRecord);
        }
        inFile.close();
    } 
}

int binaryFind(int searchID, std::vector<Region>& regions){
    int high = regions.size() - 1;
    int low = 0;
    int index;

    while(high >= low) {
        index = (low + high) / 2;
        Region current = regions.at((size_t)index);

        if(current.ID == searchID)
            return index;

        if(current.ID > searchID) {
            high = index - 1;
        } 
        else {
            low = index + 1;
        }
    }
    return -1;
}

void slideToPosition(vector<Region>& regions, size_t index) {
    for(vector<Region>::size_type i = index; i > 0; i--) {
        if(regions.at(i - 1).ID > regions.at(i).ID) {
            Region temp = regions.at(i);
            regions[i] = regions[i - 1];
            regions[i - 1] = temp;
        } 
        else
            return;
    }
}


void sortRegionsByID( vector<Region> &regions ){
    for(vector<Region>::size_type i = 0; i < regions.size(); i++) {
        slideToPosition(regions, i);
    }
}

void sortByName(vector<Region>& vec) {

  if(vec.size() <= 1)
    return;

  vector<Region> A = slice(vec, 0, vec.size() / 2);
  sortByName(A);
  vector<Region> B = slice(vec, vec.size() / 2, vec.size());
  sortByName(B);

  vec = merge(A, B);
}

vector<Region> merge(const vector<Region>& vec1, const vector<Region>& vec2) {
    vector<Region> newVec;

    size_t i1 = 0, i2 = 0;
    for(size_t i = 0; i < vec1.size() + vec2.size(); i++) {
        if(i1 >= vec1.size()) {
            newVec.push_back(vec2.at(i2));
            i2++;
        } 
        else if(i2 >= vec2.size()) {
            newVec.push_back(vec1.at(i1));
            i1++;
        } 
        else if(vec1.at(i1).cityName < vec2.at(i2).cityName) {
            newVec.push_back(vec1.at(i1));
            i1++;
        } 
        else {
            newVec.push_back(vec2.at(i2));
            i2++;
        }
    }
  return newVec;
}

vector<Region> slice(const vector<Region>& vec, size_t startLoc, size_t endLoc) {
  vector<Region> newVec;
  for(size_t i = startLoc; i < endLoc; i++) {
    newVec.push_back(vec.at(i));
  }
  return newVec;
}