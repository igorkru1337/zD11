#include <iostream>
#include <map>

using namespace std;

int countLowerCase(const string &a) {
    int c = 0;
    for (char i : a) {
        if ((i < 'A' or i > 'Z') and i != '=') {
            c++;
        }
    }
    return c;
}

int countUpperCase(const string &a) {
    int c = 0;
    for (char i : a) {
        if (i >= 'A' and i <= 'Z') {
            c++;
        }
    }
    return c;
}

void createChains(string str, map<char, string *> mp, map<char, int> index, int d1, int d2) {
    if (countLowerCase(str) <= d2 and str.size() < d2) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' and str[i] <= 'Z') {
                string temp;
                for (int j = 0; j < index[str[i]]; j++) {
                    temp = str.substr(0, i) + mp[str[i]][j] + str.substr(i + 1, str.size() - 1);
                    cout << temp << " -> ";
                    createChains(temp, mp, index, d1, d2);
                    cout << "konechnaya" <<endl;
                }

                break;
            }
        }
    }
    if (countLowerCase(str) >= d1 and countLowerCase(str) <= d2 and countUpperCase(str) == 0) {
        for (char i : str) {
            //cout << i;
        }
        cout << endl;
    }

}

int main() {
    int rules, kom, leftBorder, rightBorder;
    char symbol;

    cout << "Input range(example: >> 0 5): ";
    cin >> leftBorder >> rightBorder;
    cout << "How many rules: ";
    cin >> rules;
    char pr[rules];
    map<char, string *> mp;
    map<char, int> index;

    for (int i = 0; i < rules; i++) {
        cin >> kom >> symbol;
        cout << symbol << " -> ";
        pr[i] = symbol;
        index[symbol] = kom;
        mp[symbol] = new string[kom];
        for (int j = 0; j < kom; j++) {
            cin >> mp[symbol][j];
        }
    }
    cout << endl;

    createChains("aSb", mp, index, leftBorder, rightBorder);
}
/*

2
3 S
aA bS =
3 A
cS dA =

3
3 S
-A A +A
2 A
B AB
3 B
a b c

2
2 S
A SA
3 A
a b c

*/