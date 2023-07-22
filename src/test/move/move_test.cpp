#include <utility>
#include <vector>
#include <string>

class MyClass {
public:
    // Constructor
    MyClass(int value) : data(new int(value)) {}

    // Move constructor
    MyClass(MyClass&& other) : data(other.data) {
        other.data = nullptr; // Set the source object's pointer to null to avoid double deletion
    }

    // Destructor
    ~MyClass() {
        delete data;
    }

private:
    int* data;
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = std::move(obj1); // Use std::move to move obj1 to obj2

    // At this point, obj1 is in a valid but unspecified state, typically an "empty" state
    // and obj2 now contains the data that was previously in obj1

    return 0;
}