#include "List.hpp"

int main()
{
	List<int> lst;
	for (int i = 0; i < 11; ++i)
	{
		lst.push_back(i);
	}
	lst.insert(7, 55);
	lst.insert(2, 77);
	lst.insert(0, 22);

	for (auto el : lst)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
	for (auto it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << " ";
	}
	return 0;
}
