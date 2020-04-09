#include "mainPart.h"

std::vector<std::string> Exercises = {
"Простые отжимания", "Отжимания наоборот",
"Боковые отжимания", "Песс-бабочка",
"Упражнение для косых мышц живота",
"Приседания", "Поднятие таза и одной ноги",
"Сложные отжимания"
};

std::string mainPart::operator()() {
	std::string result = "\nОсновная часть\n";
	std::unordered_set<int> exe;
	for (size_t i = 0; i < 4; ++i)
		exe.insert(rand() % (Exercises.size()));
	for (auto i : exe) {
		result += Exercises[i];
		result += "\n" + std::to_string(15 + rand() % 10) + " раз по " + std::to_string(2 + rand() % 2) + " подхода\n";
	}
	return result;
}
