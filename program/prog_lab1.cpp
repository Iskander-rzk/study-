#include <iostream>
#include <string>
using namespace std;

//По значению:

string convertToBase(int num, int base) {
    string res = "";
    while (num > 0) {
        int rem = num % base;
        res = to_string(rem) + res;
        num /= base;
    }
    return res;
}

int main() {
    int num, base;
    cout << "Enter the decimal number: ";
    cin >> num;
    cout << "Enter the base of the new number system: ";
    cin >> base;
    cout << "The number " << num << " in base " << base << " is " << convertToBase(num, base) << endl;
    return 0;
}


//По ссылке:
/*/
void convertToBase(int num, int base, string& res) {
    while (num > 0) {
        int rem = num % base;
        res = to_string(rem) + res;
        num /= base;
    }
}

int main() {
    int num, base;
    string result = "";
    cout << "Enter the decimal number: ";
    cin >> num;
    cout << "Enter the base of the new number system: ";
    cin >> base;
    convertToBase(num, base, result);
    cout << "The number " << num << " in base " << base << " is " << result << endl;
    return 0;
}


//Через указатель:

void convertToBase(int num, int base, string* res) {
    while (num > 0) {
        int rem = num % base;
        *res = to_string(rem) + *res;
        num /= base;
    }
}

int main() {
    int num, base;
    string result = "";
    cout << "Enter the decimal number: ";
    cin >> num;
    cout << "Enter the base of the new number system: ";
    cin >> base;
    convertToBase(num, base, &result);
    cout << "The number " << num << " in base " << base << " is " << result << endl;
    return 0;
}
//*/ 