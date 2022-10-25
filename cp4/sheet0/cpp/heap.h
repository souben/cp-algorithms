#include <iostream>

void insert(int element);
int getMax();
void removeMax();
int getSize();
void print();

void checkSize(int expected) {
    int got = getSize();
    if (got != expected) {
        std::cout << "Got size " << got << ", expected " << expected << std::endl;
    }
}

void checkMax(int expected) {
    int got = getMax();
    if (got != expected) {
        std::cout << "Got max " << got << ", expected " << expected << std::endl;
    }
}

int main() {
    checkSize(0);
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    checkMax(5);
    removeMax();
    print();
    removeMax();
    print();
    checkSize(3);
    checkMax(3);
    removeMax();
    print();
    removeMax();
    print();

}
