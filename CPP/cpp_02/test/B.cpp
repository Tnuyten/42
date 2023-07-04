#include "A.hpp"
#include "B.hpp"

B::B() : x(0), y(0) {};
B::B(const B& b) : x(b.x), y(b.y) {};