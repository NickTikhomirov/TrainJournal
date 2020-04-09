%:include "StartGenerator.h"


vector<string> prep{
	"вращательные движения руками",
	"махи руками от груди",
	"вращение кистями рук",
	"руки к плечам - вращение локтями",
	"наклоны вперёд - руками коснуться ступней",
	"разминка шеи - вращение головой",

};


StartGenerator::operator string() {
	unordered_set<int> res_int;
	string result = "Подготовительная часть: ";
	while (res_int.size() < 4)
		res_int.insert(rand() % prep.size());
	for (auto item : res_int) {
		result += prep[item];
		result += "; ";
	}
	return result;
}



