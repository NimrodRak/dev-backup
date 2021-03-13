#include <stdexcept>
template <class T>
class stack
{
public:
	stack() noexcept
		: head_(nullptr)
	{}
	stack(stack& other) = default;
	stack(stack&& other) = default;
	stack& operator=(stack&& other) = delete;
	stack& operator=(stack& other) = delete;
	void push(T& data) noexcept
	{
		node* new_head = new node(data);

		new_head->next = head_;
		head_ = new_head;
	}
	void push(T&& data) noexcept
	{
		node* new_head = new node(data);
		new_head->next = head_;
		head_ = new_head;
	}
	T& top() const { return head_->data; }
	void pop()
	{
		auto new_head = head_->next;
		if (new_head == nullptr)
			throw std::underflow_error("Stack is empty, nothing to pop");
		delete head_;
		head_ = new_head;
	}
	size_t size() const noexcept
	{
		size_t size = 0;
		auto cur = head_;
		while (cur != nullptr)
		{
			size++;
			cur = cur->next;
		}
		return size;
	}
	void swap(stack& rhs) noexcept
	{
		auto& temp = rhs.head_;
		rhs.head_ = head_;
		head_ = temp;
	}
	bool empty() const noexcept { return head_ == nullptr; }
	~stack() { delete head_; }
private:
	class node
	{
	public:
		T data;
		node* next = nullptr;
		explicit node(T new_data)
			: data(new_data)
		{}
		~node() { delete next; }
		node(node& other)
			: data(other.data), next(other.next)
		{}
		node(node&& other) = default;
		node& operator=(const node& other) = default;
		node& operator=(node&& other) = default;
	};
	node* head_;
};