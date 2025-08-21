#include "PmergeMe.hpp"
#include <vector>
#include <utility>

void PmergeMe::vectorMerge(void) {

	size_t pair = level * 2;

	if (pair > _vector.size())
		return;

	for (size_t i = pair - 1; i < _vector.size(); i += pair) {

		if (_vector[i - level] <= _vector[i])
			continue;

		size_t a = i + 1 - pair;
		size_t b = i + 1 - level;

		std::vector<int>::iterator it = _vector.begin();
		std::swap_ranges(it + a, it + b, it + b);
	}

	level *= 2;
	vectorMerge();

	level /= 2;
	vectorInsert();
}

std::vector<int>::iterator PmergeMe::vectorBinarySearch(std::vector<int> &main,
		const int &target, const size_t &length) {

	size_t low = 0;
	size_t high = length / level - 1;
	size_t pos = 0;

	while (low <= high) {
		size_t mid = low + (high - low) / 2;
		if (mid > length)
			return main.begin();
		
		pos = (mid == 0) ? level - 1 : mid * level - 1;
		if (main[pos] == target)
			return main.begin() + (mid * level);

		if (main[pos] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}

	if (main[pos + level] < target)
		return main.begin() + (low * level);

	return main.begin() + (low * level - level);
}

void PmergeMe::vectorInsertions(std::vector<int> &main, const size_t &index) {

	if (main.size() >= _vector.size() / level * level)
		return;

	std::pair<int, int> jacobsthal = jacobSthal(index);
	size_t inserts = jacobsthal.second - jacobsthal.first;

	size_t actual_b = jacobsthal.second + 1;
	for (int i = inserts; i > 0; --i) {

		actual_b--;
		
		size_t j = (actual_b * 2 - 1) * level - 1;
		if (j >= _vector.size())
			continue;

		std::vector<int>::iterator mit;
		std::vector<int>::iterator it = _vector.begin();

		size_t total_as = _vector.size() / 2 / level;
		size_t ignore = total_as - actual_b + 1;
		size_t limit = main.size() - ignore;

		mit = vectorBinarySearch(main, _vector[j], limit);
		main.insert(mit, it + j - level + 1, it + j + 1);
	}

	vectorInsertions(main, index + 1);
}

void PmergeMe::vectorInsert(void) {

	std::vector<int> main;
	std::vector<int>::iterator it = _vector.begin();
	size_t pair = level * 2;
	size_t size = _vector.size() / level * level;

	main.insert(main.end(), _vector.begin(), _vector.begin() + pair);

	for (size_t i = pair * 2 - 1; i < _vector.size(); i += pair)
		main.insert(main.end(), it + i + 1 - level, it + i + 1);

	vectorInsertions(main, 3);

	main.insert(main.end(), _vector.begin() + size, _vector.end());

	_vector = main;
}
