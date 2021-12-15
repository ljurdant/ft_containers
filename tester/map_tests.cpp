
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
	typename LIB::map<Key, T>::iterator it;
	it = map.begin();
	for (typename LIB::map<Key,T>::size_type i = 0; i < pos; i++)
		it++;
	map.erase(it);
}

template < class Key, class T >
void	deletekeys(LIB::map<Key,T> &map, typename LIB::map<Key,T>::size_type pos1, typename LIB::map<Key,T>::size_type pos2)
{
	typename LIB::map<Key, T>::iterator first;
	first = map.begin();
	for (typename LIB::map<Key,T>::size_type i = 0; i < pos1; i++)
		first++;
	typename LIB::map<Key, T>::iterator last;
	last = map.begin();
	for (typename LIB::map<Key,T>::size_type i = 0; i < pos2; i++)
		last++;
	map.erase(first, last);
}

void	map_tests(void)
{
	typedef	char		key_type;
	typedef	std::string	mapped_type;
	LIB::map<key_type, mapped_type>	map;

	// std::cout << "map.empty() = " << map.empty() << std::endl;
	map['b'] = "banana";
	map['k'] = "koala";
	// map._tree.printTree(20, 8);
	map['f'] = "fresco";
	// map._tree.printTree(20, 8);
	map['a'] = "Ali Baba";
	// map._tree.printTree(20, 8);
	map['z'] = "zephyr";
	// map._tree.printTree(20, 8);
	map['c'] = "cheddar";
	map['d'] = "diamond";
	map['e'] = "erratic";
	map['p'] = "peppermint";
	// map._tree.printTree(30, 9);
	print_map(map);
	print_map_reverse(map);
	deletekey(map, 6);
	print_map(map);
	deletekeys(map, 3, 8);
	print_map(map);
	
	LIB::pair<LIB::map<key_type, mapped_type>::iterator, bool>	b_pair;
	LIB::map<key_type, mapped_type>::iterator					it = map.begin();

	b_pair  = map.insert(LIB::make_pair<key_type, mapped_type>('i', "idiocracy"));
	std::cout << "insert(i for banana) = [(" << (*(b_pair.first)).first <<  ", " << (*(b_pair.first)).second << "), " << b_pair.second << "]" << std::endl;
	print_map(map);
	it = map.insert(it, LIB::make_pair<key_type, mapped_type>('h', "Hercules"));
	std::cout << "insert(begin, h for Hercules) = (" << (*it).first << ", " << (*it).second << ")" << std::endl;
	print_map(map);

	LIB::map<key_type, mapped_type>	map2;

	map2['v'] = "vortex";
	map2['o'] = "out of the box";
	map.insert(map2.begin(), map2.end());
	print_map(map);
	std::cout << "empty? : " << map.empty() << std::endl;
	std::cout << "size = " << map.size() << std::endl;
	
	LIB::map<key_type, mapped_type>	map3(map2);
	
	map2 = map;
	print_map(map2);
	print_map(map3);
	map3.swap(map2);
	print_map(map2);
	print_map(map3);
	std::cout << "count(k) = " << map.count('k') << std::endl;
	std::cout << "count(v) = " << map.count('v') << std::endl;

}