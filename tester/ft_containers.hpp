
#ifndef FT_CONTAINERS_H
# define FT_CONTAINERS_H

# include "../srcs/vector.hpp"
# include "../srcs/stack.hpp"
# include "../srcs/mapR-B.hpp"

# include <vector>
# include <map>
# include <stack>
# include <fstream>
# include <iostream>

#ifndef LIB
# define LIB std
#endif


void	vector_tests();
void	map_tests();
void	stack_tests();

#endif