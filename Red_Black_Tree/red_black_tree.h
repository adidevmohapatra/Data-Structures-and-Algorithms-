////////Opening Comment: Purpose of the .h file is to implment functions for the rbt tree
////////like remove, insert, etc. and test it in the .cpp file


#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <cstddef>
#include <utility>
#include <iostream>



template <typename Comparable>
class RedBlackTree {

private:
	struct Node {
        Comparable value;
        Node *left=nullptr;
        Node *right=nullptr;
        Node *parent = nullptr;
        int color= RED;

        Node(const Comparable & theElement, Node *lt, Node *rt, Node* par, int c): value(theElement), left(lt), right(rt), parent(par), color(RED){}
		Node(): left(nullptr),right(nullptr), parent(nullptr), color(RED){}
    };
    Node *root=nullptr;

public:
	enum Color{RED, BLACK};
    //-------------------------------------------------------
    // Name:default 
    // PreCondition: gets all the default values to use and implement later on in the class
    // PostCondition: sets everything to initial value and sets it for later use.
    //---------------------------------------------------------
    RedBlackTree(){
        root=nullptr;
       
    }
    //-------------------------------------------------------
    // Name:copy constructor 
    // PreCondition: copy the elements of the root
    // PostCondition: elements are copied from the root
    //---------------------------------------------------------
	RedBlackTree(const RedBlackTree& other){
        if (other.root==nullptr){
            return;
        }
        copy_root(root, other.root);

    }
    //-------------------------------------------------------
    // Name:destructer 
    // PreCondition: objective is to take the roots and remove all elements 
    // PostCondition: elements are all removed from the rbt
    //---------------------------------------------------------
	~RedBlackTree(){
        destroy_destructor(root);
    }
    //-------------------------------------------------------
    // Name:operator overload
    // PreCondition: make a deep copy 
    // PostCondition: returns a deep copy of the roots
    //---------------------------------------------------------
	RedBlackTree& operator=(const RedBlackTree& other){
        
        if (this==&other){
            return *this;
        }
        if(root!=nullptr){
            destroy_destructor(root);
        }
    
        root=other.root;
        copy_root(root, other.root);
        
        return *this;

    }
    //-------------------------------------------------------
    // Name:copy_root
    // PreCondition: make a copy of the root for the rule of three
    // PostCondition: does make a copy that is recursivly called from both
    //---------------------------------------------------------
    void copy_root(Node*& upper, Node *p){
        if(p==nullptr){
            return;
        }
        upper= new Node();
        upper->value=p->value;  
        upper->parent=p->parent;
        upper->color=p->color;

        if(p->left!=nullptr){
            copy_root(upper->left,p->left);
        }
        if(p->right!=nullptr){
            copy_root(upper->right,p->right);
        }
    }
    //-------------------------------------------------------
    // Name:destroy_destructor
    // PreCondition: make a deletion of the root for the empty functions
    // PostCondition: does make a deletion that is recursivly called for them
    //---------------------------------------------------------
    void destroy_destructor(Node *p){
        if (p==nullptr){
            return;
        }
        if( p!=nullptr){
        destroy_destructor( p -> left);
        destroy_destructor( p -> right);  
        delete p;
        }
        return;
    }
    //-------------------------------------------------------
    // Name:contains
    // PreCondition: gives a contain value
    // PostCondition: returns a contain value from contain_helper
    //---------------------------------------------------------
	bool contains(const Comparable& value) const{
        return contain_helper(root, value);
    }
    //-------------------------------------------------------
    // Name:contain_helper
    // PreCondition: make a boolean to see if there or not
    // PostCondition: does make a contain that is recursivly called from contains
    //---------------------------------------------------------
    bool contain_helper(Node *x, const Comparable& item )const{
        if(x==nullptr){
            return false;
        }
        if(x->value==item){
            return true;
        }
        else if(x->value>item){
            return contain_helper(x->left,item);
        }
        else if(x->value<item){
            return contain_helper(x->right,item);
        }
        return false;
    }



