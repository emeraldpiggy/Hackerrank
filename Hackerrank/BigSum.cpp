#include "stdafx.h"
#include "BigSum.h"
#include <ostream>
#include <iostream>
#include <vector>


int BigSum()
{
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	long long sum = 0;
	for (int arr_i = 0;arr_i < n;arr_i++) {
		std::cin >> arr[arr_i];
		sum += arr[arr_i];
	}

	std::cout << sum << std::endl;
	return 0;
}

