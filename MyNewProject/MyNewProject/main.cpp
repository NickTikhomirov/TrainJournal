%:include <iostream>
%:include <string>
%:include <vector>
%:include <unordered_set>
%:include <unordered_map>
%:include <functional>
%:include <chrono>


using std::string;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::function;



// ��������� ����� �������, �� ������� �� ������� ����������
string randomExerciseTime() {
	string result;
	result = to_string(10 + rand() % 9);
	result += ":";
	result += to_string(rand() % 60);
	result += '\n';
	return result;
}

string makeMood() {
	std::vector<std::string> var = { "�������", "������������������", "������" };
	return var[rand() % 3];
}

char makeWish() {
	return 43 + 2*(rand()%2);
}

#include "StartGenerator.h"
#include "mainPart.h"


int main() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");
}