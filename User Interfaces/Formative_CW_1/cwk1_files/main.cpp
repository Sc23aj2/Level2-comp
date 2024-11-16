// COMP2811 Coursework 1: quaketool application

#include <iostream>
#include <fstream>
#include "dataset.hpp"
#include "argparse.hpp"

using namespace std;

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

  quakedataset.loadData(file);

  
  return 0;
}
