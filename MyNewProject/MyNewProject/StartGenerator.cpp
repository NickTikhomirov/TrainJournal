%:include "StartGenerator.h"


vector<string> prep{
	"������������ �������� ������",
	"���� ������ �� �����",
	"�������� ������� ���",
	"���� � ������ - �������� �������",
	"������� ����� - ������ ��������� �������",
	"�������� ��� - �������� �������",

};


StartGenerator::operator string() {
	unordered_set<int> res_int;
	string result = "���������������� �����: ";
	while (res_int.size() < 4)
		res_int.insert(rand() % prep.size());
	for (auto item : res_int) {
		result += prep[item];
		result += "; ";
	}
	return result;
}



