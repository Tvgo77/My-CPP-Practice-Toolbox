#include "include/syscall_wrap.h"
#include <string>

int main() {
    std::string s1("hello\n");
    Write(STDOUT_FILENO, s1.c_str(), s1.size());
    return 0;
}