#include <iostream>

#include <include/union-find/quick-find.h>

int main(int argc, char** argv) {
    uf::QuickFind quick_find(3);
    quick_find.Union(0, 1);
    std::cout << quick_find.Count() << std::endl;

    return EXIT_SUCCESS;
}