    //-------------------------------------------------------
    // Name:insert
    // PreCondition: gives an insert value
    // PostCondition: returns an insert value from insert_helper
    //---------------------------------------------------------
	void insert(const Comparable& x){

        Node* temp = root;
		Node* parentNode = nullptr;
		while (temp != nullptr) {
            if (x != temp->value){
                parentNode = temp;

                if (x < temp->value) {
                    temp = temp->left;
                } 
                else {
                    temp = temp->right;
                }
            }
            else if (x == temp->value) {
				return;
			}
		}
		Node* node = new Node();
		node->value = x;
		node->color = BLACK;
		node->parent = parentNode;

		if (parentNode==nullptr){
            root = node;
        }
        else{
			if (x > parentNode->value) {
				parentNode->right = node;
			}
			else if(x < parentNode->value) {
				parentNode->left = node;
			}
		}
		insertHelper(node);
		return;
       
    }
    //-------------------------------------------------------
    // Name:insert_helper
    // PreCondition: make a function to insert anywhere
    // PostCondition: does make a contain that is recursivly called from insert
    //---------------------------------------------------------
    void insertHelper(Node*& value){

        Node* grand=nullptr;
        Node* par2=nullptr;
        while (value != root && value->parent->color == RED) { 
            grand=value->parent->parent;
            par2=value->parent;
            if(par2 != grand->left){
                Node* temp = grand->left;
                if(temp == nullptr && temp->color != RED){
                    if (value == par2->left) {
                        value = par2;
                        rotateright(value);
                    }
                    par2->color = BLACK;
                    grand->color = RED;
                    rotateleft(grand);
                }
                else if (temp != nullptr && temp->color == RED) {
                    par2->color = BLACK;
                    temp->color = BLACK;
                    grand->color = RED;
                    value = grand;
                }
            }
            else if (par2 == grand->left) {
                Node* temp = grand->right;
                if(temp == nullptr && temp->color != RED){  
                    if (value == par2->right) {
                        value = par2;
                        rotateleft(value);
                    }
                par2->color = BLACK;
                grand->color = RED;
                rotateright(grand);
                }
                else if (temp != nullptr && temp->color == RED) {
                    par2->color = BLACK;
                    temp->color = BLACK;
                    grand->color = RED;
                    value = grand;
                }
            }
        }
        root->color = BLACK;
        return;
   }
   //-------------------------------------------------------
   // Name: rotateleft
   // PreCondition: to balance the rotation must be done for left side
   // PostCondition: does make the rotation by switching around for left side
   //---------------------------------------------------------
   void rotateleft(Node* node_two) {
        Node *node_one = node_two->right;
        node_two->right = node_one->left;

        if (node_two != nullptr) {
            node_two->parent = node_one;
        }
        if (node_one != nullptr) {
            node_one->parent = node_two->parent;
        }
        if (node_one->left != nullptr) {
            node_one->left->parent = node_two;
        }
        if (node_two->parent) {
            if (node_two != node_two->parent->left){
                node_two->parent->right = node_one;
            }
            else if (node_two == node_two->parent->left) {
                node_two->parent->left = node_one;
            }
        }
        else {
            root = node_one;
        }
        node_one->left = node_two;
    }
    //-------------------------------------------------------
    // Name: rotateright
    // PreCondition: to balance the rotation must be done for right side
    // PostCondition: does make the rotation by switching around for right side
    //---------------------------------------------------------
   
	void rotateright(Node* node_one){
        Node *node_two = node_one->left;
        node_one->left = node_two->right;
       
        if (node_one != nullptr) {
            node_one->parent = node_two;
        }
        if (node_two != nullptr){
            node_two->parent = node_one->parent;
        }
        if (node_two->right != nullptr) {
            node_two->right->parent = node_one;
        }
        if (node_one->parent) {
            if (node_one != node_one->parent->right){
                node_one->parent->left = node_two;
            }
            else if (node_one == node_one->parent->right) {
                node_one->parent->right = node_two;
            }
        }
        else{
            root = node_two;
        }
        node_two->right = node_one;
	}





