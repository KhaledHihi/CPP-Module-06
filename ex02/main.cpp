#include "Fun.hpp"

int main(){
    Base *base = generate();
    identify(base);
    identify(*base);

    Base *base2 = generate();
    identify(base2);
    identify(*base2);

    delete base;
    delete base2;
}
