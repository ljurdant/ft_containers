
#include <deque>

namespace ft {
	template <class T, class Container = std::deque<T> >
		class stack {
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef	size_t			size_type;
		protected:
			container_type	c;
		public:
			explicit stack (const container_type& ctnr = container_type()): c(ctnr) {}
			bool				empty() const { return (c.empty()); }
			size_type			size() const { return (c.size()); }
			value_type& 		top(){ return(c.front()); }
			const value_type&	top() const { return (c.front()); }
			void				push (const value_type& val) { c.insert(c.begin(), val); }
			void 				pop () { c.erase(c.begin()); }
			
			bool	operator== (const stack<T,Container>& rhs) { return (c == rhs.c); }
			bool	operator!= (const stack<T,Container>& rhs) { return (c != rhs.c); }
			bool	operator< (const stack<T,Container>& rhs) { return (rhs.c < c); }
			bool	operator<= (const stack<T,Container>& rhs) { return (rhs.c <= c); }
			bool	operator> (const stack<T,Container>& rhs) { return (rhs.c > c); }
			bool	operator>= (const stack<T,Container>& rhs) { return (rhs.c >= c); }

		};
}