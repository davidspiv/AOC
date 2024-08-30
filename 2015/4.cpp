#include <fstream>
#include <iostream>
#include <string>

using String = std::string;

union Output {
  int resultAsInt;
  String resultAsString;
};

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

bool testA(const String &inputToTest) {
  int count = 0;
  char sub = 'a';
  size_t pos = inputToTest.find(sub, 0);
  while (pos != String::npos) {
    count++;
    pos = inputToTest.find(sub, pos + 1);
  }
  if (count > 3) {
    return false;
  }
  return true;
}

bool testB(const String &inputToTest) { return true; }
bool testC(const String &inputToTest) { return true; }

int getDataFromFile(String fileName) {
  int count = 0;
  std::ifstream file(fileName);
  String line;
  while (std::getline(file, line)) {
    if (testA(line) && testB(line) && testC(line)) count++;
  }
  return count;
}

int main() {
  const int total = getDataFromFile("./2015/4.dat");
  display(total);
}
