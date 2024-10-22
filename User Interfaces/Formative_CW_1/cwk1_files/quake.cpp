// COMP2811 Coursework 1: Quake class

#include <stdexcept>
#include "quake.hpp"

using namespace std;


Quake::Quake(const string& tm, double lat, double lon, double dep, double mag):
  time(tm), latitude(lat), longitude(lon), depth(dep), magnitude(mag)
{
  if (depth < 0)
  {
    throw invalid_argument("Depth cannot be negative.");
  }

  if (magnitude < 0)
  {
    throw invalid_argument("Magnitude cannot be negative.");
  }

  if (latitude < -90 || latitude > 90)
  {
    throw invalid_argument("Invalid Latitude.");
  }

  if (longitude < -180 || longitude > 180)
  {
    throw invalid_argument("Invalid Latitude.");
  }

}


ostream& operator<<(ostream& out, const Quake& quake)
{
  return out << "Time: " << quake.getTime()
             << "\nLatitude: " << quake.getLatitude() << " deg"
             << "\nLongitude: " << quake.getLongitude() << " deg"
             << "\nDepth: " << quake.getDepth() << " km"
             << "\nMagnitude: " << quake.getMagnitude() << endl;
}
