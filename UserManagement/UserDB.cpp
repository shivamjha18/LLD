#include<bits/stdc++.h>
using namespace std;

class UserDB {
private:
    UserDB() {

    }
    static UserDB* instance; // Static member variable to hold the singleton instance
public:
    static UserDB* getInstance() {
        if (!instance) {
            instance = new UserDB(); // Create a new instance if it doesn't exist
        }
        return instance;
    }
    map<string, string> mp; // Map to store usernames and passwords
    void AddUser(string name, string pass) {
        if (mp.find(name) == mp.end()) {
            mp[name] = pass;
            cout << "userName: " << name << " Pass " << pass << endl;
        }
        else {
            cout << "user already exists" << endl;
        }
    }
    void RemoveUser(string name) {
        if (mp.find(name) != mp.end()) {
            mp[name] = "NotFound";
            cout << "userName: " << name << " has been deleted " << endl;
        }
        else {
            cout << "user doesn't exist" << endl;
        }
    }
    // Deleting instances when the program ends
    static void CleanUp() {
        if (instance) {
            delete instance; // Delete the instance if it exists
            instance = nullptr;
        }
    }
};

// Definition of the static member variable
UserDB* UserDB::instance = nullptr;

int main() {
    UserDB* userdb = UserDB::getInstance();
    userdb->AddUser("shivam", "123");
    userdb->AddUser("alankrit", "1234");
    userdb->RemoveUser("alankrit");

    // Clean up before the program ends
    UserDB::CleanUp();
}
