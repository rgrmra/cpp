#include "PmergeMe.hpp"
#include <deque>
#include <utility>

void PmergeMe::dequeMerge(void) {

	size_t pair = level * 2;

	if (pair > _deque.size())
		return;

	for (size_t i = pair - 1; i < _deque.size(); i += pair) {

		if (_deque[i - level] <= _deque[i])
			continue;

		size_t a = i + 1 - pair;
		size_t b = i + 1 - level;

		std::deque<int>::iterator it = _deque.begin();
		std::swap_ranges(it + a, it + b, it + b);
	}

	level *= 2;
	dequeMerge();

	level /= 2;
	dequeInsert();
}

std::deque<int>::iterator PmergeMe::dequeBinarySearch(std::deque<int> &main,
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

void PmergeMe::dequeInsertions(std::deque<int> &main, const size_t &index) {

	if (main.size() >= _deque.size() / level * level)
		return;

	std::pair<int, int> jacobsthal = jacobSthal(index);
	size_t inserts = jacobsthal.second - jacobsthal.first;

	size_t actual_b = jacobsthal.second + 1;
	for (int i = inserts; i > 0; --i) {

		actual_b--;
		
		size_t j = (actual_b * 2 - 1) * level - 1;
		if (j >= _deque.size())
			continue;

		std::deque<int>::iterator mit;
		std::deque<int>::iterator it = _deque.begin();

		size_t total_as = _deque.size() / 2 / level;
		size_t ignore = total_as - actual_b + 1;
		size_t limit = main.size() - ignore;

		mit = dequeBinarySearch(main, _deque[j], limit);
		main.insert(mit, it + j - level + 1, it + j + 1);
	}

	dequeInsertions(main, index + 1);
}

void PmergeMe::dequeInsert(void) {

	std::deque<int> main;
	std::deque<int>::iterator it = _deque.begin();
	size_t pair = level * 2;
	size_t size = _deque.size() / level * level;

	main.insert(main.end(), _deque.begin(), _deque.begin() + pair);

	for (size_t i = pair * 2 - 1; i < _deque.size(); i += pair)
		main.insert(main.end(), it + i + 1 - level, it + i + 1);

	dequeInsertions(main, 3);

	main.insert(main.end(), _deque.begin() + size, _deque.end());

	_deque = main;
}
