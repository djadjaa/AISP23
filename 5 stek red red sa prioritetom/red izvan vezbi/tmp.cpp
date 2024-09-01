#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> history;
    int n;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "back") {
            if (history.empty()) {
                std::cout << "-" << std::endl;
            } else {
                std::string current = history.front();
                history.pop();
                if (history.empty()) {
                    std::cout << "-" << std::endl;
                } else {
                    std::cout << history.front() << std::endl;
                }
                history.push(current);
            }
        } else {
            history.push(command);
            std::cout << command << std::endl;
        }
    }

    // Ispisi preostale sajtove u istoriji
    while (!history.empty()) {
        std::cout << history.front() << std::endl;
        history.pop();
    }

    return 0;
}
