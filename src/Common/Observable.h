#ifndef OBSERVABLE
#define OBSERVABLE

#include <memory>
#include "src/Common/Observer.h"
#include "src/Common/Notify.h"

using namespace std;

class Observable {
protected:
    vector<shared_ptr<Observer>> observers;
public:
    void addObserver(shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void removeObserver(shared_ptr<Observer> dObserver) {
        for (auto it = observers.begin(); it != observers.end();) {
            if (*it == dObserver) {
                it = observers.erase(it);
            } else {
                it++;
            }
        }
    }

    void notify(Notify noti) {
        for (const auto &observer:observers) {
            observer->update(noti);
        }
    }
};


#endif
