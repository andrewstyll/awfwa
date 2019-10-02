#ifndef ANDREW_TREE_BST_H
#define ANDREW_TREE_BST_H

#include <iostream>
#include "TreeNode.hpp"

template <typename Type>
class BST {
    private:
        TreeNode<Type>* root_;

    public:
        BST();
        ~BST();

        bool Insert(Type const &);
        bool Remove(Type const &);
        bool Contains(Type const &) const;

        void PreOrder() const;
        void InOrder() const;
        void PostOrder() const;
};


template <typename Type>
BST<Type>::BST() :
root_(NULL) {
}

template <typename Type>
BST<Type>::~BST() {
    delete root_;
}

template <typename Type>
bool BST<Type>::Insert(Type const &obj) {
    if(root_ == NULL) {
        root_ = new TreeNode<Type>(obj);
        return true;
    }
    return root_->Insert(obj);
}

template <typename Type>
bool BST<Type>::Remove(Type const &obj) {
    if(root_ != NULL) {
        return root_->Remove(obj, root_);
    }
    return false;
}

template <typename Type>
bool BST<Type>::Contains(Type const &obj) const {
    if(root_ != NULL) {
        return root_->Contains(obj);
    }
    return false;
}

template <typename Type>
void BST<Type>::PreOrder() const {
    std::cout << "PreOrder: ";
    if(root_ != NULL) {
        root_->PreOrder();
    }
    std::cout << "\n";
}

template <typename Type>
void BST<Type>::InOrder() const {
    std::cout << "InOrder: ";
    if(root_ != NULL) {
        root_->InOrder();
    }
    std::cout << "\n";
}

template <typename Type>
void BST<Type>::PostOrder() const {
    std::cout << "PostOrder: ";
    if(root_ != NULL) {
        root_->PostOrder();
    }
    std::cout << "\n";
}

#endif // ANDREW_TREE_BST_H
