#include "concepts.h"
#include "observer.hpp"
#include "subject.hpp"


using namespace static_concepts;


// template <ISubject Subject_>
// void test(Subject_& subject);


// clang-format off
template <template <typename> typename Subject_, typename Observer_>
    requires ISubject<Subject_, Observer_>
void test(Subject_<Observer_>& subject) {
    subject.attach(std::make_shared<Observer>(2));
    subject.attach(std::make_shared<Observer>(3));
    subject.attach(std::make_shared<Observer>(4));
    subject.notifyAll("test");
}
// clang-format on


int main() {
    auto observer = std::make_shared<Observer>(1);

    Subject<Observer> subject;
    subject.attach(observer);
    test(subject);

    subject.detach(observer);
    subject.notifyAll("main");
}
