#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> program;
unordered_map<string, string> programData;



bool isNumber(string val) {
  for (size_t i = 0; i < val.length(); i++) {
    if (!isdigit(val[i])) {
      return false;
    }
  }
  return true;
}

void popProgram(string fileName) {
  ifstream file(fileName);
  string line;

  while (getline(file, line)) {
    const int delimeter = line.find('>');
    const string wire = line.substr(delimeter + 1, string::npos);
    const string signal = line.substr(0, delimeter - 2);

    if (signal.find("AND") != string::npos) {
      const int index = signal.find("AND");

      const string argA = signal.substr(0, index);
      const string argB = signal.substr(index + 4, string::npos);
    }

    if (signal.find("OR") != string::npos) {
    }

    if (signal.find("LSHIFT") != string::npos) {
    }

    if (signal.find("RSHIFT") != string::npos) {
    }

    if (signal.find("NOT") != string::npos) {
    }

    if (isNumber(signal)) {
      programData[wire] = signal;
    }

    program[wire] = signal;
  }
}

int main() {
  popProgram("./2015/7.dat");

  for (const auto& element : programData) {
    cout << element.first << ": " << element.second << endl;
  }

  for (const auto& element : program) {
    cout << element.first << ": " << element.second << endl;
  }
}
