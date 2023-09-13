#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class PasswordGenerator {
private:
    int length;
    string allchar;

public:
    PasswordGenerator(int len, bool uppercase = true, bool lowercase = true, bool digits = true, bool specialchars = true)
        : length(len) {
        srand(time(0));
        if (uppercase) {
            allchar += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        }
        if (lowercase) {
            allchar += "abcdefghijklmnopqrstuvwxyz";
        }
        if (digits) {
            allchar += "0123456789";
        }
        if (specialchars) {
            allchar += "*!@#$%^&";
        }
    }

    string generate() {
        string password;
        int random;

        for (int i = 0; i < length; i++) {
            random = rand() % allchar.length();
            password += allchar[random];
        }
        return password;
    }
};

bool isValidChoice(char choice) {
    return choice == '0' || choice == '1';
}

bool getChoice(const string& message) {
    char choice;
    do {
        cout << message << " (1 for Yes and 0 for No): ";
        cin >> choice;
    } while (!isValidChoice(choice));
    return choice == '1';
}

int getPositiveInt(const string& message) {
    int value;
    do {
        cout << message;
        while (!(cin >> value) || value <= 0) {
            cout << "Invalid input. Please enter a positive integer: ";
            cin.clear();        }
    } while (false);
    return value;
}

int main() {
    cout << "*** RANDOM PASSWORD GENERATOR ***" << endl;
    
    int length = getPositiveInt("Enter desired password length: ");
    bool uppercase = getChoice("Include Uppercase Letters?");
    bool lowercase = getChoice("Include Lowercase Letters?");
    bool digits = getChoice("Include Digits?");
    bool specialchars = getChoice("Include Special Characters?");
    
    PasswordGenerator generator(length, uppercase, lowercase, digits, specialchars);
    string password = generator.generate();
    
    cout << "Generated Password: " << password << endl;
    
    return 0;
}

