/**
* @brief Assignment 8 Algorithms
* @name Adam Jennings
*/

#include <iostream>
#include <fstream>
#include <vector>

#include "helpers.h"

using namespace std;


int main(){
    ///////////////////////////////////////////
    // Part 1 (Populate Regions Vector From File)
    printPartHeader("Part 1");
    vector<Region> regions;

    CSVtoVector("ZILLOW_REGIONS.csv", regions);

    // Print out the first five Regions (id, city, and state) in your vector.
    for (vector<Region>::size_type i = 0; i < 5; i++){
        cout << regions.at(i).toString() << endl;
    }

    ///////////////////////////////////////////
    // Part 2 (Quadratic Sort)
    printPartHeader("Part 2");

    clock_t start = clock();    
    sortRegionsByID(regions);
    clock_t end = clock();
    
    // print time it took to sort
    cout << "Took " << 1.0 * (end - start) / CLOCKS_PER_SEC << " seconds." << endl;
    
    // Print out the first five Regions (id, city, and state) in your vector.
    for (vector<Region>::size_type i = 0; i < 5; i++){
        cout << regions.at(i).toString() << endl;
    }

    ///////////////////////////////////////////
    // Part 3  (Sort By Name)
    printPartHeader("Part 3");
    vector<Region> regionsByName;
    regionsByName = regions;

    start = clock();    
    sortByName(regionsByName);
    end = clock();
    
    // print time it took to sort
    cout << "Took " << 1.0 * (end - start) / CLOCKS_PER_SEC << " seconds." << endl;

    // Print out the first five Regions (id, city, and state) in your vector.
    for (vector<Region>::size_type i = 0; i < 5; i++){
        cout << regions.at(i).toString() << endl;
    }

    ///////////////////////////////////////////
    // Part 4 (Populate Price Records Vector From File)
    printPartHeader("Part 4");

    vector<PriceRecord> prices;
    CSVtoVector("ZILLOW_DATA.csv", prices);

    // Print out the first five Regions (id, city, and state) in your vector.
    for (vector<PriceRecord>::size_type i = 0; i < 5; i++){
        cout << prices.at(i).toString() << endl;
    }

    ///////////////////////////////////////////
    // Part 5 (Binary Find)
    printPartHeader("Part 5");

    size_t position = (size_t)binaryFind(20317, regions);

    cout << regions.at(position).toString() << endl;
    
    ///////////////////////////////////////////
    // Part 6 (User Input / Search)
    printPartHeader("Part 6");
    
    cout << "Enter a city : ";
    string input;
    getline(cin, input);
    
    for (size_t i = 0; i < prices.size(); i++){
        size_t cityPosition = (size_t)binaryFind(prices.at(i).ID, regions);
        if (regions.at(cityPosition).cityName == input){
            cout << regions.at(cityPosition).cityName << " ";
            cout << regions.at(cityPosition).state << " ";
            cout << prices.at(i).date << " ";
            cout << to_string(prices.at(i).value) << endl;
        }
    }
    
    return 0;
}