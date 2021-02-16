#include <bits/stdc++.h>
using namespace std;
int main() {
  int deg, dis;
  cin >> deg >> dis;
  dis = (dis + 3) / 6;
  if (dis <= 2) {
    cout << "C";
  } else if (112.5 <= deg && deg <= 337.5) {
    cout << "NNE";
  } else if (337.5 <= deg && deg <= 562.5) {
    cout << "NE";
  } else if (562.5 <= deg && deg <= 787.5) {
    cout << "ENE";
  } else if (787.5 <= deg && deg <= 1012.5) {
    cout << "E";
  } else if (1012.5 <= deg && deg <= 1237.5) {
    cout << "ESE";
  } else if (1237.5 <= deg && deg <= 1462.5) {
    cout << "SE";
  } else if (1462.5 <= deg && deg <= 1687.5) {
    cout << "SSE";
  } else if (1687.5 <= deg && deg <= 1912.5) {
    cout << "S";
  } else if (1912.5 <= deg && deg <= 2137.5) {
    cout << "SSW";
  } else if (2137.5 <= deg && deg <= 2362.5) {
    cout << "SW";
  } else if (2362.5 <= deg && deg <= 2587.5) {
    cout << "WSW";
  } else if (2587.5 <= deg && deg <= 2812.5) {
    cout << "W";
  } else if (2812.5 <= deg && deg <= 3037.5) {
    cout << "WNW";
  } else if (3037.5 <= deg && deg <= 3262.5) {
    cout << "NW";
  } else if (3262.5 <= deg && deg <= 3487.5) {
    cout << "NNW";
  } else {
    cout << "N";
  }
  cout << " ";
  if (dis <= 2) {
    cout << 0;
  } else if (dis <= 15) {
    cout << 1;
  } else if (dis <= 33) {
    cout << 2;
  } else if (dis <= 54) {
    cout << 3;
  } else if (dis <= 79) {
    cout << 4;
  } else if (dis <= 107) {
    cout << 5;
  } else if (dis <= 138) {
    cout << 6;
  } else if (dis <= 171) {
    cout << 7;
  } else if (dis <= 207) {
    cout << 8;
  } else if (dis <= 244) {
    cout << 9;
  } else if (dis <= 284) {
    cout << 10;
  } else if (dis <= 326) {
    cout << 11;
  } else {
    cout << 12;
  }
  cout << "\n";
  return 0;
}
