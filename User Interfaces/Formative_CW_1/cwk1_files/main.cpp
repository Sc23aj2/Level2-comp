// COMP2811 Coursework 1: quaketool application

#include <iostream>
#include "dataset.hpp"
#include "argparse.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    fprintf(2, "Usage: ./main <file_name>");
  }

  argparse::ArgumentParser program("main");

  program.add_argument("filename")
    .help("name of CSV file containing quake data")
    .metavar("CSV_FILE");

  return 0;
}
