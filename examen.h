#ifndef EXAMEN_H
#define EXAMEN_H

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

extern map<string, set<string>> events; 

void add_event(map<string, set<string>>& events, const string& date_str, const string& event);
bool delete_event(map<string, set<string>>& events, const string& date_str, const string& event);
bool validate_date(const string& date_str, string& error_msg);
int delete_date(map<string, set<string>>& events, const string& date_str);
set<string> find(map<string, set<string>>& events, const string& date_str);
void print_events();

#endif
