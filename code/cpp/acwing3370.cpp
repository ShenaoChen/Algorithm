#include <iostream>
#include <unordered_map>

using namespace std;

typedef pair<int, int> PII;

string strs[] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
string sentence[8];
unordered_map<string, int> m;
unordered_map<string, PII> record;

int main() {
    for(int i = 0; i < 12; i++)
        m[strs[i]] = i;
    int n;
    cin >> n;
    record["Bessie"] = {0, 0};
    while(n--){
        for(int i = 0; i < 8; i++)
            cin >> sentence[i];
        string x = sentence[0], y = sentence[7];
        int age;
        if(sentence[3] == "next")
            age = record[y].second + ((m[sentence[4]] - record[y].first + 12 - 1) % 12 + 1) ;
        else
            age = record[y].second - ((record[y].first - m[sentence[4]] + 12 - 1) % 12 + 1) ;
        record[x] = {m[sentence[4]], age};
    }
    cout << abs(record["Elsie"].second) << endl;   
    return 0;
}