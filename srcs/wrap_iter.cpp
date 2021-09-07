// template<class _Iter>						
			// class	 __wrap_iter {
			// 	public:
			// 		typedef _Iter															iterator_type;
			// 		typedef typename std::iterator_traits<iterator_type>::iterator_category	iterator_category;
			// 		typedef typename std::iterator_traits<iterator_type>::value_type		value_type;
			// 		typedef typename std::iterator_traits<iterator_type>::difference_type	difference_type;
			// 		typedef typename std::iterator_traits<iterator_type>::pointer			pointer;
			// 		typedef typename std::iterator_traits<iterator_type>::reference			reference;
				
			// 	private:
			// 		iterator_type	__i;
			// 	public:
			// 		__wrap_iter() {}
			// 		__wrap_iter(__wrap_iter const &copy) {*this = copy;}
			// 		__wrap_iter		&operator=(__wrap_iter<iterator_type>  const &rhs) {
			// 			__i = rhs.__i;
			// 			return (*this);
			// 		}
			// 		bool			operator==(__wrap_iter const &rhs) const { return (__i == rhs.__i);}
			// 		bool			operator!=(__wrap_iter const &rhs) const { return (__i != rhs.__i);}
			// 		reference		operator*() const { return (*__i);}
			// 		pointer			operator->() const { return (__i);}
			// 		iterator_type	operator++(int) { return (__i++);}
			// 		iterator_type	operator++() { return (++__i);}
			// 		iterator_type	operator--(int) { return (__i--);}
			// 		iterator_type	operator--() { return (--__i);}			
			// 		iterator_type	operator+(difference_type n) const {return (__i + n);}

					
			// 		__wrap_iter(iterator_type const &p): __i(p){}
			// };
			// typedef __wrap_iter<pointer>			iterator;