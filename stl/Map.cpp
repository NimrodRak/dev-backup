#include <utility>
#include <stack>
template <class Kty, class Vty>
class OrderedMap
{

public:
	OrderedMap()
		: base_(NULL, NULL)
	{}
	Vty& operator[](Kty key) { return base_.find(key); }
	const Vty& operator[](Kty key) const { return base_.find(key); }

private:
	/** Tree node of a BST map implementation */
	class _TreeNode
	{
	private:
		std::pair<Kty, Vty> data_;
		_TreeNode* left_ = nullptr;
		_TreeNode* right_ = nullptr;
		friend class OrderedMap;
	public:
		_TreeNode(Kty key, Vty mapped)
			: data_(key, mapped)
		{}
		_TreeNode(std::pair<Kty, Vty> value)
			: data_(value)
		{}
		_TreeNode(const _TreeNode& other)
			: data_(other.data_), left_(other.left_), right_(other.right_)
		{}
		/** return the mapped value of the key, a recursive find in a BST */
		Vty& find(Kty key)
		{
			if (key < data_.first)
			{
				if (left_ != nullptr)
					return left_->find(key);

				left_ = new _TreeNode(key, NULL);
				return left_->data_.second;
			}
			if (key > data_.first)
			{
				if (right_ != nullptr)
					return right_->find(key);

				right_ = new _TreeNode(key, NULL);
				return right_->data_.second;
			}
			// if the value is not smaller or bigger - it is the value itself
			return data_.second;
		}
		~_TreeNode() { delete left_; delete right_; }
	};
public:
	class Iterator
	{
	private:
		std::stack<_TreeNode> node_stack_;
		static void push_left_nodes(std::stack<_TreeNode>& stack, _TreeNode& start)
		{
			auto cur = start;
			do
			{
				node_stack_.push(cur);
				cur = cur.left_;
			} while (cur.left_ != nullptr);
		}
	public:
		Iterator(OrderedMap* map)
		{
			push_left_nodes(node_stack_, map.base_);
		}
		Iterator& operator++()
		{
			auto top = node_stack_.top();

			node_stack_.pop();
			push_left_nodes(node_stack_, top.right_);
			return *this;
		}
		Vty& operator*()
		{
			return node_stack_.top().data_.second;
		}

	};
private:
	_TreeNode base_;
public:
	Iterator begin()
	{
		return Iterator(this);
	}
	Iterator end()
	{
		return NULL;
	}
};
