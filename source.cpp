#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

map<string, set<string>> events;

//Funcion por Lucas, anhadir evento
void anhadir_evento(const string& date, const string& event);


int main(){





    return 0;
}

//Funcion por Lucas, anhadir evento
void anhadir_evento(const string& date, const string& event) {
    events[date].insert(event);
}