#ifndef MYP_TRAIN_H
#define MYP_TRAIN_H

#include <string>
#include <vector>

using namespace std;

class Train{
public:
    Train(string s);
    Train(int tId);

    bool operator< (const Train &t) const;
    int getId() { return id; }

private:
    int id;
    int numberOfWaggons;
};

class TrainList{
public:
    TrainList(char const *filename);
    Train trainAt(int index) { return trains[index]; }
    int length() { return trains.size(); }

private:
    vector<Train> trains;
};

#endif //MYP_TRAIN_H
