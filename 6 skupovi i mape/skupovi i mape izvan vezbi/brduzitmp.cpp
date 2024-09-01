#include <iostream>
#include <set>
#include <cmath>

struct Line {
    int x1, y1, z1, x2, y2, z2;

    // Конструктор за иницијализацију
    Line(int x1, int y1, int z1, int x2, int y2, int z2)
        : x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2) {}

    // Метод за рачунање дужине дужи
    double length() const {
        return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) + std::pow(z2 - z1, 2));
    }

    // Поређење за коришћење у std::set
    bool operator<(const Line& other) const {
        return length() < other.length();
    }
};

int main() {
    int N;
    std::cin >> N;

    // Креирајмо скуп за чување дужина
    std::set<double> lengths;

    for (int i = 0; i < N; ++i) {
        int x1, y1, z1, x2, y2, z2;
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        // Креирајмо објекат типа Line
        Line line(x1, y1, z1, x2, y2, z2);

        // Додајемо дужину у скуп
        lengths.insert(line.length());
    }

    // Исписујемо број различитих дужина
    std::cout << lengths.size() << std::endl;

    return 0;
}
