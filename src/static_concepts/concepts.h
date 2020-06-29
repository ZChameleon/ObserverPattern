#pragma once


#include <concepts>
#include <memory>
#include <string_view>


namespace static_concepts {


// clang-format off
template <typename Observer_>
concept IObserver =
    requires(Observer_ observer, std::string_view message) {
        { observer.update(message) } -> std::same_as<void>;
};


template <template <typename> typename Subject_, typename Observer_>
concept ISubject =
    IObserver<Observer_> &&
    requires(Subject_<Observer_> subject,
             std::shared_ptr<Observer_> observer,
             std::string_view message) {
        { subject.attach(observer) } -> std::same_as<void>;
        { subject.detach(observer) } -> std::same_as<void>;
        { subject.notifyAll(message) } -> std::same_as<void>;
};
// clang-format on


} // namespace static_concepts
