#pragma once


#include "concepts.h"
#include <cstdint>
#include <iostream>


namespace static_concepts {


class Observer {
public:
    explicit Observer(std::uint32_t id) noexcept : id_(id) {}

    void update(std::string_view message) noexcept {
        std::cout << "Observer [" << id_ << "] received message: " << message
                  << std::endl;
    }

private:
    std::uint32_t id_;
};


} // namespace static_concepts
