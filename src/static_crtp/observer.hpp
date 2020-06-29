#pragma once


#include "interfaces.h"
#include <cstdint>
#include <iostream>


namespace static_crtp {


class Observer final : public IObserver<Observer> {
    using Base = IObserver<Observer>;
    friend Base;

public:
    explicit Observer(std::uint32_t id) noexcept : id_(id) {}

private:
    using Base::update;
    void update_impl(std::string_view message) noexcept {
        std::cout << "Observer [" << id_ << "] received message: " << message
                  << std::endl;
    }

private:
    std::uint32_t id_;
};


} // namespace static_crtp
