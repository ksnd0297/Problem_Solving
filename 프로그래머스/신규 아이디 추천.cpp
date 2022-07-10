#include <iostream>
#include <string>

using namespace std;

string one(string& id) {
	for (int i = 0; i < id.size(); i++) {
		if (id[i] >= 65 && id[i] <= 90) id[i] = id[i] + 32;
	}
	return id;
}

string two(string& id) {
	string temp;
	for (int i = 0; i < id.size(); i++) {
		if ((id[i] >= 97 && id[i] <= 122) || (id[i] - '0' >= 0 && id[i] - '0' <= 9) || id[i] == '-' || id[i] == '_' || id[i] == '.')
			temp += id[i];
	}
	return temp;
}

string three(string& id) {
	string temp;
	for (int i = 0; i < id.size(); i++) {
		if (id[i] == '.') {
			int index = i;
			while (id[index] == '.') index++;
			temp += '.'; i = index - 1;
		}
		else temp += id[i];
	}
	return temp;
}

string four(string& id) {
	string temp;
	for (int i = 0; i < id.size(); i++) {
		if (i == 0 && id[i] == '.') continue;
		else if (i == id.size() - 1 && id[i] == '.') continue;
		else temp += id[i];
	}
	return temp;
}

string five(string& id) {
	if (id.size() == 0) id += 'a';
	return id;
}

string six(string& id) {
	string temp;
	if (id.size() >= 16) {
		for (int i = 0; i < 15; i++) temp += id[i];
		temp = four(temp);
		return temp;
	}
	else return id;
}

string seven(string& id) {
	if (id.size() <= 2) {
		char rep = id[id.size() - 1];
		while (id.size() < 3)  id += rep;
	}
	return id;
}

string recommand(string& id) {
	id = one(id);
	id = two(id);
	id = three(id);
	id = four(id);
	id = five(id);
	id = six(id);
	id = seven(id);
	return id;
}

string solution(string new_id) {
	return recommand(new_id);
}