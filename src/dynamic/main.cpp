#include "interfaces.h"
#include "observer.hpp"
#include "subject.hpp"


using namespace dynamic;


void test(ISubject& subject) {
    subject.attach(std::make_shared<Observer>(2));
    subject.attach(std::make_shared<Observer>(3));
    subject.attach(std::make_shared<Observer>(4));
    subject.notifyAll("test");
}


int main() {
    auto observer = std::make_shared<Observer>(1);

    Subject subject;
    subject.attach(observer);
    test(subject);

    subject.detach(observer);
    subject.notifyAll("main");
}
