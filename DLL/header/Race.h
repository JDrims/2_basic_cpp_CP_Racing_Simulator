#pragma once
#include "Vehicle.h"
#include <vector>
#include <memory>
#include <string>

class DLL_API Race {
protected:
    std::vector<std::unique_ptr<Vehicle>> participants;
    double distance;
    bool isFinished;
    std::vector<std::pair<std::string, double>> results;

public:
    explicit Race(double dist);
    virtual ~Race() = default;

    Race(const Race&) = delete;
    Race& operator=(const Race&) = delete;

    virtual bool addVehicle(Vehicle* vehicle) = 0;
    bool removeVehicle(int numVehicle);
    int getParticipantCount() const;
    std::vector<std::string> getParticipantNames() const;

    void start();
    std::vector<std::pair<std::string, double>> getResults() const;

protected:
    virtual bool isVehicleAllowed(const Vehicle* vehicle) const = 0;
    void sortResults();
};