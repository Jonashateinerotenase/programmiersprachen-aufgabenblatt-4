#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cstddef>
// List .hpp
template <typename T>
class List;

template <typename T>
struct ListNode
{
	ListNode():
	m_value(),
	m_prev(nullptr),
	m_next(nullptr){}
	ListNode(T const & v,ListNode*prev,ListNode*next):
	  m_value(v),
	  m_prev(prev),
	  m_next(next)
	{}
	T m_value ;
	ListNode * m_prev ;
	ListNode * m_next ;
};
	
	template <typename T>
	struct ListIterator
	{
	typedef ListIterator<T> Self;

	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef ptrdiff_t difference_type ;
	typedef std::forward_iterator_tag iterator_category;

	friend class List <T>;

	ListIterator():
		m_node{nullptr}
	 {}
	ListIterator (ListNode <T>* n):
	m_node{n}
	{} 
	reference operator*() const {
		return m_node->m_value;
	} 
	pointer operator->() const {
		return &(m_node->m_value);
	} // not implemented jet
	Self& operator++() //++i
	{
		m_node = m_node -> m_next;
		return *this;
	} 
	Self operator++(int) //i++
	{
		ListIterator tmp(*this);

		m_node = m_node -> m_next;
		
		return tmp;
	} // not implemented jet
	/*Self operator++(int x)
	{
			while(x!=0){
				*this=next();
				--x;
			}
			return *this;
	} // not implemented jet*/

	bool operator==(const Self& x) const {
		if (x.m_node==m_node)
		{
			return true;
		}
		else return false;
	} // not implemented jet
	bool operator!=(const Self& x) const {
		if (x.m_node!=m_node)
		{
			return true;
		}
		else return false;
	} // not implemented jet
Self next() const
{
	if (m_node)
		return ListIterator (m_node -> m_next);
	else
		return ListIterator (nullptr);
}
private:
// The Node the iterator is pointing to
ListNode<T>* m_node = nullptr;
};

template <typename T>
struct ListConstIterator
{
	friend class List <T>;
public:
// not implemented yet
private:
	ListNode <T>* m_node = nullptr;
};


template <typename T>
bool operator==(List<T> const& xs, List<T> const& ys) //in const fkt alle benutzten fkt const
{
	if(xs.size() != ys.size())return false;
	else
	{
		ListIterator<T> jumperx = xs.begin();
		ListIterator<T> jumpery = ys.begin();
	 	for(unsigned int i = 0; i < xs.size(); ++i)
	 	{
	 		if(*jumperx != *jumpery)
	 		{
	 			return false;
	 		}
	 		jumperx++;
	 		jumpery++;
	 	}
	 	/*
	 	while(jumperx!=xs.end())
	 	{
			if(*jumperx != *jumpery)
			{
				return false;
			}
		jumperx++;
		jumpery++;

		std::cout << "HALLO MAMA" << std::endl;
		}
		*/
	}
	return true;
}


template <typename T>
bool operator!=(List<T> const& xs, List<T> const& ys)
{
	return !(xs==ys);
}

template <typename T>
class List
{
public:
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef ListIterator <T> iterator;
	typedef ListConstIterator <T> const_iterator;
	friend class ListIterator <T>;
	friend class ListConstIterator <T>;

	List():
		m_size{0},
		m_first{nullptr},
		m_last{nullptr}
	{}

	List(List<T> const& list2): 
		m_size{0},
		m_first{nullptr},
		m_last{nullptr}
	{

		for(auto const& x : list2){
			push_back(x);
		}
	}

	List(List&& listmove):
		m_size{listmove.m_size},
		m_first{listmove.m_first},
		m_last{listmove.m_last}
	{
		listmove.m_size=0;
		listmove.m_first=nullptr;
		listmove.m_last=nullptr;

	}

	
	~List() { clear(); }

	bool empty() const {
		return m_size == 0;
	}
	std::size_t size() const{
		return m_size;
	} 
	T const& front() const {
		return m_first->m_value;
	}
	T& front() {
		return m_first->m_value;
	}
	T& back() {
		return m_last->m_value;
	}
	T const& back() const {
		return m_last->m_value;
	}

	ListIterator<T> end() const
	{
		return ListIterator<T>();
	}
	ListIterator<T> begin() const
	{
		return ListIterator<T>(m_first);
	}
	void push_front(T const& x){
		m_first = new ListNode<T>{x, nullptr, m_first};
		if (m_size==0){
			
			m_last=m_first;
		}
		else if(m_size>=1){
			m_first->m_next->m_prev=m_first;
		}
		++m_size;
	}
	void push_back(T const& x){
		m_last = new ListNode<T>{x, m_last, nullptr};
		if (m_size==0)
		{
			m_first=m_last;
		}
		else if(m_size>=1){
			m_last->m_prev->m_next=m_last;
		}
		++m_size;
	}
	void pop_front(){
		if (m_size==0){
		} else if (m_size == 1)	{
            delete m_first;
            m_first = nullptr;
            m_last = nullptr;
            m_size = 0;
		}
		else if(m_size>1){
			assert(m_first != nullptr);
			auto n = m_first;
			m_first = m_first->m_next;
			delete n;
			--m_size;
		}

	}
	void pop_back(){
		if (m_size==0){
		}else if (m_size == 1){
			delete m_last;
			m_first = nullptr;
			m_last = nullptr;
			m_size = 0;
		}
		else if(m_size>1){
			assert(m_last != nullptr);
			auto n = m_last;
			m_last = m_last->m_prev;
			delete n;
			--m_size;
		}

	}
	void clear(){
		while(!empty())
			pop_front();
	}
	/*void insert(){

	}*/
	void reverse(){
		List<T> y{*this};
		clear();
		for(ListIterator<T> q = y.begin(); q!=y.end();++q){
			push_front(*q);
		}
	}

	void insert(T const& wert, iterator& position)
	{
		if (position==begin())
		{
			push_front(wert);
		}
		else if(position==end())
		{
			push_back(wert);
		}
		else 
		{
			ListNode <T>* newnode= new ListNode<T>{wert, position.prev().m_node, position.m_node};

			position.prev().m_node->m_next = newnode;
			position.m_node->m_prev = newnode;
			m_size++;//wird bei pushen selbstgemacht
		}
	}

private:
	std::size_t m_size = 0;
	ListNode<T>* m_first = nullptr;
	ListNode<T>* m_last = nullptr;
};

# endif //#define BUW_LIST_HPP