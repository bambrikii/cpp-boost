#include <iostream>
#include <string>
#include <boost/iterator.hpp>
#include <boost/iterator/iterator_facade.hpp>

template <typename T>
struct MyNode
{
    T _val;
    MyNode<T> *_left;
    MyNode<T> *_right;
    MyNode(T val) : _val(val)
    {
    }
    ~MyNode()
    {
        delete _left;
        delete _right;
    }
};

template <typename T>
class MyIterator : public boost::iterator_facade<MyIterator<T>, T, boost::bidirectional_traversal_tag>
{
private:
    MyNode<T> *_node_ptr;

public:
    friend class boost::iterator_core_access;
    MyIterator(MyNode<T> *node) : _node_ptr(node) {}
    void increment() { _node_ptr = _node_ptr->_right; }
    void decrement() { _node_ptr = _node_ptr->_left; }
    bool equal(const MyIterator<T> &that) const
    {
        return _node_ptr == that._node_ptr;
    }
    T &dereference() const
    {
        return _node_ptr->_val;
    }
};

template <typename T>
class MyTree
{
private:
    MyNode<T> *_root;

    void insert(T val, MyNode<T> *node)
    {
        if (node->_val > val)
        {
            if (node->_left == nullptr)
            {
                node->_left = new MyNode(val);
            }
            else
            {
                insert(val, node->_left);
            }
        }
        else if (node->_val < val)
        {
            if (node->_right == nullptr)
            {
                node->_right = new MyNode(val);
            }
            else
            {
                insert(val, node->_right);
            }
        }
        // TODO: should we fail if the value already exists
    }

public:
    MyTree() : _root(nullptr) {}
    MyIterator<T> begin() { return MyIterator<T>(_root); }
    MyIterator<T> end() { return MyIterator<T>(nullptr); }

    MyIterator<T> begin() const { return MyIterator<T>(_root); }
    MyIterator<T> end() const { return MyIterator<T>(nullptr); }

    void insert(T val)
    {
        if (_root == nullptr)
        {
            _root = new MyNode(val);
        }
        else
        {
            insert(val, _root);
        }
    }
};

int main(int argc, char const *argv[])
{
    MyTree<std::string> tree;
    tree.insert("5");
    tree.insert("6");
    tree.insert("3");
    tree.insert("4");
    tree.insert("9");
    tree.insert("7");
    for (auto i = tree.begin(); i != tree.end(); i++)
    {
        std::cout << (*i) << std::endl;
    }

    return 0;
}
