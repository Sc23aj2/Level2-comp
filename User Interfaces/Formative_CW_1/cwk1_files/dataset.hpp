// COMP2811 Coursework 1: QuakeDataset class

#pragma once

#include <vector>
#include "quake.hpp"

class QuakeDataset
{
  public:
    QuakeDataset() {}
    QuakeDataset(const std:: string& file) { loadData(file) ;}
    void loadData(std:: string&);
    int size() const { return sizeof(data); }
    std::vector<Quake> operator [] (int index) { return data.at(index); }
    std::vector<Quake> strongest();
    std::vector<Quake> shallowest();
    double meanDepth();
    double meanMagnitude();

  private:
    std::vector<Quake> data;
};
