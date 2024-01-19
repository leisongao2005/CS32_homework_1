#include "GamerMap.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    GamerMap a;
    a.addGamer("John");
    a.addGamer("Charles");
    a.addGamer("Tony");
    a.addGamer("Zackary");
    a.addGamer("Max");
    a.addGamer("Richie");
    cout << a.numGamers() << endl;
    a.play("Tony", 12.3);
    a.play("Zackary", 1.3);
    a.play("Tony", 4.6);
    a.play("Richie", 9.8);
    cout << a.hoursSpent("Tony") << endl;;
    cout << a.hoursSpent("Richie") << endl;;
    cout << a.hoursSpent("Max") << endl;;
    a.print();
}
