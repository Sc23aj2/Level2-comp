// COMP2811 Coursework 1: QuakeDataset class

#pragma once

#include <vector>
#include "quake.hpp"

class QuakeDataset
{
  public:
    QuakeDataset() {}
    QuakeDataset(const std:: string&) const { loadData(std:: string&); };
    void loadData(std:: string&); 
    int size();
    std::vector<Quake> operator [] (int index) { data.at(index); }
    std::vector<Quake> strongest();
    std::vector<Quake> shawllowest();
    double meanDepth();
    double meanMagnitude();

  private:
    std::vector<Quake> data;
};
