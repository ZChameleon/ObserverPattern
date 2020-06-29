#pragma once


#include "interfaces.h"
#include <cstdint>
#include <iostream>


namespace dynamic {


class Observer final : public IObserver {
public:
    explicit Observer(std::uint32_t id) noexcept : id_(id) {}

    void update(std::string_view message) noexcept override {
        std::cout << "Observer [" << id_ << "] received message: " << message
                  << std::endl;
    }

private:
    std::uint32_t id_;
};


} // namespace dynamic
