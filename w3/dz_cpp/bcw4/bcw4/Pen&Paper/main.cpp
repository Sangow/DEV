#include <iostream>
#include "Pen.h"

int main() {
    try {
        Pen pen(20);
        Paper paper(40);

        paper.show();

        pen.refill();

        pen.write(paper, "Hello, world!");
        paper.show();

        pen.write(paper, " Come over to the dark side!");
        paper.show();

        pen.refill();

        pen.write(paper, "ver to the dark side!");
        paper.show();

        pen.refill();

        pen.write(paper, "This text will not be printed!");


    } catch ( OutOfSpace e ) {
        std::cout << "Not enough space!" << std::endl;
    } catch ( OutOfInk e ) {
        std::cout << "Pen is empty!" << std::endl;
    }
    
    return 0;
}