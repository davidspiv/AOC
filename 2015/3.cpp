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
  const String data = getDataFromFile("./2015/3.dat");

  String locationHistory[data.length()];
  locationHistory[0] = "0/0";
  locationHistory[1] = "0/0";

  int uniqueCount = 1;

  for (size_t i = 0; i < data.length() - 1; i++) {
    String location = locationHistory[i];

    String tokenX = location.substr(0, location.find('/'));
    location.erase(0, tokenX.length() + 1);
    String tokenY = location.substr(0, location.find('/'));

    switch (data[i]) {
      case '^':
        tokenY = std::to_string(stoi(tokenY) + 1);
        break;
      case 'v':
        tokenY = std::to_string(stoi(tokenY) - 1);
        break;
      case '<':
        tokenX = std::to_string(stoi(tokenX) + 1);
        break;
      case '>':
        tokenX = std::to_string(stoi(tokenX) - 1);
        break;
      default:
        return 1;
    }

    const String nextLocation = tokenX + '/' + tokenY;

    uniqueCount++;

    for (size_t j = 0; j < data.length(); j++) {
      if (locationHistory[j] == nextLocation) {
        uniqueCount--;
        break;
      }
    }
    if (i >= data.length() - 2) {
      locationHistory[i + 1] = nextLocation;
    } else {
      locationHistory[i + 2] = nextLocation;
    }
  }
  display(uniqueCount);
}
