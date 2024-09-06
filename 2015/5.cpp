#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

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

bool isNice(const String &str) {
  bool hasDuplicate = false;
  bool hasMatch = false;

  for (size_t i = 0; i < str.length(); i++) {
    if (i >= 1 && !hasDuplicate) {
      const String newStr1 = str.substr(0, i - 1);

      const String newStr2 = str.substr(i + 1, str.length());

      if (newStr1.find(str.substr(i - 1, 2)) != std::string::npos ||
          newStr2.find(str.substr(i - 1, 2)) != std::string::npos) {
        hasDuplicate = true;
      }
    }

    if (i >= 2 && !hasMatch) {
      if (str[i] == str[i - 2]) {
        hasMatch = true;
      }
    }

    if (hasDuplicate && hasMatch) {
      return true;
    }
  }

  return false;
}

int getNiceStringTotal(String fileName) {
  int count = 0;
  std::ifstream file(fileName);
  String line;

  while (std::getline(file, line)) {
    if (isNice(line)) count++;
  }
  return count;
}

int main() {
  const int total = getNiceStringTotal("./2015/5.dat");
  display(total);
}

// bool isNice(const String &str) {
//   std::unordered_map<String, int> letterFreq;
//   bool duplicate = false;
//   for (size_t i = 0; i < str.length(); i++) {
//     letterFreq[str.substr(i, 1)]++;
//     if (i != 0) {
//       if (str[i] == str[i - 1]) {
//         duplicate = true;
//       }
//     }
//   }

//   const bool doesNotContain = str.find("ab") == std::string::npos &&
//                               str.find("cd") == std::string::npos &&
//                               str.find("pq") == std::string::npos &&
//                               str.find("xy") == std::string::npos;

//   // std::cout << doesNotContain << std::endl;

//   const int total = letterFreq["a"] + letterFreq["e"] + letterFreq["i"] +
//                     letterFreq["o"] + letterFreq["u"];

//   if (total >= 3 && doesNotContain && duplicate) {
//     return true;
//   }

//   return false;
// }
