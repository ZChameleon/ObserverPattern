#pragma once


#include "interfaces.h"
#include <algorithm>
#include <vector>


namespace static_crtp {


template <typename Observer_>
class Subject final : public ISubject<Subject<Observer_>> {
    using Base = ISubject<Subject<Observer_>>;
    friend Base;

private:
    using Base::attach;
    void attach_impl(std::shared_ptr<IObserver<Observer_>> const& observer) {
        observers_.emplace_back(observer);
    }

    using Base::detach;
    void detach_impl(std::shared_ptr<IObserver<Observer_>> const& observer) {
        observers_.erase(
            std::remove(observers_.begin(), observers_.end(), observer));
    }

    using Base::notifyAll;
    void notifyAll_impl(std::string_view message) {
        for (auto& observer : observers_) {
            observer->update(message);
        }
    }

private:
    std::vector<std::shared_ptr<IObserver<Observer_>>> observers_;
};


} // namespace static_crtp
