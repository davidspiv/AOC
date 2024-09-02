
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using String = std::string;

void printFrequencies(const String &str) {
  std::unordered_map<String, int> letterFreq;


  for (size_t i = 0; i < str.length(); i++) {
    letterFreq[str.substr(i, 1)]++;
  }

  std::unordered_map<String, int>::iterator p;
  for (p = letterFreq.begin(); p != letterFreq.end(); p++) {
    std::cout << "(" << p->first << ", " << p->second << ")\n";
  }
}

// Driver code
int main() {
  String str = "Hello this is a sentence";
  printFrequencies(str);
  return 0;
}
