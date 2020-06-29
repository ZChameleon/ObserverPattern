#pragma once


#include "concepts.h"
#include <algorithm>
#include <vector>


namespace static_concepts {


template <IObserver Observer_>
class Subject {
public:
    void attach(std::shared_ptr<Observer_> const& observer) {
        observers_.emplace_back(observer);
    }

    void detach(std::shared_ptr<Observer_> const& observer) {
        observers_.erase(
            std::remove(observers_.begin(), observers_.end(), observer));
    }

    void notifyAll(std::string_view message) {
        for (auto& observer : observers_) {
            observer->update(message);
        }
    }

private:
    std::vector<std::shared_ptr<Observer_>> observers_;
};


} // namespace static_concepts