    //-------------------------------------------------------
    // Name:remove
    // PreCondition: gives a remove value
    // PostCondition: returns a remove value from remove_helper
    //---------------------------------------------------------
	void remove(const Comparable& value){
    //    remove_helper(root, value);
    }
    //-------------------------------------------------------
    // Name:remove_helper
    // PreCondition: make a function to remove anywhere
    // PostCondition: does make a contain that is recursivly called from remove
    //---------------------------------------------------------
    ////////////////attempt at remove
    // void remove_helper(RedBlackTree*& x, const Comparable& item ) {
    //     if (x == nullptr) {
    //         return;
    //     }
    //     if (item < x->value) {
    //         remove_helper(x->left, item);
    //     }
    //     else if (item > x->value) {
    //         remove_helper(x->right, item);
    //     }
    //     else if (x->left != nullptr && x->right != nullptr) {
    //         x->value = node_min(x->right)->value;
    //         remove_helper(x->rightchildptr,x->node_obj);
    //     }
    //     else {
    //         RedBlackTree* temp = x;   
    //         if (x->left == nullptr) {
    //             x = x->rightchildptr;
    //         }
    //         else if(x->left != nullptr) {
    //             x = x->left;
    //         }
    //         delete temp;
    //     }      
    // }

    // Node* node_min(Node* p) {
    //     Node* current = p;
    //     while (current!= nullptr && current->left!= nullptr) {
    //         current = current->left;
    //     }
    //     return current;
    // }

    //-------------------------------------------------------
    // Name:find_min
    // PreCondition: gives a minimum value
    // PostCondition: returns a minimum value
    //---------------------------------------------------------
	const Comparable& find_min() const{
        if(root==nullptr){    
            throw std::invalid_argument("Empty Tree");
        }
        Node*newNode=root;
        while (newNode->left!=nullptr){
            newNode=newNode->left;
        }
        return newNode->value;
    }
    //-------------------------------------------------------
    // Name:find_max
    // PreCondition: gives a maximum value
    // PostCondition: returns a maximum value
    //---------------------------------------------------------
	const Comparable& find_max() const{
        if(root==nullptr){    
            throw std::invalid_argument("Empty Tree");
        }
        Node*newNode=root;
        while (newNode->right!=nullptr){
            newNode=newNode->right;
        }
        return newNode->value;
    }
    //-------------------------------------------------------
    // Name:print_tree
    // PreCondition: gives the tree image
    // PostCondition: returns the tree image
    //---------------------------------------------------------
	void print_tree(std::ostream& os=std::cout){
        if (root==nullptr){
            os<< "<empty>\n";
        }
        else{
            print_helper(root,0, os);
        }
    }
    //-------------------------------------------------------
    // Name:print_helper
    // PreCondition: make a function to print tree
    // PostCondition: does make a contain that is recursivly called from print
    //---------------------------------------------------------
    void print_helper(Node* t,size_t spaces, std::ostream& os=std::cout) const{
        if (t == nullptr) {
            return;
        }

        print_helper(t->right,spaces+2,os);
        for (size_t i=0;i<spaces;++i){
            os<<" ";
        }
        if (t->color == RED) {
            os <<"R:";
        }
        os << t->value << std::endl;
        print_helper(t->left,spaces+2,os);
    }
    //-------------------------------------------------------
    // Name:is_empty
    // PreCondition: checks if/if not empty
    // PostCondition: returns if/if not empty
    //---------------------------------------------------------
	bool is_empty() const{
        if (root==nullptr){
            return true;
        }
        return false;
    }
    //-------------------------------------------------------
    // Name:make_empty
    // PreCondition: makes if/if not empty
    // PostCondition: does empty the root from destroy_destructor
    //---------------------------------------------------------
	void make_empty(){
        destroy_destructor(root);
        root=nullptr;
    }

	// FOR TESTING ONLY - do not use these in your implementation
    //-------------------------------------------------------
    // Name:color
    // PreCondition: makes black in a scenario the node is nullptr
    // PostCondition: returns a default color value from enum
    //---------------------------------------------------------
    int color(const Node* node) const{
		if(node == nullptr)
			return BLACK;
		return node->color;
	}
    //-------------------------------------------------------
    // Name:get_root
    // PreCondition: get the root value or none
    // PostCondition: return the root value or null
    //---------------------------------------------------------
	const Node* get_root() const{
        if(root == nullptr)
			return nullptr;
		return root;
    }

};

#endif  // RED_BLACK_TREE_H