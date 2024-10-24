// COMP2811 Coursework 1: QuakeDataset class
#include <stdexcept>
#include "csv.hpp"
#include "dataset.hpp"

using namespace std;

void QuakeDataset::loadData(const string& file)
{
    csv::CSVReader reader("data/test0.csv");
    for (auto& row: reader) 
    {
        string time = row["A"].get<>();
        double latitude = row["B"].get<double>();
        double longitude = row["C"].get<double>();
        double depth = row["C"].get<double>();
        double magnitude = row["C"].get<double>();

        data.push_back(Quake(time, latitude, longitude, depth, magnitude));
    }
}

Quake QuakeDataset::strongest() const
{
    int i;
    if (data.size() == 0)
    {
        throw out_of_range("Cannot find strongest for empty dataset.");
    }
    
    Quake strongest = data[0];

    for (i = 0; i < data.size(); i ++)
    {
        if(data[i].getMagnitude() > strongest.getMagnitude())
        {
            strongest = data[i];
        }
    }

    return strongest;
}

Quake QuakeDataset::shallowest() const
{
    return Quake("aaa", 0, 0, 0, 0);
}

double QuakeDataset::meanDepth() const
{
    return 0;
}

double QuakeDataset::meanMagnitude() const
{
    return 0;
}

