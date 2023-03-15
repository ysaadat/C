#ifndef MYP_SCHEDULE_H
#define MYP_SCHEDULE_H

#include <string>
#include <vector>

using namespace std;

class Entry{
public:
    Entry(string s);
    Entry(int tId, int time, int param);     //time=dep or arr, param 0 for time=arr

    bool operator< (const Entry &e) const;
    bool operator== (const Entry &e) const;

    int getTrainId(){ return trainId; }
    int getArrival(){ return arrival; }
    int getDeparture(){ return departure; }

private:
    int trainId, stationId, arrival, departure, parameter;
};

class Schedule{
public:
    Schedule(char const *filename);
    int lookup(int trainId, int stationId, int param);
    int length() { return allEntries.size(); }
    Entry entryAt(int index) { return allEntries[index]; }

private:
    vector<Entry> allEntries;
};

#endif //MYP_SCHEDULE_H
