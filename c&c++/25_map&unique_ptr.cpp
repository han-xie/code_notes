/*
 * Reference:
 * https://blog.csdn.net/zsc_976529378/article/details/52250597
 *
 * Compile with g++ 25_map\&unique_ptr.cpp -o test_map_ptr
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

class TestClass {
  public:
    TestClass(int classID) {
      classID_ = classID;
      std::cout << "test constructor, ID: " << classID_ << std::endl;
    }
    ~TestClass() {
      std::cout << "test destructor, ID: " << classID_ << std::endl;
    }
    void PrintMessage() {
      std::cout << "test message, ID: " << classID_ << std::endl;
    }
  private:
    int classID_;
};

int main() {
  std::unordered_map<std::string, std::unique_ptr<TestClass> > mymap;
  std::cout << "before map emplace" << std::endl;
  mymap.emplace("test1", new TestClass(1) );
  mymap.emplace("test2", new TestClass(2) );
  mymap["test1"]->PrintMessage();
  mymap["test2"]->PrintMessage();
  std::cout << "before map erase" << std::endl;
  mymap.erase("test1");
  std::cout << "after map erase" << std::endl;
  return 0;
}
