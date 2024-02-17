#include "WriteJson.h"

std::string WriteJson(int input) { return std::to_string(input); }

std::string WriteJson(float input) { return std::to_string(input); }

std::string WriteJson(double input) { return std::to_string(input); }

std::string WriteJson(short input) { return std::to_string(input); }

std::string WriteJson(long input) { return std::to_string(input); }

std::string WriteJson(unsigned int input) { return std::to_string(input); }

std::string WriteJson(unsigned short input) { return std::to_string(input); }

std::string WriteJson(unsigned long input) { return std::to_string(input); }

std::string WriteJson(char input) {
  std::string result = "";
  std::string sChars = "\"\\/bfnrt";
  std::string dsChars = "\"\\/\b\f\n\r\t";

  if (sChars.find(input) != std::string::npos) {
    result += '\\';
  }
  result += input;

  return "\"" + result + "\"";
}

std::string WriteJson(std::string input) {
  std::string result = "";
  std::string sChars = "\"\\/bfnrt";
  std::string dsChars = "\"\\/\b\f\n\r\t";

  for (char c : input) {

    if (sChars.find(c) != std::string::npos) {
      result += '\\';
    }
    result += c;
  }

  return "\"" + result + "\"";
}

std::string WriteJson(const char *input) {
  std::string result = "";
  std::string sChars = "\"\\/bfnrt";
  std::string dsChars = "\"\\/\b\f\n\r\t";

  int it = 0;
  for (char c = input[it]; it < sizeof(input) - 1; it++) {

    if (sChars.find(c) != std::string::npos) {
      result += '\\';
    }
    result += c;
  }

  return "\"" + result + "\"";
}

std::string WriteJson(char *input) {
  std::string result = "";
  std::string sChars = "\"\\/bfnrt";
  std::string dsChars = "\"\\/\b\f\n\r\t";

  int it = 0;
  for (char c = input[it]; it < sizeof(input) - 1; it++) {

    if (sChars.find(c) != std::string::npos) {
      result += '\\';
    }
    result += c;
  }

  return "\"" + result + "\"";
}

std::string WriteJson(bool input) { return input ? "true" : "false"; }
