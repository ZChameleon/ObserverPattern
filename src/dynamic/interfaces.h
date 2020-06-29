#pragma once


#include <memory>
#include <string_view>


namespace dynamic {


class IObserver {
public:
    virtual void update(std::string_view message) = 0;
};


class ISubject {
public:
    virtual void attach(std::shared_ptr<IObserver> const& observer) = 0;
    virtual void detach(std::shared_ptr<IObserver> const& observer) = 0;
    virtual void notifyAll(std::string_view message) = 0;
};


} // namespace dynamic
