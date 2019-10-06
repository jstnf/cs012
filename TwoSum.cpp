#include <vector>
using namespace std;

vector<int> twosum(const vector<int> &, int);

int main() {
    return 0;
}

vector<int> twosum(const vector<int> &nums, int target) { // [2,7,11,15] 9
    for (unsigned i = 0; i < nums.size(); ++i) {
        for (unsigned j = i + 1; j < nums.size(); ++j) {
            if (nums.at(i) + nums.at(j) == target) {
                return {i, j};
            }
        }
    }
    return {};
}