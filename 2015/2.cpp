#include <fstream>
#include <iostream>
#include <string>

using String = std::string;

struct Present {
  int wrappingPaper;
  int ribbon;
};

struct Result {
  int wrappingPaperTotal;
  int ribbonTotal;
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

Present processLine(String line) {
  String lengthToken = line.substr(0, line.find('x'));
  line.erase(0, lengthToken.length() + 1);
  String widthToken = line.substr(0, line.find('x'));
  line.erase(0, widthToken.length() + 1);
  String heightToken = line.substr(0, line.find('x'));

  const int length = stoi(lengthToken);
  const int width = stoi(widthToken);
  const int height = stoi(heightToken);

  const int surfaceArea =
      2 * length * width + 2 * width * height + 2 * length * height;

  const int max = std::max(std::max(length, width), height);
  const int areaOfSmallestFace = length * width * height / max;

  const int perimeterOfSmallestFace =
      length * 2 + width * 2 + height * 2 - max * 2;

  Present present;
  present.wrappingPaper = surfaceArea + areaOfSmallestFace;
  present.ribbon = perimeterOfSmallestFace + length * width * height;

  return present;
}

Result calcTotal(String fileName) {
  Result result;
  result.wrappingPaperTotal = 0;
  result.ribbonTotal = 0;

  std::ifstream file(fileName);
  String line;

  while (std::getline(file, line)) {
    const Present present = processLine(line);
    result.wrappingPaperTotal += present.wrappingPaper;
    result.ribbonTotal += present.ribbon;
  }

  return result;
}

int main() {
  const Result result = calcTotal("./2015/2.dat");
  display("Wrapping paper (sqft): ", 0);
  display(result.wrappingPaperTotal);
  display("Ribbon (ft): ", 0);
  display(result.ribbonTotal);
}
