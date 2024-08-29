#include <fstream>
#include <iostream>
#include <string>

using String = std::string;

void display(const int &output, bool returnFlag = 1) {
  if (returnFlag) {
    std::cout << output << std::endl;
    return;
  }
  std::cout << output;
}

void display(const String &output, bool returnFlag = 1) {
  if (returnFlag) {
    std::cout << output << std::endl;
    return;
  }
  std::cout << output;
}

String getDataFromFile(String fileName) {
  std::ifstream file(fileName);
  String line, data = "";
  while (std::getline(file, line)) {
    data += line;
  }
  return data;
}

int main() {
  const String data = getDataFromFile("3.dat");

  String locationHistory[data.length()];
  locationHistory[0] = "0/0/0/0";

  int uniqueCount = 0;

  for (size_t i = 0; i < data.length() - 1; i++) {
    String location = locationHistory[i];

    String northToken = location.substr(0, location.find('/'));
    location.erase(0, northToken.length() + 1);
    String southToken = location.substr(0, location.find('/'));
    location.erase(0, southToken.length() + 1);
    String eastToken = location.substr(0, location.find('/'));
    location.erase(0, eastToken.length() + 1);
    String westToken = location.substr(0, location.find('/'));

    switch (data[i]) {
      case '^':
        northToken = std::to_string(stoi(northToken) + 1);
        break;
      case 'v':
        southToken = std::to_string(stoi(southToken) + 1);
        break;
      case '<':
        westToken = std::to_string(stoi(westToken) + 1);
        break;
      case '>':
        eastToken = std::to_string(stoi(eastToken) + 1);
        break;
      default:
        return 1;
    }

    const String nextLocation =
        northToken + '/' + southToken + '/' + eastToken + '/' + westToken;

    uniqueCount++;

    for (size_t j = 0; j < data.length(); j++) {
      if (locationHistory[j] == nextLocation) {
        uniqueCount--;
        break;
      }
    }

    locationHistory[i + 1] = nextLocation;
  }

  display(uniqueCount);
}
