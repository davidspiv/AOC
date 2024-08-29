#include <fstream>
#include <iostream>
#include <string>

using String = std::string;

void display(int output, bool returnFlag = 1) {
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

int process(String data) {
  int floor = 0;
  for (size_t i = 0; i < data.length(); i++) {
    if (floor == -1) {
      display(i);
    }
    if (data[i] == '(') {
      floor++;
      continue;
    }
    floor--;
  }
  return floor;
}

int main() {
  const String data = getDataFromFile("1.dat");
  const int floor = process(data);
  display(floor);
}
