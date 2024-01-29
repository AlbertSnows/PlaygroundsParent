#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <ranges>
#include <numeric>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "shared_interest.h"
using namespace std;

void entry() {
	vector<tuple<int, int, int>> list_of_left_right_weight_friendship = {
		make_tuple(1, 2, 2),
		make_tuple(1, 2, 3),
		make_tuple(2, 3, 1),
		make_tuple(2, 3, 3),
		make_tuple(2, 4, 4) };
	string line;
	//while (getline(cin, line) && !line.empty()) {
	//	lines.push_back(line);
	//}

	auto weights = accumulate(list_of_left_right_weight_friendship.begin(), list_of_left_right_weight_friendship.end(), unordered_set<int>{},
		[](unordered_set<int> weights, auto coord_with_weight) {
			weights.insert(coord_with_weight[2]);
			return weights;
		});
	auto weight_to_nodes = accumulate(list_of_left_right_weight_friendship.begin(), list_of_left_right_weight_friendship.end(), 
		unordered_map<int, unordered_set<int>>{},
		[](unordered_map<int, unordered_set<int>> weight_to_nodes, auto coord_with_weights) {

			unordered_set<int> nodes_for_weight = weight_to_nodes[coord_with_weights[2]];
			nodes_for_weight.insert(coord_with_weights[2]);

			weight_to_nodes.emplace(coord_with_weights[2], nodes_for_weight);
			return weight_to_nodes;
		});
	auto coord_to_max_weight = unordered_map<pair<int, int>, int>{};
	for (auto weight_with_nodes : weight_to_nodes) {
		auto weight = weight_with_nodes.first;
		auto coords = weight_with_nodes.second;
		for (auto x : coords) {
			for (auto y : coords) {
				auto left_pair = make_pair(x, y);
				auto right_pair = make_pair(y, x);
				auto left_pair_exists = coord_to_max_weight.find(left_pair) != coord_to_max_weight.end();
				if (left_pair_exists) {
					coord_to_max_weight[left_pair] += weight;
				}
				else {
					coord_to_max_weight[left_pair] = weight;
				}
				auto right_pair_exists = coord_to_max_weight.find(right_pair) != coord_to_max_weight.end();
				if (right_pair_exists) {
					coord_to_max_weight[right_pair] += weight;
				}
				else {
					coord_to_max_weight[right_pair] = weight;
				}
			}
		}
	}
	auto max_weight_possible = accumulate(coord_to_max_weight.begin(), coord_to_max_weight.end(), 0, [](auto max, int curr) {
		return max(max, curr);
		});
	auto coords_with_max_weight_possible = unordered_map < pair<int, int>, int>{};
	for (auto pair : coord_to_max_weight) {
		if (pair.second == max_weight_possible) {
			coords_with_max_weight_possible.insert(pair);
		}
	}
	auto max_friend_score = 0;
	for (auto pair : coords_with_max_weight_possible) {
		max_friend_score = max(max_friend_score, pair.first.first + pair.first.second);
	}
	cout << max_friend_score << endl;
	//return max_friend_score;
}