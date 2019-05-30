#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <ctime>
#include <chrono>

long long getMilliseconds() {
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

void print(const std::set<std::string> value) {
    for (const std::string & v : value) {
        std::cout << v << std::endl;
    }
}

void print(const std::map<std::string, int> value) {
    for (const auto & v : value) {
        std::cout << "for the word " << v.first << " found " << v.second << " repeats" << std::endl;
    }
}

void print(const std::unordered_map<std::string, int> value) {
    for (const auto & v : value) {
        std::cout << "for the word " << v.first << " found " << v.second << " repeats" << std::endl;
    }
}

std::set<std::string> splitToSet(const std::string &s, char delim) {
  std::string item;
  std::stringstream ss(s);
  std::set<std::string> res;
  while (std::getline(ss, item, delim)) {
    res.insert(item);
  }
  return res;
}

std::map<std::string, int> splitToMap(const std::string &s, char delim) {
  std::string item;
  std::stringstream ss(s);
  std::map<std::string, int> res;
  while (std::getline(ss, item, delim)) {
      res[item] = res[item] + 1;
  }
  return res;
}

std::unordered_map<std::string, int> splitToUnOrderedMap(const std::string &s, char delim) {
  std::string item;
  std::stringstream ss(s);
  std::unordered_map<std::string, int> res;
  while (std::getline(ss, item, delim)) {
      res[item] = res[item] + 1;
  }
  return res;
}

std::string readFile(const std::string & path) {
  std::ifstream f(path); //taking file as inputstream
  if (f) {
      std::ostringstream ss;
      ss << f.rdbuf(); // reading data
      return ss.str();
   }
   return "";
}

void task1(const std::string & text) {
    std::cout << "*** TASK 1 ***" << std::endl;
    std::set<std::string> res = splitToSet(text, ' ');
    std::cout << "Found: " << res.size() << " unique words" << std::endl;
    print(res);
}

void task2(const std::string & text) {
    std::cout << "*** TASK 2 ***" << std::endl;
    std::map<std::string, int> res = splitToMap(text, ' ');
    std::cout << "Found: " << res.size() << " unique words" << std::endl;
    print(res);
}

void task3(const std::string & filepath) {
    std::cout << "*** TASK 3 ***"<< std::endl;
    std::string data = readFile(filepath);

    long long time1 = getMilliseconds();
    std::unordered_map<std::string, int> res = splitToUnOrderedMap(data, ' ');
    std::cout << "Found: " << res.size() << " unique words. Time: " << getMilliseconds() - time1 << " ms" << std::endl;
    print(res);

    long long time2 = getMilliseconds();
    std::map<std::string, int> res2 = splitToMap(data, ' ');
    std::cout << "Found: " << res2.size() << " unique words. Time: " << getMilliseconds() - time2 << " ms" << std::endl;
    print(res2);
}

int main() {
    task1("На вход в функцию подается случайный текст. Необходимо напечатать все слова, которые в нем встречаются. На вход в функцию подается случайный текст. Необходимо напечатать все слова, которые в нем встречаются. На вход в функцию подается случайный текст. Необходимо напечатать все слова, которые в нем встречаются.");
    task2("На вход в функцию подается случайный текст. Необходимо напечатать все слова, которые в нем встречаются и количество вхождений каждого слова. На вход в функцию подается случайный текст. Необходимо напечатать все слова, которые в нем встречаются и количество вхождений каждого слова.");
    task3("/home/wokinsark/task3.txt");
    return 0;
}

