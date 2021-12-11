
#include "ft_containers.hpp"

template < class Key, class T >
void	print_map(LIB::map<Key,T> &map)
{	
	// typename LIB::map<Key,T>::iterator it = map.begin();
	// it++;
	// std::cout << "map[" << (*it).first << "] = " << (*it).second ;
	for (typename LIB::map<Key,T>::iterator it = map.begin(); it != map.end(); it++)
	{
		if (it != map.begin())
			std::cout << " ,";
		std::cout << "map[" << (*it).first << "] = " << (*it).second ;
	}
	std::cout << std::endl;
}

template < class Key, class T >
void	print_map_reverse(LIB::map<Key,T> &map)
{	
	typename LIB::map<Key,T>::iterator it = map.end();
	it--;
	while (it != map.begin())
	{
		
		std::cout << "map[" << (*it).first << "] = " << (*it).second ;
		std::cout << ", ";
		it--;
	}
	std::cout << "map[" << (*it).first << "] = " << (*it).second ;
	std::cout << std::endl;
}

void	map_tests(void)
{
	LIB::map<char, std::string>	map;

	// std::cout << "map.empty() = " << map.empty() << std::endl;
	map['b'] = "snake";
	map['k'] = "piano";
	// map._tree.printTree(20, 8);
	map['f'] = "koala";
	// map._tree.printTree(20, 8);
	map['a'] = "yoyo";
	// map._tree.printTree(20, 8);
	map['z'] = "nounours";
	// map._tree.printTree(20, 8);
	map['c'] = "pantatonic";
	map['d'] = "cheddar";
	map['e'] = "castle";
	map._tree.printTree(20, 9);
	print_map(map);
	print_map_reverse(map);
	ft::map<char, std::string>::iterator it;
	it = map.begin();
	for (int i = 0; i < 3; i++)
		it++;
	map.erase(it);
	map._tree.printTree(20, 9);

}