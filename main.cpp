#include "include/ConsoleBarChart.h"

using namespace aarsoftx;

int main(int argc, char **argv){
	vector<ConsoleChartData> result;
	
	result.push_back({"Abtahi", 5000});	
	result.push_back({"Ehsan", 8000});
	result.push_back({"Anik", 10500});
	result.push_back({"Tisha", 3500});

	ConsoleBarChart *cbc = new ConsoleBarChart("Monthly Salary", 3, 500, result);
	
	cbc->insert("Jannat" , 6000);

	cbc->show();
	

	return 0;
}
