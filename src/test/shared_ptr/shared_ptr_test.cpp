#include <memory>
#include <string>
#include <vector>
#include <cstdio>

using std::shared_ptr;

class TestClass {
public:
  std::string name;

  TestClass(): name("Default name") {
    ::printf("TestClass: %s allocated.\n", name.c_str());
  }

  TestClass(std::string s): name(s) {
    ::printf("TestClass: %s allocated.\n", name.c_str());
  }

  ~TestClass() {
    ::printf("TestClass: %s free.\n", name.c_str());
  }
};

shared_ptr<TestClass> testFun1(shared_ptr<TestClass> ptr) {
  shared_ptr<TestClass> ptrInFun;
  ptr.use_count();
  ptrInFun = ptr;
  return ptrInFun;
}

shared_ptr<TestClass> testFun2(shared_ptr<TestClass>& ptr) {
  shared_ptr<TestClass> ptrInFun;
  ptr.use_count();
  ptrInFun = ptr;
  return ptrInFun;
}

int main() {
  /* Create shared object in block with shared_ptr */
  TestClass* commonPtr;  // Uninitialized common pointer
  shared_ptr<TestClass> testClassPtr1;

  {
    /* shared_ptr assign value */
    shared_ptr<TestClass> testClassPtr2;
    shared_ptr<TestClass> testClassPtr3(std::make_shared<TestClass> ());
    testClassPtr1 = testClassPtr3;  // Copy shared_ptr increase use count 
    testClassPtr2 = std::move(testClassPtr3);  // Move shared_ptr do not increase use count
    commonPtr = testClassPtr2.get();  // Copy address to Common pointer do not increase use count
    shared_ptr<TestClass> testClassPtr4(commonPtr);  // Initalize from a common pointer do not increase count
    printf("\n");
  }
  testClassPtr1.reset();  // Reset decrease use count

  /* Copy or move shared_ptr to container */
  std::vector<shared_ptr<TestClass>> ptrList;
  testClassPtr1 = std::move(std::make_shared<TestClass> ("shared_ptr-test"));
  ptrList.push_back(testClassPtr1);
  ptrList.push_back(std::move(testClassPtr1));
  ptrList.erase(ptrList.begin() + 1);

  /* Pass to or return from function*/
  testFun1(ptrList[0]);
  auto newPtr = testFun2(ptrList[0]);
  return 0;
}