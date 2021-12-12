// copyright Lucas Henrique Gonçalves Wodtke-16202258
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "array_list.h"

namespace structures {

/*!
* Documentacao
*/
template<typename T>
class BinaryTree: public ArrayList<T> {
 public:
     /*!
    * Documentacao
    */
    ~BinaryTree() {
        delete root;
        size_ = 0u;
    }
    /*!
    * Documentacao
    */
    void insert(const T& data) {
        if (empty())
            root = new Node(data);
        else
            root->insert(data);
        size_++;
    }

    /*!
    * Documentacao
    */
    void remove(const T& data) {
        bool seg;
        if (empty()) {
            return;
        } else {
            seg = root->remove(data);
            if (seg) {
                --size_;
            }
        }
    }

    /*!
    * Documentacao
    */
    bool contains(const T& data) const {
        if (empty()) {
            return false;
        } else {
            return root->contains(data);
        }
    }
    /*!
    * Documentacao
    */
    bool empty() const {
        return size() == 0;
    }

    /*!
    * Documentacao
    */
    std::size_t size() const {
        return size_;
    }

    /*!
    * Documentacao
    */
    ArrayList<T> pre_order() const {
        ArrayList<T> v;
        if (!(empty())) {
            root->pre_order(v);
        }
        return v;
    }
    /*!
    * Documentacao
    */
    ArrayList<T> in_order() const {
        ArrayList<T> v;
        if (!(empty())) {
            root->in_order(v);
        }
        return v;
    }
    /*!
    * Documentacao
    */
    ArrayList<T> post_order() const {
        ArrayList<T> v;
       if (!(empty())) {
            root->in_order(v);
        }
        return v;
    }

private:
    struct Node {
        explicit Node(const T& data) {
            this->data = data;
        }

        T data;
        Node* left{nullptr};
        Node* right{nullptr};

        void insert(const T& data_) {
            Node* newNode;
            if (data_ > data) {
                if (right == nullptr) {
                    newNode = new Node(data_);
                    right = newNode;
                    if (right == nullptr)
                    throw std::out_of_range("Full tree!");
                } else {
                    right->insert(data_);
                }
            } else {
                if (left == nullptr) {
                    newNode = new Node(data_);
                    left = newNode;
                    if (left == nullptr)
                    throw std::out_of_range("Full tree!");
                } else {
                    left->insert(data_);
                }
            }
        }

        bool remove(const T& data_) {
            if (data_ == data) {
                if (left != nullptr && right != nullptr) {
                    auto it = mini(right);
                    data = it->data;
                    return right->remove(data);
                } else {
                    if (right != nullptr) {
                        data = right->data;
                        return right->remove(data);
                    } else {
                        if (left != nullptr) {
                            data = left->data;
                            return left->remove(data);
                        } else {
                            delete this;
                            return true;
                        }
                    }
                }
            } else {
                if (right != nullptr && data < data_) {
                    return right->remove(data_);
                } else {
                    if (left != nullptr && data > data_) {
                        return left->remove(data_);
                    }
                }
            }
            return false;
        }

        Node* mini(Node* node) {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        bool contains(const T& data_) const {
            if (data == data_) {
                return true;
            } else {
                if (right != nullptr && data_ > data) {
                    return right->contains(data_);
                } else if (left != nullptr && data_ < data) {
                    return left->contains(data_);
                }
            }
            return false;
        }

        void pre_order(ArrayList<T>& v) const {
            v.push_back(data);
            if (left != nullptr) {
                left->pre_order(v);
            }
            if (right != nullptr) {
                right->pre_order(v);
            }
        }

        void in_order(ArrayList<T>& v) const {
            if (left != nullptr) {
                left->in_order(v);
            }
            v.push_back(data);
            if (right != nullptr) {
                right->in_order(v);
            }
        }

        void post_order(ArrayList<T>& v) const {
            if (left != nullptr) {
                left->post_order(v);
            }
            if (right != nullptr) {
                right->post_order(v);
            }
            v.push_back(data);
        }
    };

    Node* root{nullptr};
    std::size_t size_{0u};
};

}  // namespace structures
#endif
