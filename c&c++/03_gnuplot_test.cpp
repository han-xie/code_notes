/* Acknowledgement: https://github.com/dstahlke/gnuplot-iostream
 * Based on example-misc.cc
 *
 * apt install libgnuplot-iostream-dev
 *
 * g++ -o 03_gnuplot_test 03_gnuplot_test.cpp -lutil -lboost_iostreams -lboost_system -lboost_filesystem
 */
#include <iostream>
#include "gnuplot-iostream.h"

int main() {
  Gnuplot gp;
  std::vector< std::pair<double, double> > y_pts;
  for (double x=-2; x<2; x+=0.01) {
    double y = x*x*x;
    y_pts.push_back(std::make_pair(x, y));
  }

  gp << "set terminal png\n";
  gp << "set output 'my_graph_1.png'\n";
  gp << "plot '-' with lines\n";
  gp.send1d(y_pts);
  return 0;
}
