#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void read_data(istream& input, vector<float>& data)
{
    float value;
    while (input >> value)
    {
        data.push_back(value);
    }

}

float mean_value(vector<float>& data)
{
    int i;
    float sum = 0;
    float mean;

    for (i=0; i < data.size(); i++)
    {
    sum += data[i];
    }
    mean = sum/data.size();
    return mean;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: ./mean <filname>" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    if (not infile)
    {
        cerr << "Error: cannot access " << argv[1] << endl;
        return 2;
    }

    vector<float> data;

    read_data(infile, data);

    cout << data.size() << " values read from the file." << endl;
    cout << "mean value = " << mean_value(data) << endl;

    return 0;
}