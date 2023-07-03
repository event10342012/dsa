#include <iostream>
#include <vector>
#include <set>

using namespace std;

class UniqueEmailAddress {
public:
    int numUniqueEmails(vector<string> &emails) {
        set<string> validEmails;
        for (const string &email: emails) {
            validEmails.insert(parseEmail(email));
        }
        return validEmails.size();
    }

private:
    string parseEmail(const string &email) {
        bool plus_sign{false};
        bool at_sign(false);
        string result;
        for (char c: email) {
            if (at_sign || c == '@') {
                at_sign = true;
                result.push_back(c);
                continue;
            }
            if (plus_sign || c == '+') {
                plus_sign = true;
                continue;
            }
            if (c == '.') {
                continue;
            }
            result.push_back(c);
        }
        cout << result << endl;
        return result;
    }
};

