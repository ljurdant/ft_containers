
#ifndef FT_CONTAINERS_H
# define FT_CONTAINERS_H

# include "../srcs/vector.hpp"
# include "../srcs/stack.hpp"
# include "../srcs/map.hpp"
# include "../srcs/set.hpp"

# include <vector>
# include <map>
# include <stack>
# include <fstream>
# include <iostream>
#include <typeinfo>


#ifndef LIB
# define LIB ft
#endif


void	vector_tests();
void	map_tests();
void	stack_tests();

#endif