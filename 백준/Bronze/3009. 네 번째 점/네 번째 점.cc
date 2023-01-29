#include <iostream>
using namespace std;

int main() {
  int aa[3];
  int bb[3];
  int ta, tb;
  for (int i = 0; i < 3; i++) {
    cin >> aa[i] >> bb[i];
  }
  if (aa[0] == aa[1])
    ta = aa[2];
  else if (aa[0] == aa[2])
    ta = aa[1];
  else
    ta = aa[0];

  if (bb[0] == bb[1])
    tb = bb[2];
  else if (bb[0] == bb[2])
    tb = bb[1];
  else
    tb = bb[0];

  cout << ta << " " << tb;

  return 0;
}