#include "station.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "station.h"

using namespace std;

Station::Station(string s) {
    stringstream ss(s);
    ss >> id >> name;
}

Station::Station(int sId) {
    id = sId;
}

StationList::StationList(char const *filename){
    ifstream input(filename);
    string line;

    while(getline(input,line))
        stations.push_back(Station(line));

    sort(stations.begin(), stations.end());
}

string Station::getName() {
    return name;
}

bool Station::operator< (const Station &s) const  {
    return id < s.id;
}