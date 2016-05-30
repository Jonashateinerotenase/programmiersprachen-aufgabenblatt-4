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
	Self& operator++() {
		return m_node->m_next;
	} // not implemented jet -- jet koennte allerdings nich ganz starten!!
	Self operator++(int) {
			ListIterator cooleriterator(*this);
			return *this;
	} // not implemented jet
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
	ListIterator<T> end(){
		if(empty())
		{
			return nullptr; 									
		}
		else if (m_last->m_next == nullptr) 
		{ 		
			ListNode<T>* node = new ListNode<T> ();
			node->m_prev = m_last; 							
			m_last->m_next = node; 					
			return node;
		} 
		else 
		{
			return m_last->m_next;										
		}
	}
	ListIterator<T> begin(){
		ListIterator <T> anfang(m_first);
		return anfang;
	}
	void push_front(T const& x){
		if (m_size==0){
			m_first = new ListNode<T>{x, nullptr, nullptr};
			m_last=m_first;
		}
		else if(m_size>=1){
			m_first = new ListNode<T>{x, nullptr, m_first};
			m_first->m_next->m_prev=m_first;
		}
		++m_size;
	}
	void push_back(T const& x){
		if (m_size==0)
		{
			m_last = new ListNode<T>{x, nullptr, nullptr};
			m_first=m_last;
		}
		else if(m_size>=1){
			m_last = new ListNode<T>{x, m_last, nullptr};
			m_last->m_prev->m_next=m_last;
		}
		++m_size;
	}
	void pop_front(){
		if (m_size==0){

			}
		else if(m_size>=1){
			assert(m_first != nullptr);
			delete m_first;
			m_first = m_first->m_next;
			--m_size;
		}

	}
	void pop_back(){
		if (m_size==0){

			}
		else if(m_size>=1){
			assert(m_last != nullptr);
			delete m_last;
			m_last = m_last->m_prev;
			--m_size;
		}

	}
	void clear(){
		if(m_size > 0){
			/*
			unsigned int range = m_size;
			for (unsigned int i = 0; i <= range; ++i)
			{
				pop_front();
			}
			*/
			while(m_size != 0)
			{
				pop_front();
			}

		}

	}


private:
	std::size_t m_size = 0;
	ListNode<T>* m_first = nullptr;
	ListNode<T>* m_last = nullptr;
};

# endif //#define BUW_LIST_HPP