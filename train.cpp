#include "train.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "train.h"

using namespace std;

Train::Train(string s) {
    stringstream ss(s);
    ss >> id >> numberOfWaggons;
}

Train::Train(int tId) {
    id = tId;
}

TrainList::TrainList(char const *filename){
    ifstream input(filename);
    string line;

    while(getline(input,line))
        trains.push_back(Train(line));

    sort(trains.begin(), trains.end());
}

bool Train::operator< (const Train &t) const {
    return id < t.id;
}