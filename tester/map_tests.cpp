
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
	typename LIB::map<Key,T>::iterator begin = map.begin();
	while (it != begin)
	{
		
		std::cout << "map[" << (*it).first << "] = " << (*it).second ;
		std::cout << ", ";
		it--;
	}
	std::cout << "map[" << (*it).first << "] = " << (*it).second ;
	std::cout << std::endl;
}

template < class Key, class T >
void	deletekey(LIB::map<Key,T> &map, typename LIB::map<Key,T>::size_type pos)
{
	ft::map<char, std::string>::iterator it;
	it = map.begin();
	for (typename LIB::map<Key,T>::size_type i = 0; i < pos; i++)
		it++;
	map.erase(it);
}

template < class Key, class T >
void	deletekeys(LIB::map<Key,T> &map, typename LIB::map<Key,T>::size_type pos1, typename LIB::map<Key,T>::size_type pos2)
{
	ft::map<char, std::string>::iterator first;
	first = map.begin();
	for (typename LIB::map<Key,T>::size_type i = 0; i < pos1; i++)
		first++;
	ft::map<char, std::string>::iterator last;
	last = map.begin();
	for (typename LIB::map<Key,T>::size_type i = 0; i < pos2; i++)
		last++;
	map.erase(first, last);
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
	// map['p'] = "peppermint";
	map._tree.printTree(20, 9);
	print_map(map);
	print_map_reverse(map);
	deletekey(map, 6);
	// print_map(map);
	map._tree.printTree(20, 9);
	// deletekeys(map, 3, 6);
	// map._tree.printTree(20, 9);
}