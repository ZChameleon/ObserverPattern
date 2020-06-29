#pragma once


#include <memory>
#include <string_view>


#define DEFINE_UNDERLYING(clazz)                                               \
    clazz& underlying() { return static_cast<clazz&>(*this); }                 \
    clazz const& underlying() const { return static_cast<clazz const&>(*this); }


namespace static_crtp {


template <typename Observer_>
class IObserver {
public:
    void update(std::string_view message) { underlying().update_impl(message); }

private:
    DEFINE_UNDERLYING(Observer_)
};


template <typename>
class ISubject;

template <template <typename> typename Subject_, typename Observer_>
class ISubject<Subject_<Observer_>> {
public:
    void attach(std::shared_ptr<IObserver<Observer_>> const& observer) {
        underlying().attach_impl(observer);
    }

    void detach(std::shared_ptr<IObserver<Observer_>> const& observer) {
        underlying().detach_impl(observer);
    }

    void notifyAll(std::string_view message) {
        underlying().notifyAll_impl(message);
    }

private:
    DEFINE_UNDERLYING(Subject_<Observer_>)
};


} // namespace static_crtp
