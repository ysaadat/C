#include <iostream>
#include <fstream>
#include "station.h"
#include "train.h"
#include "schedule.h"

using namespace std;

int main(int argc, char *argv[]) {

    TrainList trains = TrainList("trains.dat");
    StationList stations = StationList("stations.dat");
    Schedule schedule = Schedule("schedule.dat");

    for(int a = 0; a < trains.length(); a++){
        for(int b = 0; b < trains.length(); b++){
            for(int c = 0; c < stations.length(); c++){
                int departureA = schedule.lookup(trains.trainAt(a).getId(), stations.stationAt(c).getId(), 1);
                if(departureA == -1)    continue;
                int departureB = schedule.lookup(trains.trainAt(b).getId(), stations.stationAt(c).getId(), 1);
                if(departureB == -1)    continue;

                if(departureA < departureB){
                    for(int d = 0; d < trains.length(); d++){
                        int arrivalA = schedule.lookup(trains.trainAt(a).getId(), stations.stationAt(d).getId(), 0);
                        if(arrivalA == -1)    continue;
                        int arrivalB = schedule.lookup(trains.trainAt(b).getId(), stations.stationAt(d).getId(), 0);
                        if(arrivalB == -1)    continue;

                        if(arrivalA > departureA && arrivalB > departureB && arrivalA > arrivalB){
                            cout << "FOUND" << endl;
                            break;
                        }
                    }
                }
            }
        }
    }
}