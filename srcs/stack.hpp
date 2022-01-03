
#include <deque>
#include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
		class stack {
		public:
			typedef T					value_type;
			typedef Container			container_type;
			typedef	size_t				size_type;
			typedef	value_type&			reference;
			typedef value_type const &	const_reference;
		protected:
			container_type	c;
		public:
			explicit stack (const container_type& ctnr = container_type()): c(ctnr) {}
			bool				empty() const { return (c.empty()); }
			size_type			size() const { return (c.size()); }
			reference 			top(){ return(c.back()); }
			const_reference		top() const { return (c.back()); }
			void				push (const value_type& val) { c.push_back(val); }
			void 				pop () { c.pop_back(); }

			friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c == rhs.c);
			}

			friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c != rhs.c);
			}

			friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				
				return (lhs.c < rhs.c);
			}

			friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c <= rhs.c);
			}

			friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c > rhs.c);
			}

			friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c >= rhs.c);
			}
		};
}