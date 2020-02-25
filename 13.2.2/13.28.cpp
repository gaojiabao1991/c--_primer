#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::allocator;
using std::array;
using std::back_inserter;
using std::begin;
using std::cerr;
using std::cin;
using std::copy;
using std::cout;
using std::deque;
using std::end;
using std::endl;
using std::ends;
using std::find;
using std::forward_list;
using std::front_inserter;
using std::getline;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::make_shared;
using std::map;
using std::multimap;
using std::multiset;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::pair;
using std::runtime_error;
using std::set;
using std::shared_ptr;
using std::sort;
using std::stable_sort;
using std::string;
using std::stringstream;
using std::unique;
using std::unique_ptr;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::weak_ptr;
using namespace std::placeholders;

class TreeNode {
   public:
    TreeNode() : value("-"), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode& ori) {
        value = ori.value;
        count = ori.count;
        left = new TreeNode(*ori.left);
        right = new TreeNode(*ori.right);
    }

    TreeNode& operator=(const TreeNode& cp) {
        auto left_cp = new TreeNode(*cp.left);
        auto right_cp = new TreeNode(*cp.right);
        delete left;
        delete right;
        value = cp.value;
        count = cp.count;
        left = left_cp;
        right = right_cp;
    }

    ~TreeNode() {
        delete left;
        delete right;
    }

   private:
    string value;
    int count;
    TreeNode* left;
    TreeNode* right;
};

class BinStrTree {
   public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree& ori) {
        root = new TreeNode(*ori.root);
    }

    BinStrTree& operator=(const BinStrTree& cp) {
        auto root_cp = new TreeNode(*cp.root);
    }

    ~BinStrTree() {
        delete root;
    }

   private:
    TreeNode* root;
};