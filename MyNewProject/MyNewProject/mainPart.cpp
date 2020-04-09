#include "mainPart.h"

std::vector<std::string> Exercises = {
"������� ���������", "��������� ��������",
"������� ���������", "����-�������",
"���������� ��� ����� ���� ������",
"����������", "�������� ���� � ����� ����",
"������� ���������"
};

std::string mainPart::operator()() {
	std::string result = "\n�������� �����\n";
	std::unordered_set<int> exe;
	for (size_t i = 0; i < 4; ++i)
		exe.insert(rand() % (Exercises.size()));
	for (auto i : exe) {
		result += Exercises[i];
		result += "\n" + std::to_string(15 + rand() % 10) + " ��� �� " + std::to_string(2 + rand() % 2) + " �������\n";
	}
	return result;
}
