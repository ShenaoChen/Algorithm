class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> weeks = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int cnt = 0;
        cnt += 365 * (year - 1971) + (year - 1969) / 4;
        for(int i = 0; i < month - 1; i++)
            cnt += months[i];
        if(month > 2 && (year % 400 == 0 || year % 4 == 0 && year % 100 != 0))
            cnt++;
        cnt += day;
        return weeks[(cnt + 4) % 7];
    }
};
