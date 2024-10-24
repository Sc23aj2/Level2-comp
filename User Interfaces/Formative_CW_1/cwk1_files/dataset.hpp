// COMP2811 Coursework 1: QuakeDataset class

#pragma once

#include <vector>
#include "quake.hpp"

class QuakeDataset
{
  public:
    QuakeDataset() {}
    QuakeDataset(const std::string& file) { loadData(file) ;}
    void loadData(const std::string&);
    int size() const { return sizeof(data); }
    Quake operator [] (int index) { return data.at(index); }
    Quake strongest() const;
    Quake shallowest() const;
    double meanDepth() const;
    double meanMagnitude() const;

  private:
    std::vector<Quake> data;
};
