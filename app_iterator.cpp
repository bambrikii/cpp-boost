#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <numeric>
#include <regex>
#include <boost/iterator/filter_iterator.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/function_output_iterator.hpp>
#include <boost/iterator.hpp>
#include <boost/iterator/iterator_facade.hpp>

typedef std::map<std::string, std::string> mymap;

struct GetScore : std::unary_function<const mymap::value_type &, std::string>
{
    result_type operator()(argument_type entry) const
    {
        return entry.second;
    }
};

struct StringCat
{
    StringCat(std::string &str) : result_(str) {}
    void operator()(const std::string &arg)
    {
        if (arg.find_first_of(" \t") != std::string::npos)
        {
            result_ += " \"" + arg + "\"";
        }
        else
        {
            result_ += " " + arg;
        }
    }
    std::string &result_;
};

template <typename T>
struct TreeNode
{
    T data;
    TreeNode<T> *left, *right;
    TreeNode<T> *prev, *next;

    TreeNode(const T &elem) : data(elem), left(nullptr), right(nullptr), prev(nullptr), next(nullptr)
    {
    }

    ~TreeNode()
    {
        delete left;
        delete right;
    }
};
template <typename T>
class BSTIterator : public boost::iterator_facade<BSTIterator<T>, T, boost::bidirectional_traversal_tag>
{
public:
    BSTIterator() : node_ptr(nullptr) {}
    explicit BSTIterator(TreeNode<T> *node) : node_ptr(node) {}
    BSTIterator(const BSTIterator<T> &that) : node_ptr(that.node_ptr) {}

private:
    TreeNode<T> *node_ptr;
    friend class boost::iterator_core_access;
    void increment() { node_ptr = node_ptr->next; }
    void decrement() { node_ptr = node_ptr->prev; }
    bool equal(const BSTIterator<T> &that) const
    {
        return node_ptr == that.node_ptr;
    }
    T &dereference() const { return node_ptr->data; }
};
template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr), first(nullptr), last(nullptr) {}
    ~BinarySearchTree()
    {
        delete root;
        delete last;
    }

    void insert(const T &elem)
    {
        if (!root)
        {
            root = new TreeNode<T>(elem);
            first = root;
            last = new TreeNode<T>(T());
            first->next = last;
            last->prev = first;
        }
        else
        {
            insert(elem, root);
        }
    }
    BSTIterator<T> begin() { return BSTIterator<T>(first); }
    BSTIterator<T> end() { return BSTIterator<T>(last); }

    BSTIterator<T> begin() const { return BSTIterator<const T>(first); }
    BSTIterator<T> end() const { return BSTIterator<const T>(last); }

private:
    TreeNode<T> *root;
    TreeNode<T> *first;
    TreeNode<T> *last;

    void insert(const T &elem, TreeNode<T> *node)
    {
        if (elem < node->data)
        {
            if (node->left)
            {
                insert(elem, node->left);
            }
            else
            {
                node->left = new TreeNode<T>(elem);
                node->left->prev = node->prev;
                node->prev = node->left;
                node->left->next = node;

                if (!node->left->prev)
                {
                    first = node->left;
                }
                else
                {
                    node->left->prev->next = node->left;
                }
            }
        }
        else if (node->data < elem)
        {
            if (node->right)
            {
                insert(elem, node->right);
            }
            else
            {
                node->right = new TreeNode<T>(elem);
                node->right->next = node->next;
                node->next = node->right;
                node->right->prev = node;

                if (node->right->next)
                {
                    node->right->next->prev = node->right;
                }
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    // --
    std::vector<std::string> vector1{"str1", "str2", "str3"};
    auto iter = boost::make_filter_iterator([](const std::string str)
                                            {
                                                std::regex re("([12]+)");
                                                return std::regex_search(str, re);
                                                // return str.find("1") != std::string::npos;
                                            },
                                            vector1.begin(), vector1.end());
    for (auto i = iter; i.base() != i.end(); i++)
    {
        std::cout << " filter - " << (*i) << std::endl;
    }

    // --
    mymap map1;
    map1["key1"] = "val1";

    // boost::transform_iterator<std::string, mymap::iterator>
    //     first(map1.begin(), [](std::pair<std::string, std::string> &entry)
    //           { return entry.second; })
    // last(map1.begin(), [](std::string &entry)
    //  { return entry; })
    // ;
    boost::transform_iterator<GetScore, mymap::iterator>
        first(map1.begin(), GetScore()),
        last(map1.begin(), GetScore());
    // std::cout << std::accumulate(first, last, 0) << '\n';
    for (auto i = first; i.base() != map1.end(); i++)
    {
        std::cout << " transform - " << (*i) << std::endl;
    }

    // --
    std::vector<std::string> list3{"var1", "var2", "var3"};
    std::string str3 = "";
    std::copy(list3.begin(), list3.end(), boost::make_function_output_iterator(StringCat(str3)));
    std::cout << " transform output - " << str3 << '\n';

    // --
    BinarySearchTree<std::string> bst;
    bst.insert("abc");
    bst.insert("def");
    bst.insert("xyz");

    for (auto &x : bst)
    {
        std::cout << x << '\n';
    }

    return 0;
}
