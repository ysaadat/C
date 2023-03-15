#include "schedule.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "schedule.h"

using namespace std;

Entry::Entry(string s) {
    stringstream ss(s);
    int arrHour, arrMin, depHour, depMin;
    ss >> trainId >> stationId >> arrHour >> arrMin >> depHour >> depMin;
    /* Then it is not the first, but the last train */
    if(depHour == 0 && depMin == 0)
        depHour = 24;

    arrival = arrHour*60+arrMin;
    departure = depHour*60+depMin;
}

Entry::Entry(int tId, int statId, int param) {
    trainId = tId;
    stationId = statId;
    parameter = param;
}

Schedule::Schedule(char const *filename){
    ifstream input(filename);
    string line;

    while(getline(input,line)){
        allEntries.push_back(Entry(line));
    }
    sort(allEntries.begin(), allEntries.end());
}

int Schedule::lookup(int trainId, int stationId, int param) {
    Entry item(trainId, stationId, param);
    vector<Entry>::iterator it = find(allEntries.begin(), allEntries.end(), item);
    if (it != allEntries.end()){
        Entry e = *it;
        return (param == 0) ? e.getArrival() : e.getDeparture();
    }
    else
        return -1;
}

bool Entry::operator< (const Entry &e) const  {
    return (trainId == e.trainId && arrival < e.arrival) || trainId < e.trainId;
}

bool Entry::operator== (const Entry &e) const  {
    return (trainId == e.trainId && stationId == e.stationId);
}