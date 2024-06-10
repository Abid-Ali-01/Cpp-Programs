#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};

    // Print initial contents
    std::cout << "Before swap:\n";
    std::cout << "vec1: ";
    for (int num : vec1) {
        std::cout << num << " ";
    }
    std::cout << "\nvec2: ";
    for (int num : vec2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Swap the contents of vec1 and vec2
    std::swap(vec1, vec2);

    // Print swapped contents
    std::cout << "\nAfter swap:\n";
    std::cout << "vec1: ";
    for (int num : vec1) {
        std::cout << num << " ";
    }
    std::cout << "\nvec2: ";
    for (int num : vec2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
