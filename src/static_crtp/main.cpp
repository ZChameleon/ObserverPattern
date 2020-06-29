#include "interfaces.h"
#include "observer.hpp"
#include "subject.hpp"


using namespace static_crtp;


template <typename Subject_>
void test(ISubject<Subject_>& subject) {
    subject.attach(std::make_shared<Observer>(2));
    subject.attach(std::make_shared<Observer>(3));
    subject.attach(std::make_shared<Observer>(4));
    subject.notifyAll("test");
}


int main() {
    auto observer = std::make_shared<Observer>(1);

    Subject<Observer> subject;
    ISubject<Subject<Observer>>& rsubject = subject;
    rsubject.attach(observer);
    test(subject);

    rsubject.detach(observer);
    rsubject.notifyAll("main");
}
