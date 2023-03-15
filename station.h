#ifndef MYP_STATION_H
#define MYP_STATION_H

#include <string>
#include <vector>

using namespace std;

class Station {
public:
    Station(string s);
    Station(int sId);

    string getName();
    bool operator< (const Station &s) const;
    int getId(){ return id; }

private:
    int id;
    string name;
};

class StationList {
public:
    StationList(char const *filename);
    Station stationAt(int index) { return stations[index]; }
    int length() { return stations.size(); }

private:
    vector<Station> stations;
};

#endif //MYP_STATION_H
