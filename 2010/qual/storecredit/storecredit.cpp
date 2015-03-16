#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int* getPrices(int length, ifstream& ifs) {
  ostringstream oss;
  int *array = new int[length];
  int i = 0;
  char c;
  ifs.get(c);
  while (c != '\n') {
    if (c == ' ') {
      array[i] = stoi(oss.str(), nullptr);
      i++;
      oss.clear();
      oss.str("");
      ifs.get(c);
      continue;
    }
    oss << c;
    ifs.get(c);
  }
  array[i] = stoi(oss.str(), nullptr);
  return array;
}

void calculate(int credit, int length, int* array, int& a, int& b) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (i != j) {
        if ((array[i] + array[j]) == credit) {
          a = i;
          b = j;
          return;
        }
      }
    }
  }
}

int main() {
  ifstream ifs("A-large-practice.in");
  ofstream ofs("A-large-solution");
  char* buffer = new char[10];
  ifs.getline(buffer, 10);
  int testCases = atoi(buffer);
  for (int test = 0; test < testCases; test++) {
    ifs.getline(buffer, 10);
    int credit = atoi(buffer);
    ifs.getline(buffer, 10);
    int numItems = atoi(buffer);
    int* prices = getPrices(numItems, ifs);
    int x,y;
    calculate(credit, numItems, prices, x, y);
    ofs << "Case #" << test+1 << ": " << x+1 << ' ' << y+1 << '\n';
  }
  ofs.close();
  ifs.close();
  return 0;
}
