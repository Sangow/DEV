#include <iostream>

template <typename T>
class Point {
    private:
        T x, y;

    public:
        Point() {
            this->x = 0;
            this->y = 0;
        }

        Point(T x, T y) {
            this->x = x;
            this->y = y;
        }

        T getX() const {
            return this->x;
        }

        T getY() const {
            return this->y;
        }

        void print() {
            std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
        }
};

int main() {
    Point<float> *p1 = new Point<float>(2.2, 3.5);
    Point<int> *p2 = new Point<int>(4, 2);
    Point<double> *p3 = new Point<double>(1.1, 9.1);

    p1->print();
    p2->print();
    p3->print();

    return 0;
}