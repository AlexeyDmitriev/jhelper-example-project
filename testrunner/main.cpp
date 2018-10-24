#include "../tasks/uva/FractionsAgain.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

namespace jhelper {

struct Test {
	std::string input;
	std::string output;
	bool active;
	bool has_output;
};

bool check(std::string expected, std::string actual) {
	while(!expected.empty() && isspace(*--expected.end()))
		expected.erase(--expected.end());
	while(!actual.empty() && isspace(*--actual.end()))
		actual.erase(--actual.end());
	return expected == actual;
}

} // namespace jhelper

int main() {
	std::vector<jhelper::Test> tests = {
		{"12\n2\n", "8\n1/12 = 1/156 + 1/13\n1/12 = 1/84 + 1/14\n1/12 = 1/60 + 1/15\n1/12 = 1/48 + 1/16\n1/12 = 1/36 + 1/18\n1/12 = 1/30 + 1/20\n1/12 = 1/28 + 1/21\n1/12 = 1/24 + 1/24\n2\n1/2 = 1/6 + 1/3\n1/2 = 1/4 + 1/4\n", true, true},
	};
	bool allOK = true;
	int testID = 0;
	std::cout << std::fixed;
	double maxTime = 0.0;
	for(const jhelper::Test& test: tests ) {
		std::cout << "Test #" << ++testID << std::endl;
		std::cout << "Input: \n" << test.input << std::endl;
		if (test.has_output) {
			std::cout << "Expected output: \n" << test.output << std::endl;
		}
		else {
			std::cout << "Expected output: \n" << "N/A" << std::endl;
		}
		if (test.active) {
			std::stringstream in(test.input);
			std::ostringstream out;
			std::clock_t start = std::clock();
			FractionsAgain solver;
			solver.solve(in, out);
			std::clock_t finish = std::clock();
			double currentTime = double(finish - start) / CLOCKS_PER_SEC;
			maxTime = std::max(currentTime, maxTime);
			std::cout << "Actual output: \n" << out.str() << std::endl;
			if (test.has_output) {
				bool result = jhelper::check(test.output, out.str());
				allOK = allOK && result;
				std::cout << "Result: " << (result ? "OK" : "Wrong answer") << std::endl;
			}
			std::cout << "Time: " << currentTime << std::endl;
		}
		else {
			std::cout << "SKIPPED\n";
		}

		std::cout << std::endl;

	}
	if(allOK) {
		std::cout << "All OK" << std::endl;
	}
	else {
		std::cout << "Some cases failed" << std::endl;
	}
	std::cout << "Maximal time: " << maxTime << "s." << std::endl;
	return 0;
}
