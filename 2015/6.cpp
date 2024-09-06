#include <fstream>
#include <iostream>

using namespace std;

void getGridTotal(string fileName) {
  ifstream file(fileName);
  string line;

  int grid[1000][1000];

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      grid[i][j] = 0;
    }
  }

  while (getline(file, line)) {
    string instruction = "";
    if (line.find("turn on") != string::npos) {
      instruction = "turn on";
    } else if (line.find("turn off") != string::npos) {
      instruction = "turn off";
    } else if (line.find("toggle") != string::npos) {
      instruction = "toggle";
    }

    line = line.substr(instruction.length(), string::npos);
    const int delimeter = line.find("through");
    const string line1 = line.substr(0, delimeter);
    const string line2 = line.substr(delimeter + 8, string::npos);
    const int comma1 = line1.find(',');
    const int comma2 = line2.find(',');

    const int aX = stoi(line1.substr(0, comma1));
    const int aY = stoi(line1.substr(comma1 + 1, string::npos));

    const int bX = stoi(line2.substr(0, comma2));
    const int bY = stoi(line2.substr(comma2 + 1, string::npos));

    // cout << instruction;
    // cout << "( " << aX << " : " << aY << " )";
    // cout << "( " << bX << " : " << bY << " )" << endl;

    // cout << "test";

    // cout << grid[aX][aY] << endl;

    for (int i = aX; i < bX + 1; i++) {
      for (int j = aY; j < bY + 1; j++) {
        if (instruction == "turn on") {
          grid[i][j]++;
        }
        if (instruction == "turn off") {
          if (grid[i][j] > 0) {
            grid[i][j]--;
          }
        }
        if (instruction == "toggle") {
          grid[i][j] += 2;
        }
      }
    }
  }

  int count = 0;

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      if (grid[i][j]) {
        count += grid[i][j];
      };
    }
  }

  cout << count << endl;
}

int main() {
  getGridTotal("./2015/6.dat");
  // bool testBool = true;
  // testBool = !testBool;
  // cout << "test bool: " << testBool << endl;
}
