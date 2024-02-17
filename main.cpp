#include "Json/ParseJson.h"
#include "Json/WriteJson.h"

#include "Store/StoreJson.h"

#include <iostream>
#include <map>
#include <string>

int testjson() {
  std::vector<std::string> myvector;
  myvector.push_back("Hi");
  myvector.push_back("Hi");
  std::cout << WriteJson(myvector) << std::endl;

  std::map<std::string, std::string> mymap;
  mymap.emplace("Hi", "1w");
  mymap.emplace("Hi1", "2w");
  std::cout << WriteJson(mymap) << std::endl;

  std::cout << ParseJson<std::string>("\"First part \\nSecond Part")
            << std::endl;

  std::string jsonvector = WriteJson(myvector);
  for (auto i : ParseJson<std::vector<std::string>>(jsonvector)) {
    std::cout << i << std::endl;
  }
  std::cout << ParseJson<unsigned long long>("5") << std::endl;

  std::string jsonmap = WriteJson(mymap);

  auto test = ParseJson<std::map<std::string, std::string>>(jsonmap);
  for (auto &it : test) {
    std::cout << "Key: " << std::any_cast<std::string>(it.first)
              << " Value: " << std::any_cast<std::string>(it.second)
              << std::endl;
  }

  return 0;
}

int testjsonstore() {
  std::string name = "TestTable";
  if (CreateJsonTable(name))
    std::cout << "Could not create table" << std::endl;

  std::vector<std::string> myvector;
  myvector.push_back("Hi");
  myvector.push_back("Hi");

  std::vector<std::string> myvector1;
  myvector1.push_back("Hi1");
  myvector1.push_back("Hi1");

  if (InsertJsonTable("TestTable", WriteJson(myvector)))
    std::cout << "Could not store data" << std::endl;

  if (InsertJsonTable("TestTable", WriteJson(myvector1)))
    std::cout << "Could not store data" << std::endl;

  std::vector<std::vector<std::string>> TableVector =
      ExtractJsonTable<std::vector<std::string>>("TestTable");
  std::cout << TableVector.front().front() << std::endl;

  std::vector<std::string> myvector2;
  myvector2.push_back("Hi2");
  myvector2.push_back("Hi2");

  ReplaceJsonTable("TestTable", "\"Hi\"", WriteJson(myvector2));

  // if (RemoveJsonTable("TestTable", WriteJson(myvector)))
  //  std::cout << "could not remove from table" << std::endl;

  // if (DeleteJsonTable("TestTable"))
  // std::cout << "Could not delete table" << std::endl;

  return 0;
}

int main() { return testjsonstore(); }
