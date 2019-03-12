/*
misc.cpp
Author : BAKFR
File under GNU GPL v3.0
*/
#include "misc.hpp"

#include <algorithm>  //std::generate
#include <array>      //std::array
#include <functional> //std::ref
#include <random>     //std::mt19937, std::seed_seq, std::random_device

namespace Utils::Misc {

    std::mt19937& getRNGEngine() {
        static std::mt19937 mt = []() {
            std::array<std::mt19937::result_type, std::mt19937::state_size> data;
            std::random_device device;
            std::generate(data.begin(), data.end(), std::ref(device));
            std::seed_seq seed(data.begin(), data.end());
            mt.seed(seed);
            return mt;
        }();

        return mt;
    }

    int randU(int limit) {
        return random_(0, limit - 1);
    }

    unsigned int randUI(unsigned int limit) {
        return random_(0u, limit - 1u);
    }

    std::size_t hash(const std::string &str) {
        return std::hash<std::string>{}(str);
    }
} // namespace Utils::Misc

