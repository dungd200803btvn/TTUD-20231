#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<map>
using namespace std;

int getDuration(string s, string e) {
	int start = ((s[0]-'0')*10 + (s[1]-'0'))*3600 + ((s[3]-'0')*10 + (s[4]-'0'))*60 + ((s[6]-'0')*10 + (s[7]-'0'));
	int end = ((e[0]-'0')*10 + (e[1]-'0'))*3600 + ((e[3]-'0')*10 + (e[4]-'0'))*60 + ((e[6]-'0')*10 + (e[7]-'0'));
	return end - start;
}

int checkNumber(string number) {
	if (number.length() != 10) return 0;
	for (int i=0; i<10; i++) {
		if (!isdigit(number[i])) return 0;
	}
	return 1;
}

int main() {
	string fromNumber, toNumber;
	string date;
	string fromTime, toTime;
	map <string, int> callCount;
	map <string, int> durationCount;
	int count = 0;
	int validNumbers = 1;
	
	string input;
	cin >> input;
	do {
		count++;
		cin >> fromNumber >> toNumber >> date >> fromTime >> toTime;
		validNumbers = validNumbers && checkNumber(fromNumber) && checkNumber(toNumber);
		callCount[fromNumber] += 1;
		durationCount[fromNumber] += getDuration(fromTime, toTime);
		cin >> input;
	} while (input != "#");
	
	cin >> input;
	do {
		if (input=="#") break;
		
		if (input == "?check_phone_number") {
			cout << validNumbers << endl;
		} else if (input == "?number_calls_from") {
			string number; cin >> number;
			cout << callCount[number] << endl;
		} else if (input == "?number_total_calls") {
			cout << count << endl;
		} else {
			string number; cin >> number;
			cout << durationCount[number] << endl;
		}
		cin >> input;
	} while (input != "#");
	
	return 0;
}
