#include "Race.h"
#include <algorithm>
#include <iostream>

Race::Race(double dist) : distance(dist), isFinished(false) {}

bool Race::removeVehicle(int numVehicle) {
    if (numVehicle < 0 || numVehicle >= static_cast<int>(participants.size())) {
        return false;
    }
    participants.erase(participants.begin() + numVehicle);
    return true;
}

int Race::getParticipantCount() const {
    return static_cast<int>(participants.size());
}

std::vector<std::string> Race::getParticipantNames() const {
    std::vector<std::string> names;
    for (const auto& v : participants) {
        names.push_back(v->getName());
    }
    return names;
}

void Race::start() {
    results.clear();
    for (const auto& v : participants) {
        double time = v->calculateTime(distance);
        results.push_back({ v->getName(), time });
    }
    sortResults();
    isFinished = true;
}

std::vector<std::pair<std::string, double>> Race::getResults() const {
    return results;
}

void Race::sortResults() {
    std::sort(results.begin(), results.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
}