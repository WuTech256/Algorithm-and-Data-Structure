#include <bits/stdc++.h>
using namespace std;
struct Employee {
    string name;
    int score;
    int employeeNo;
};
 
int main() {
    int numCandidates;
    cin >> numCandidates;
    vector<Employee> employees(numCandidates);
     
    unordered_map<string, int> nameId;
    for (int id = 0; id < numCandidates; ++id) {
        cin >> employees[id].name;
        employees[id].employeeNo = id;
        employees[id].score = 0;
        nameId.insert({employees[id].name, id});
    }
 
    int numParticipants;
    cin >> numParticipants;
    for (int idx = 0; idx < numParticipants; ++idx) {
        string name;
        int score;
        cin >> name;
        cin >> score;
        auto getNameId = nameId.find(name);
        if (getNameId != nameId.end()) {
            int getId = getNameId->second;
            employees[getId].score += score;
        }
    }
     
    sort(employees.begin(), employees.end(), [] (const Employee& a, const Employee& b) {
        if (a.score == b.score) {
            return (a.employeeNo < b.employeeNo);
        } else {
            return (a.score > b.score);
        }
    });
    
    for (int idx = 0; idx < 3; ++idx) {
        cout << employees[idx].name << " " << employees[idx].score << endl;
    }
    return 0;
}
