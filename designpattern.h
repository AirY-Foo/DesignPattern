#ifndef DESIGNPATTERN_H
#define DESIGNPATTERN_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//观察者模式
//观察者
class Secretary;
class Observer{
private:
    string name;
    Secretary *sub;
public:
    Observer(string strname,Secretary *strsub)
    {
        name = strname;
        sub= strsub;
    }

    void Update();
};

void Observer::Update()
{
    cout << name << ":" << sub->action <<"Don't play now,Work!" << endl;
}


//秘书，通知者
//class Observer;
class Secretary{
private:
    vector<Observer> observers;
public:
    string action;
    void Add(Observer ob)
    {
        observers.push_back(ob);
    }

    void Notify()
    {
        vector<Observer>::iterator p = observers.begin();
        while(p!=observers.end())
        {
            (*p).Update();
            p++;
        }
    }
};
#endif // DESIGNPATTERN_H
