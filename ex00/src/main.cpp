#include"./include/easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        std::vector<int>::iterator vec_it = easyfind(vec, 3);
        std::cout << "Found element at position " << std::distance(vec.begin(), vec_it) << std::endl;
        std::list<int>::iterator lst_it = easyfind(lst, 20);
        std::cout << "Found element at position " << std::distance(lst.begin(), lst_it) << std::endl;
        easyfind(vec, 6);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
