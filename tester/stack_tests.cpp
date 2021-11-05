
#include "ft_containers.hpp"

template <typename T, class Container >
	void	print_stack(LIB::stack<T,Container>	stack)
	{
		for (typename LIB::stack<T,Container>::size_type i = 0; i < stack.size();)
		{
			if (stack.size() != 1)
				std::cout << " ,";
			std::cout << stack.top();
			stack.pop();
		}
		std::cout << std::endl;
	}	

void	stack_tests() {
	LIB::stack<int>						stackdq;
	LIB::vector<int>					vector(3,89);
	LIB::stack<int,LIB::vector<int> >	stackv(vector);

	std::cout << "stackdq.empty() = " << stackdq.empty() << std::endl;
	std::cout << "stackv.empty() = " << stackv.empty() << std::endl;
	std::cout << "stackdq.size() = " << stackdq.size() << std::endl;
	std::cout << "stackv.size() = " << stackv.size() << std::endl;
	std::cout << "stackdq.top() = " << stackdq.top() << std::endl;
	std::cout << "stackv.top() = " << stackv.top() << std::endl;
	std::cout << "push" << std::endl;
	stackdq.push(6);
	stackv.push(7);
	print_stack(stackdq);
	print_stack(stackv);
	LIB::vector<int>					vector2(3,89);
	LIB::stack<int, LIB::vector<int> >	stackv2(vector2);
	std::cout << "stackv == stackv2 -> " << (stackv == stackv2) << std::endl;
	std::cout << "stackv != stackv2 -> " << (stackv != stackv2) << std::endl;
	std::cout << "stackv < stackv2 -> " << (stackv < stackv2) << std::endl;
	std::cout << "stackv <= stackv2 -> " << (stackv <= stackv2) << std::endl;
	std::cout << "stackv > stackv2 -> " << (stackv > stackv2) << std::endl;
	std::cout << "stackv >= stackv2 -> " << (stackv >= stackv2) << std::endl;

}