#ifndef ANDREW_TREE_TREENODE_H
#define ANDREW_TREE_TREENODE_H

#include <iostream>
#include <cstddef>

template <typename Type>
class TreeNode {
    private:
        Type obj_;
        TreeNode<Type>* left_;
        TreeNode<Type>* right_;
        
    public:
        TreeNode(Type const &);
        ~TreeNode();

        bool IsLeaf() const;

        Type Retrieve() const;
        TreeNode<Type>* Left() const;
        TreeNode<Type>* Right() const;

        void Left(TreeNode<Type>*);
        void Right(TreeNode<Type>*);
        
        TreeNode<Type>* Front();
        TreeNode<Type>* Back();

        bool Insert(Type const &);
        bool Remove(Type const &, TreeNode<Type>* &);
        bool Contains(Type const &) const;

        void PreOrder() const;
        void InOrder() const;
        void PostOrder() const;
};

template <typename Type>
TreeNode<Type>::TreeNode(Type const &obj):
obj_(obj),left_(NULL),right_(NULL){
}

template <typename Type>
TreeNode<Type>::~TreeNode() {
    delete left_;
    delete right_;
    left_ = NULL;
    right_ = NULL;
}

template <typename Type>
bool TreeNode<Type>::IsLeaf() const {
    return (left_ == NULL && right_ == NULL);
}

template <typename Type>
Type TreeNode<Type>::Retrieve() const {
    return obj_;
}

template <typename Type>
TreeNode<Type>* TreeNode<Type>::Left() const {
    return left_;
}

template <typename Type>
TreeNode<Type>* TreeNode<Type>::Right() const {
    return right_;
}

template <typename Type>
void TreeNode<Type>::Left(TreeNode<Type>* n) {
    left_ = n;
}

template <typename Type>
void TreeNode<Type>::Right(TreeNode<Type>* n) {
    right_ = n;
}

template <typename Type>
TreeNode<Type>* TreeNode<Type>::Front() {
    if(right_ == NULL) {
        return this;
    }
    return right_->Front();
}

template <typename Type>
TreeNode<Type>* TreeNode<Type>::Back() {
    if(left_ == NULL) {
        return this;
    }
    return left_->Back();
}

template <typename Type>
bool TreeNode<Type>::Insert(Type const &obj) {
    bool ret = false;

    if(obj < obj_) {
        if(left_ == NULL) {
            left_ = new TreeNode<Type>(obj);
            ret = true;
        } else {
            return left_->Insert(obj);
        }
    } else if(obj > obj_) {
        if(right_ == NULL) {
            right_ = new TreeNode<Type>(obj);
            ret = true;
        } else {
            return right_->Insert(obj);
        }
    }
    return ret;
}

// use ref to pointer to reassign children pointers of parent while in child. Alternative is to perform deletion from
// perspective of parent.
template <typename Type>
bool TreeNode<Type>::Remove(Type const &obj, TreeNode<Type>* &current) {
    if(obj < obj_) {
        if(left_ == NULL) {
            return false;
        } else {
            return left_->Remove(obj, left_);
        }
    } else if(obj > obj_) {
        if(right_ == NULL) {
            return false;
        } else {
            return right_->Remove(obj, right_);
        }
    } else {
        if(IsLeaf()) {
            current = NULL;
            delete this;
        } else if(right_ != NULL && left_ == NULL) {
            current = right_;
            right_ = NULL;
            delete this;
        } else if(right_ == NULL && left_ != NULL) {
            current = left_;
            left_ = NULL;
            delete this;
        } else {
            // get back of right or front of left, I'm going with front of left
            // copy the value? no, remove the
            obj_ = left_->Front()->Retrieve(); // safe as left can't be NULL
            return left_->Remove(obj_, left_);
        }
        return true;
    }
}

template <typename Type>
bool TreeNode<Type>::Contains(Type const &obj) const {
    if(obj < obj_) {
        if(left_ != NULL) {
            return left_->Contains(obj);
        } else {
            return false;
        }
    } else if(obj > obj_) {
        if(right_ != NULL) {
            return right_->Contains(obj);
        } else {
            return false;
        }
    } else {
        return true;
    }
}

template <typename Type>
void TreeNode<Type>::PreOrder() const {
    std::cout << obj_ << ",";
    
    if(left_ != NULL) {
        left_->PreOrder();
    }
    if(right_ != NULL) {
        right_->PreOrder();
    }
}

template <typename Type>
void TreeNode<Type>::InOrder() const {
    
    if(left_ != NULL) {
        left_->InOrder();
    }
    
    std::cout << obj_ << ",";
    
    if(right_ != NULL) {
        right_->InOrder();
    }
}

template <typename Type>
void TreeNode<Type>::PostOrder() const {
    
    if(left_ != NULL) {
        left_->PostOrder();
    }
    if(right_ != NULL) {
        right_->PostOrder();
    }
    
    std::cout << obj_ << ",";
}

#endif // ANDREW_TREE_TREENODE_H
