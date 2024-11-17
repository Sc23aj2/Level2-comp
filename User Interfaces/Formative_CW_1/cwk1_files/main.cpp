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
  Table strongest_quake;
  Table shallowest_quake;

  quakedataset.loadData(file);

  cout << "The number of quakes in the file: " << quakedataset.size() << endl;

  strongest_quake.add_row({"Time", "Latitude", "Longitude", "Depth", "Magnitude"});
  strongest_quake.add_row({quakedataset.strongest().getTime(), to_string(quakedataset.strongest().getLatitude()), to_string(quakedataset.strongest().getLongitude()), to_string(quakedataset.strongest().getDepth()), to_string(quakedataset.strongest().getMagnitude())});
  cout << "\nThe strongest quake is:\n" << strongest_quake << endl;

  shallowest_quake.add_row({"Time", "Latitude", "Longitude", "Depth", "Magnitude"});
  shallowest_quake.add_row({quakedataset.shallowest().getTime(), to_string(quakedataset.shallowest().getLatitude()), to_string(quakedataset.shallowest().getLongitude()), to_string(quakedataset.shallowest().getDepth()), to_string(quakedataset.shallowest().getMagnitude())});
  cout << "\nThe shallowest quake:\n" << shallowest_quake << endl;

  cout << "\nThe mean depth of quakes: " << quakedataset.meanDepth() << endl;
  cout << "The mean magnitude of quakes: " << quakedataset.meanMagnitude() << endl;


  
  return 0;
}
