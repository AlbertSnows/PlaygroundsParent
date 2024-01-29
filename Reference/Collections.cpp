#include <vector>
#include <numeric>
using namespace std;
vector<int> range(const int& end, const int& start = 0, const int& step_size = 1) {
	int slots_needed = (end - start + step_size - 1) / step_size;
	auto list = vector<int>(slots_needed);
	iota(list.begin(), list.end(), start);
	return list;
}
