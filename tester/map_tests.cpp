
#include "ft_containers.hpp"

// template < class Key, class T >
// void	print_map(LIB::map<Key,T> &map)
// {
// 	for (typename LIB::map<Key,T>::iterator it = map.begin(); it != map.end(); it++)
// 	{
// 		if (it != map.begin())
// 			std::cout << " ,";
// 		std::cout << "map[" << (*it).first << "] = " << (*it).second ;
// 	}
// 	std::cout << std::endl;
// }

void	map_tests(void)
{
	LIB::map<char, std::string>	map;

	// std::cout << "map.empty() = " << map.empty() << std::endl;
	map['b'] = "snake";
	map['k'] = "piano";
	map['f'] = "koala";
	map['a'] = "yoyo";
	map['z'] = "nounours";
	map['c'] = "nounours";
	map._tree.printTree(20, 6);
	//print_map(map);
	// std::cout << "map['a'] is " << map['a'] << std::endl;
	// std::cout << "map['k'] is " << map['k'] << std::endl;
	// std::cout << "map['f'] is " << map['f'] << std::endl;
	// std::cout << "map['b'] is " << map['b'] << std::endl;
	// std::cout << "map['-'] is " << map['-'] << std::endl;

	// std::cout << "map.empty() = " << map.empty() << std::endl;
	// LIB::pair<char, std::string> pair('b', "cowboy");
	// LIB::pair<LIB::map<char, std::string>::iterator, bool> ret;
	// ret = map.insert(pair);
	// std::cout << "map.insert (doesn't exist) -> <" << (*(ret.first)).first << ", " << ret.second << ">" << std::endl;
	// ret = map.insert(LIB::make_pair('b', "ratchet"));
	// std::cout << "map.insert (exists) -> <" << (*(ret.first)).first << ", " << ret.second << ">" << std::endl;
	// print_map(map);
	// map.erase(map.begin());
	// std::cout << "map.erase(begin)" << std::endl;
	// print_map(map);
	// LIB::map<char, std::string>::iterator	itb = map.begin();
	// itb++;
	// std::cout << "map.erase(begin+1,begin+3)" << std::endl;
	// print_map(map);
	// LIB::map<char, std::string>::iterator	ite = map.begin();
	// ite++;
	// ite++;
	// ite++;
	// map.erase(itb,ite);
	// LIB::map<char, std::string>	map2;
	// map2.insert(LIB::make_pair('y',"Dupleix"));
	// map2.insert(LIB::make_pair('o',"Kiwi"));
	// print_map(map);
	// print_map(map2);
	// map2.swap(map);
	// print_map(map);
	// print_map(map2);
	// std::cout << "map.clear()" << std::endl;
	// map2.clear();
	// print_map(map2);
	// print_map(map);
	// std::cout << "map.count('o') = " << map.count('o') << std::endl;
	// std::cout << "map.count('a') = " << map.count('a') << std::endl;
	// map['l'] = "lolipop";
	// map['p'] = "platypus";
	// map['a'] = "fried eggs";
	// print_map(map);
	// std::cout << "map.lower_bound('l') = " << map.lower_bound('l')->first << std::endl;
	// std::cout << "map.lower_bound('k') = " << map.lower_bound('k')->first << std::endl;
	// std::cout << "map.upper_bound('l') = " << map.upper_bound('l')->first << std::endl;
	// std::cout << "map.upper_bound('k') = " << map.upper_bound('k')->first << std::endl;

}