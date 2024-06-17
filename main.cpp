#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "examen.h"

using namespace std;

int main() {
    string operation;
    string date_str;
    string event;
    string error_msg;

    while (cin >> operation) {
        if (operation == "Add") {
            cin >> date_str;
            getline(cin, event);
            event = event.substr(1);
            if (validate_date(date_str, error_msg)) {
                add_event(events, date_str, event);
            } else {
                cout << error_msg << endl;
            }
        } else if (operation == "Del") {
            cin >> date_str;
            getline(cin, event);
            if (validate_date(date_str, error_msg)) {
                if (event.empty()) {
                    cout << "Deleted " << delete_date(events, date_str) << " events" << endl;
                } else {
                    event = event.substr(1);
                    if (delete_event(events, date_str, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                }
            } else {
                cout << error_msg << endl;
            }
        } else if (operation == "Find") {
            cin >> date_str;
            if (validate_date(date_str, error_msg)) {
                set<string> events_found = find(events, date_str);
                for (const auto& event : events_found) {
                    cout << event << endl;
                }
            } else {
                cout << error_msg << endl;
            }
        } else if (operation == "Print") {
            print_events();
        } else {
            cout << "Unknown command: " << operation << endl;
        }
    }
    
    return 0;
}
