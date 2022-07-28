#include <iostream>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  switch(x) 
  {
    case 12:
      y += 30;
    case 11:
      y += 31;
    case 10:
      y += 30;
    case 9:
      y += 31;
    case 8:
      y += 31;
    case 7:
      y += 30;
    case 6:
      y += 31;
    case 5:
      y += 30;
    case 4:
      y += 31;
    case 3:
      y += 28;
    case 2:
      y += 31;
  }


  int result = y % 7;
  switch(result) 
  {
    case 1:
      cout << "MON";
      break;
    case 2:
      cout << "TUE";
      break;
    case 3:
      cout << "WED";
      break;
    case 4:
      cout << "THU";
      break;
    case 5:
      cout << "FRI";
      break;
    case 6:
      cout << "SAT";
      break;
    case 0:
      cout << "SUN";
      break;
  }

  return 0;
}