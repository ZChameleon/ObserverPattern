#pragma once


#include "interfaces.h"
#include <algorithm>
#include <vector>


namespace dynamic {


class Subject final : public ISubject {
public:
    void attach(std::shared_ptr<IObserver> const& observer) override {
        observers_.emplace_back(observer);
    }

    void detach(std::shared_ptr<IObserver> const& observer) override {
        observers_.erase(
            std::remove(observers_.begin(), observers_.end(), observer));
    }

    void notifyAll(std::string_view message) override {
        for (auto& observer : observers_) {
            observer->update(message);
        }
    }

private:
    std::vector<std::shared_ptr<IObserver>> observers_;
};


} // namespace dynamic
