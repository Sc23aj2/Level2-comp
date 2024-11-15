// COMP2811 Coursework 1: quaketool application

#include <iostream>
#include "dataset.hpp"
#include "argparse.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  argparse::ArgumentParser program("quaketool");

  program.add_argument("filename")
    .help("name of CSV file containing quake data")
    .metavar("CSV_FILE");
  program.parse_args(argc, argv);
  return 0;
}
