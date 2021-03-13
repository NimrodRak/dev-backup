#include <iostream>
#include <stdexcept>
class list
{
private:
	void** base_;
	size_t max_size_, size_;

public:
	list()
		: max_size_(1), size_(0)
	{ base_ = new void* [max_size_]; }
	list(const size_t size)
		: max_size_(size), size_(0)
	{ base_ = new void* [max_size_]; }
	size_t size() const { return size_; }
	size_t max_size() const { return max_size_; }
	template <class T>
	void append(T& item)
	{
		if (size_ >= max_size_)
			throw std::out_of_range("Before dynamic allocation");
		size_++;
		base_[size_ - 1] = new T(item); // requires copy constructor
	}
	template <class T>
	void append(T&& item)
	{
		if (size_ == max_size_)
		{
			max_size_ *= 2;
			auto old_base = base_;
			base_ = new void* [max_size_];
			memcpy(base_, old_base, size_ * sizeof(void*));
			delete[] base_;
			base_ = new_base;
		}
		
		base_[size_] = new T(item);
		size_++;
	}
	template <class T>
	T& at(const size_t index)
	{
		if (index >= size_)
			throw std::out_of_range("Tried to access value out ot current size");
		// TODO : there is an error here for some reason
		auto x = (T*) base_[index];
		return *x;
		return *((T*) base_[index]);
	}
	template <class T>
	const T& at(const size_t index) const
	{
		if (index >= size_)
			throw std::out_of_range("Tried to access value out ot current size");

		return *static_cast<T*>(base_[index]);
	}
	void pop(size_t index = 0)
	{
		if (size_ >= index)
			throw std::out_of_range("Can not pop item outside range of list");
		
		memmove(base_ + index * sizeof(void*),
			base_ + (index + 1) * sizeof(void*), // difference between src and dst is 1
			(size_ - index - 1) * sizeof(void*));
		size_--;
	}
};

int main()
{
	list l;
	l.append(3);
	l.append(4);
	auto x = l.at<int>(0);
	std::cout << x;
}