// COMP2811 Coursework 1: QuakeDataset class
#include <stdexcept>
#include "csv.hpp"
#include "dataset.hpp"

using namespace std;

void QuakeDataset::loadData(const string& file)
{
    csv::CSVReader reader(file);
    
    data.clear();
    for (auto& row: reader) 
    {
        string time = row["time"].get<>();
        double latitude = row["latitude"].get<double>();
        double longitude = row["longitude"].get<double>();
        double depth = row["depth"].get<double>();
        double magnitude = row["mag"].get<double>();

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
    int i;
    if (data.size() == 0)
    {
        throw out_of_range("Cannot find shallowest for empty dataset.");
    }
    
    Quake shallowest = data[0];

    for (i = 0; i < data.size(); i ++)
    {
        if(data[i].getDepth() < shallowest.getDepth())
        {
            shallowest = data[i];
        }
    }

    return shallowest;
}

double QuakeDataset::meanDepth() const
{
    int i;
    if (data.size() == 0)
    {
        throw out_of_range("Cannot find mean depth for empty dataset.");
    }
    
    double sum = 0;

    for (i = 0; i < data.size(); i ++)
    {
        sum += data[i].getDepth();
    }

    double mean_depth = sum / data.size();
    return mean_depth;
}

double QuakeDataset::meanMagnitude() const
{
    int i;
    if (data.size() == 0)
    {
        throw out_of_range("Cannot find mean magnitude for empty dataset.");
    }
    
    double sum = 0;

    for (i = 0; i < data.size(); i ++)
    {
        sum += data[i].getMagnitude();
    }

    double mean_magnitude = sum / data.size();
    return mean_magnitude;
}

