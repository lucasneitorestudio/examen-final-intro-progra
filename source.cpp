#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

map<string, set<string>> events;

//Funcion por Lucas, add_event
void add_event(const string& date, const string& event);
bool delete_event(const string& date, const string& event);

int main(){





    return 0;
}

//Funcion por Lucas, add_event
void add_event(const string& date, const string& event) {
    events[date].insert(event);
}

bool delete_event(const string& date, const string& event){
    if(events.count(date) && events[date].count(event)){
        events[date].erase(event);
        if(events[date].empty()){
            events.erase(date);
        }
        return true;
    }
    return false;
}