#include <iostream>
#include <fstream>
#include <vector>

#include <cstdlib>

#include "dubin/include/dubin.h"

int main(int argc, char** argv) {
  std::vector<gl2d::Circle> neighborhoods;

  int N = atoi(argv[1]);
  int K = atoi(argv[2]);
  int Q = atoi(argv[3]);
  int A = atoi(argv[4]);
  double R = atof(argv[5]);
  std::istream* input = new std::ifstream(argv[6]);

  for (int i = 0;i < N;i++) {
    double x, y, r;
    int id;
    *input >> id >> x >> y >> r;
    neighborhoods.emplace_back(gl2d::Circle(x, y, r));
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int u = 0; u < Q; ++u) {
        for (int v = 0; v < Q; ++v) {
          for (int a = 0; a < A; ++a) {
            for (int b = 0; b < A; ++b) {
              gl2d::Vector w1 = gl2d::Vector::i;
              gl2d::Vector w2 = gl2d::Vector::i;

              w1.Rotate(gl2d::Radians::TWOPI * ((double) u / Q));
              w1 *= neighborhoods[i].Radius();
              w1 += gl2d::Vector(neighborhoods[i].Center());

              w2.Rotate(gl2d::Radians::TWOPI * ((double) v / Q));
              w2 *= neighborhoods[j].Radius();
              w2 += gl2d::Vector(neighborhoods[j].Center());

              gl2d::Vector v1 = gl2d::Vector::i;
              gl2d::Vector v2 = gl2d::Vector::i;

              v1.Rotate(gl2d::Radians::TWOPI * ((double) a / A));
              v2.Rotate(gl2d::Radians::TWOPI * ((double) b / A));

              auto path = dubin::Path::ShortestPath(w1.Point(), v1, w2.Point(), v2, R);

              if (path)
                std::cout << path->Length() << std::endl;
              else
                std::cout << 0 << std::endl;
            }
          }
        }
      }
    }
  }

  return 0;
}
