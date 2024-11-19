// COMP2811 Coursework 1: quaketool application

#include <iostream>
#include "dataset.hpp"
#include "argparse.hpp"
#include "tabulate.hpp"

using namespace std;
using namespace tabulate;

int main(int argc, char* argv[])
{
  argparse::ArgumentParser program("quaketool");

  program.add_argument("filename")
    .help("name of CSV file containing quake data")
    .metavar("CSV_FILE");

  program.add_argument("-t", "--table")
  .help("view quakes in a table format")
  .default_value(false)
  .implicit_value(true);

  program.add_argument("-m")
  .help("displays quakes with a magnitude equal to or greater than the specified threshold.\nTo be used in table mode.")
  .scan<'i', int>();
    
  try 
  {
    program.parse_args(argc, argv);
  }
  catch (const std::exception& err)
  {
    cerr << err.what() << endl;
    cerr << program;
    return 1;
  }

  auto file = program.get("filename");
  
  QuakeDataset quakedataset;
  Table all_quakes;
  Table strongest_quake;
  Table shallowest_quake;

  quakedataset.loadData(file);

  if (program["-t"] == true|| program["--table"] == true)
  {
    all_quakes.add_row({"Time", "Latitude", "Longitude", "Depth", "Magnitude"});
    for (int i = 0; i < quakedataset.size(); i++)
    {
      try 
      {
        int magnitude = program.get<int>("-m");
        if (quakedataset[i].getMagnitude() >= magnitude)
        {
          all_quakes.add_row({quakedataset[i].getTime(), to_string(quakedataset[i].getLatitude()), to_string(quakedataset[i].getLongitude()), to_string(quakedataset[i].getDepth()), to_string(quakedataset[i].getMagnitude())});
        }      
      }
      catch (const std::exception& logic_error)
      {
        all_quakes.add_row({quakedataset[i].getTime(), to_string(quakedataset[i].getLatitude()), to_string(quakedataset[i].getLongitude()), to_string(quakedataset[i].getDepth()), to_string(quakedataset[i].getMagnitude())});
      }
    }
    cout << all_quakes << endl;
  }
  else
  {
    cout << "The number of quakes in the file: " << quakedataset.size() << endl;

    strongest_quake.add_row({"Time", "Latitude", "Longitude", "Depth", "Magnitude"});
    strongest_quake.add_row({quakedataset.strongest().getTime(), to_string(quakedataset.strongest().getLatitude()), to_string(quakedataset.strongest().getLongitude()), to_string(quakedataset.strongest().getDepth()), to_string(quakedataset.strongest().getMagnitude())});
    cout << "\nThe strongest quake is:\n" << strongest_quake << endl;

    shallowest_quake.add_row({"Time", "Latitude", "Longitude", "Depth", "Magnitude"});
    shallowest_quake.add_row({quakedataset.shallowest().getTime(), to_string(quakedataset.shallowest().getLatitude()), to_string(quakedataset.shallowest().getLongitude()), to_string(quakedataset.shallowest().getDepth()), to_string(quakedataset.shallowest().getMagnitude())});
    cout << "\nThe shallowest quake:\n" << shallowest_quake << endl;

    cout << "\nThe mean depth of quakes: " << quakedataset.meanDepth() << endl;
    cout << "The mean magnitude of quakes: " << quakedataset.meanMagnitude() << endl;
  } 

  return 0;
}
