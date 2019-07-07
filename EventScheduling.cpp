#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b) {
	return (a.second < b.second);
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> eventList;
	pair<int, int> temp;
	for (int i = 0; i < n; i++) {
		cin >> temp.first >> temp.second;
		temp.second = temp.first + temp.second - 1;
		eventList.push_back(temp);
	}
	sort(eventList.begin(), eventList.end(), comparator);
//	for (int i = 0; i < n; i++) {
//		cout << eventList.at(i).first << " " << eventList.at(i).second << endl;
//	}
	int count = 1, prevEvent = 0;
	for (int i = 1; i < n; i++) {
		if (eventList.at(i).first > eventList.at(prevEvent).second){
			count++;
			prevEvent = i;
		}
	}
	cout << count << endl;
	return 0;
}
