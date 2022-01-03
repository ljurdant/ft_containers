
#include "ft_containers.hpp"

template <typename T>
void	print_vector(LIB::vector<T> &vector)
{
	for (typename LIB::vector<T>::size_type i = 0; i < vector.size(); i++)
	{
		std::cout << "vector[" << i << "] = " << vector[i] ;
		if (i != vector.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

template <typename T, class Container >
	void	print_stack(LIB::stack<T,Container>	stack)
	{
		for (typename LIB::stack<T,Container>::size_type i = 0; i < stack.size();)
		{
			std::cout << stack.top();
			stack.pop();
			if (stack.size() >= 1)
				std::cout << " ,";
		}
		std::cout << std::endl;
	}	

void	stack_tests() {
	LIB::stack<int>						stackdq;
	LIB::vector<int>					vector(3,89);
	LIB::stack<int, LIB::vector<int> >	stackv(vector);
	LIB::vector<int>					ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	print_vector(ctnr);
	LIB::stack<int, LIB::vector<int> >		stck(ctnr);

	print_stack(stck);
	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);
	stck.push(5);
	stck.push(6);
	print_stack(stck);

	std::cout << "stackdq.empty() = " << stackdq.empty() << std::endl;
	std::cout << "stackv.empty() = " << stackv.empty() << std::endl;
	std::cout << "stackdq.size() = " << stackdq.size() << std::endl;
	std::cout << "stackv.size() = " << stackv.size() << std::endl;
	std::cout << "stackv.top() = " << stackv.top() << std::endl;
	std::cout << "push" << std::endl;
	stackdq.push(6);
	stackv.push(7);
	print_stack(stackdq);
	print_stack(stackv);
	LIB::vector<int>					vector2(3,89);
	LIB::stack<int, LIB::vector<int> >	stackv2(vector2);
	// stackv2.push(8);
	LIB::stack<int, LIB::vector<int> >	stackv3(vector2);
	// stackv3.push(8);
	std::cout << "HELLLLLLLLLOOOOOOOOOOOOOOOO" << std::endl;
	print_stack(stackv);
	print_stack(stackv2);
	// print_stack(stackv3);
	std::cout << "stackv3 == stackv2 -> " << (stackv3 == stackv2) << std::endl;
	std::cout << "stackv == stackv2 -> " << (stackv == stackv2) << std::endl;
	std::cout << "stck == stackv -> " << (stck == stackv2) << std::endl;
	std::cout << "stackv != stackv2 -> " << (stackv != stackv2) << std::endl;
	std::cout << "stackv3 != stackv2 -> " << (stackv3 != stackv2) << std::endl;
	std::cout << "stck != stackv -> " << (stck != stackv2) << std::endl;
	std::cout << "stackv < stackv2 -> " << (stackv < stackv2) << std::endl;
	std::cout << "stck < stackv -> " << (stck < stackv2) << std::endl;
	std::cout << "stackv3 < stackv2 -> " << (stackv3 < stackv2) << std::endl;
	std::cout << "stackv <= stackv2 -> " << (stackv <= stackv2) << std::endl;
	std::cout << "stck <= stackv -> " << (stck <= stackv2) << std::endl;
	std::cout << "stackv3 <= stackv2 -> " << (stackv3 <= stackv2) << std::endl;
	std::cout << "stackv > stackv2 -> " << (stackv > stackv2) << std::endl;
	std::cout << "stck > stackv -> " << (stck > stackv2) << std::endl;
	std::cout << "stackv3 > stackv2 -> " << (stackv3 > stackv2) << std::endl;
	std::cout << "stackv >= stackv2 -> " << (stackv >= stackv2) << std::endl;
	std::cout << "stck >= stackv -> " << (stck >= stackv2) << std::endl;
	std::cout << "stack3 >= stackv2 -> " << (stackv3 >= stackv2) << std::endl;
}