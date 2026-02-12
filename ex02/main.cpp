#include "Functions.hpp"

int main(){
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
}
