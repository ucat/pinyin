#include <iostream>

#include "pinyin.hpp"


int main(void) {
    std::cout << ucat::hz2py_dict.size() << std::endl;
    std::cout << ucat::hz2py_dict.load_factor() << std::endl;
    std::cout << ucat::hz2py_dict.max_load_factor() << std::endl;

    ucat::Pinyin hz2py;
    std::cout << hz2py.string2pinyin(L"重庆重型机械厂长高身长") << std::endl;
    return 0;
}
