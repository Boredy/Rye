#include "BSTY.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

BSTY::BSTY() {
    root = NULL;

}

// You write:  insert a new node with data x (a string) into the
// binary search tree
// This method should return true if a new node is inserted and
// false if the data x is already in the tree
// Remember to check whether the new node will be the root
// (meaning the root is currently NULL) and if so, set the root
// to be the new node.
// Note: Make sure you make the new node point to its parent!!!
// Note2: after you've inserted a new node, you should call the
// adjustHeights method that will update the heights of all the
// ancestors of the node that was just inserted.
bool BSTY:: insertit(string x) {
    if (root == NULL) {
        root = new NodeT(x);
        return true;
    } else {
        NodeT* n = root;
        while (n != NULL) {
            if (x < n->data) {
                if (n->left == NULL) {
                    NodeT* tmp = new NodeT(x);
                    n->left = tmp;
                    tmp->parent = n;
                    adjustHeights(tmp);
                    return true;
                } else {
                    n = n->left;
                }
            } else if (x > n->data) {
                if (n->right == NULL) {
                    NodeT* tmp = new NodeT(x);
                    n->right = tmp;
                    tmp->parent = n;
                    adjustHeights(tmp);
                    return true;
                } else {
                    n = n->right;
                }
            } else {
                return false;
            }
        }
    }
    return false;
}

bool BSTY:: insertit(string x, string d) {
    if (root == NULL) {
        root = new NodeT(x,d);
        return true;
    } else {
        NodeT* n = root;
        while (n != NULL) {
            if (x < n->data) {
                if (n->left == NULL) {
                    NodeT* tmp = new NodeT(x,d);
                    n->left = tmp;
                    tmp->parent = n;
                    adjustHeights(tmp);
                    return true;
                } else {
                    n = n->left;
                }
            } else if (x > n->data) {
                if (n->right == NULL) {
                    NodeT* tmp = new NodeT(x,d);
                    n->right = tmp;
                    tmp->parent = n;
                    adjustHeights(tmp);
                    return true;
                } else {
                    n = n->right;
                }
            } else {
                return false;
            }
        }
    }
    return false;
}

// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have
// this working now.  It should be called whenever you change the height of a
// a particular node.  So, for instance, when a new node is inserted as a leaf,
// its height is 1. The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of
// the height of the left child and the height of the right child, plus 1).  If
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.
void BSTY::adjustHeights(NodeT *n) {
    if (n == NULL) {
        return;
    } else {
        if (n->left == NULL && n->right == NULL) {
            n->height = 1;
        } else if (n->left == NULL && n->right != NULL) {
            n->height = 1 + n->right->height;
        } else if (n->left != NULL && n->right == NULL) {
            n->height = 1 + n->left->height;
        } else {
            n->height = max(n->left->height, n->right->height) + 1;
        }
        
        //check for balance and if necessary rotate accordingly
        if (findBalance(n) >= 2) {
            if (findBalance(n->left) >= 1) {
                cout<< n->data << " must rotate right (" << findBalance(n) << ")" <<endl;
                rotateRight(n);
            } else if (findBalance(n->left) <= -1) {
                cout<< n->left->data << " child, rotating left" <<endl;
                rotateLeft(n->left);
            }
        } else if (findBalance(n) <= -2) {
            if (findBalance(n->right) <= -1) {
                cout<< n->data << " must rotate left (" << findBalance(n) << ")" <<endl;
                rotateLeft(n);
            } else if (findBalance(n->right) >= 1) {
                cout<< n->right->data << " child, rotating right" <<endl;
                rotateRight(n->right);
            }
        }
        adjustHeights(n->parent);
    }
}

void BSTY::printTreeIO() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        printTreeIO(root);
    }
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is
// traversed in order
void BSTY::printTreeIO(NodeT *n) {
    if (n == NULL) {
        return;
    } else {
        printTreeIO(n->left);
        n->printNode();
        printTreeIO(n->right);
    }
}

void BSTY::printTreePre() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        printTreePre(root);
    }
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) {
    if (n == NULL) {
        return;
    } else {
        n->printNode();
        printTreePre(n->left);
        printTreePre(n->right);
    }
}

void BSTY::printTreePost() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        printTreePost(root);
        cout << endl;
    }
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) {
    if (n == NULL) {
        return;
    } else {
        printTreePost(n->left);
        printTreePost(n->right);
        n->printNode();
    }
}

void BSTY::myPrint() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        myPrint(root);
        cout << endl;
    }
}
void BSTY::myPrint(NodeT *n) {
    if (n == NULL) {
        return;
    }
    else {
        myPrint(n->left);
        cout << n->data.length()-1;
        if (mine) {
            cout <<".";
            mine = false;
        }
        myPrint(n->right);
    }
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.
NodeT *BSTY::find(string x) {
    int counter = 1;
    if (root == NULL) {
        cout<< "The tree is empty" <<endl;
        return NULL;
    } else {
        NodeT *n = root;
        while (n != NULL) {
            if (n->data == x) {
            	counter++;
            	cout<<counter<<": ";
                n->printNode();
                return n;
            } else if (x < n->data) {
                n = n->left;
                counter++;
            } else {
                n = n->right;
                counter++;
            }
        }
    }
    cout<<x<<" not found"<<endl;
    return NULL;
}

/*************************************************************************************/
/* Extra Credit Methods                                                              */
/* Challenging: worth 35 EC pts to go towards labs                                   */
/* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR */
/* UNDERSTANDING HOW THEY WORK!!                                                     */
/*************************************************************************************/
/* When removing a node from a binary search tree, the resulting tree MUST BE a binary
 * search tree.
 *
 * When removing a node, there are 3 conditions:
 * 1: when the node being removed has no children, in which case the node is deleted,
 * the node's parent is set to NULL, and the node's parent's height is adjusted (if
 * necessary) and heights on up are adjusted.
 * 2: when the node being removed has one child, in which case the node's parent points
 * to the node's child, and the node's child points to the node's parent, and the node
 * is deleted (and the height of the parent on up as necessary is adjusted)
 * 3: when the node has 2 children, in which case the left-most child of the node's
 * right child replaces the node.
 * A couple of notes about this one: you are replacing a node with a node that is lower
 * down in the tree.  That means that you are, in essence, removing the node from that
 * lower position and moving it up to the old node's location.  Thus the replacing node
 * must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after
 * the replacing node is removed from its old location but before it is inserted into its
 * new location.  Equally, the replacing node's height must be adjusted to be the larger of
 * its two children's heights before you adjust heights above that.
 *****************************************************************************************/
/* remove(): takes as input a string, uses the find method to find the node in the tree that
 * holds that string, and then calls replace1, replace2, or replace3 depending on what type
 * of replacing should be done.  It adjusts the heights, deletes the node, and returns
 * true if the removal was successful.
 */
bool BSTY::remove(string s) {
    NodeT *tmp;
    if (root == NULL) {
        return false;
    }
    tmp = this->find(s);
    if (tmp->left == NULL && tmp->right == NULL) {
        remove1(tmp);
        return true;
    }
    if (tmp->left == NULL || tmp->right == NULL) {
        remove2(tmp);
        return true;
    }
    if (tmp->left != NULL && tmp->right != NULL) {
        remove3(tmp);
        return true;
    }
    return false;
}

/* remove1(): called when the node to be removed has no children. Takes as input the
 * node to be removed, and sets the parent of the node to point to NULL.
 * helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
 * Make sure you check to whether n is the root or not.
 */
void BSTY::remove1(NodeT *n) {
    if (n == root) {
        root = NULL;
        delete root;
    } else {
        if (n->parent->left == n) {
            n->parent->left = NULL;
            NodeT* pnode = n->parent;
            delete n;
            adjustHeights(pnode);
        } else {
            n->parent->right = NULL;
            NodeT* pnode2 = n->parent;
            delete n;
            adjustHeights(pnode2);
        }
    }
}

/* remove2(): called when the node to be removed has 1 child only.  Takes as input
 * the node to be removed and bypasses it by making the parent point to the node's
 * one child, and makes the node's one child point to the node's parent.
 * This one needs a bunch of checking - you need to see if the node is the parent's
 * left or right child, and you need to see if the node's child is its left or its
 * right child.
 * Also, make sure you check that if the node to be removed is the root, then the
 * one child becomes the root.
 */
void BSTY::remove2(NodeT *n) {
    if (n == root) {
        if (root->left == NULL && root->right != NULL) {
            NodeT* tmp = n->right;
            delete n;
            root = tmp;
            adjustHeights(n);
            
        } else if (root->left != NULL && root->right == NULL) {
            NodeT* tmp = n->left;
            delete n;
            root = tmp;
            adjustHeights(n);
            
        }
    } else {
        if (n->parent != NULL) {
            if (n->right == NULL && n->left != NULL) {
                n->parent->left = n->left;
                n->left->parent = n->parent;
                adjustHeights(n->parent);
                n->parent = NULL;
                delete n;
            } else if (n->right == NULL && n->left != NULL) {
                n->parent->right = n->right;
                n->right->parent = n->parent;
                adjustHeights(n->parent);
                n->parent = NULL;
                delete n;
            }
        }
    }
}

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
 * node to be removed.  The node to replace the node to be removed should be the
 * left-most descendant of the node's right child.  That way the binary search tree
 * properties are guaranteed to be maintained.
 * When replacing the node to be removed with the replacing node, the replacing node
 * is, in essence, being removed from its place in the tree, and thus replace1 or
 * replace2 methods should be used.
 * The new node's parent must be set to the removed node's parent, the removed node's
 * parent must point to the new node, the new node's left child must point to the
 * removed node's left child (and the child must point to the new node as a parent),
 * and the same for the right child.
 * Remember to take into account that the node being removed might be the root.
 */
void BSTY::remove3(NodeT *n) {
    if (n == root) {
        NodeT* tmp = findMin(root);
        root->data = tmp->data;
        
        if (tmp->right == NULL && tmp->left == NULL) {
            remove1(tmp);
        }
        if (tmp->right == NULL || tmp->left == NULL) {
            remove2(tmp);
        }
        
    } else {
        NodeT* tmp = findMin(n);
        n->data = tmp->data;
        
        if (tmp->right == NULL && tmp->left == NULL) {
            remove1(tmp);
        }
        if (tmp->right == NULL || tmp->left == NULL) {
            remove2(tmp);
        }
        
    }
}

/* findMin(): takes as input a node, and finds the left-most descendant of its
 * right child.  The left-most descendant is returned.
 */
NodeT *BSTY::findMin(NodeT *n) {
    if (root == NULL) {
        cout<< " The tree is empty" <<endl;
        return NULL;
    } else {
        n = n->right;
        while (n->left != NULL) {
            n = n->left;
        }
        return n;
    }
}

void BSTY::myPrintEC() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        myPrintEC(root);
        cout << endl;
    }
}
void BSTY::myPrintEC(NodeT *n) {
    if (n == NULL) {
        return;
    }
    else {
        myPrintEC(n->left);
        cout << alpha[n->data.length()-2];
        myPrintEC(n->right);
    }
}

NodeT* BSTY::rotateRight(NodeT* n) {
	NodeT* tmp = n->left;
	if (n == root) {
		if (tmp->right != NULL) {
			tmp->right->parent = n;
			n->left = tmp->right;
			tmp->right = n;
			root = tmp;
			n->parent = tmp;
			tmp->parent = NULL;

		} else {
			tmp->right = n;
			n->left = NULL;
			n->parent = tmp;
			tmp->parent = NULL;
			root = tmp;
		}
	} else {
		if (tmp->right != NULL) {
			tmp->right->parent = n;
			n->left = tmp->right;
		} else if (tmp->right == NULL) {
			n->left = NULL;
		}

		if (n->parent->right == n) {
			n->parent->right = tmp;
			tmp->parent = n->parent;
			n->parent = tmp;
			tmp->right = n;
		} else if (n->parent->left == n) {
			n->parent->left = tmp;
			tmp->parent = n->parent;
			n->parent = tmp;
			tmp->right = n;
		}
	}
    adjustHeights(n);
    return tmp;
}

NodeT* BSTY::rotateLeft(NodeT* n) {
    NodeT* tmp = n->right;
    if (n == root) {
        if (tmp->left != NULL) {
            tmp->left->parent = n;
            n->right = tmp->left;
            tmp->left = n;
            root = tmp;
            tmp->parent = NULL;
            n->parent = tmp;
        } else {
            tmp->left = n;
            n->right = NULL;
            root = tmp;
            tmp->parent = NULL;
            n->parent = tmp;
        }
    } else {
        if (tmp->left != NULL) {
            n->right = tmp->left;
            tmp->left->parent = n;
        } else if (tmp->left == NULL) {
            n->right = NULL;
        }

        if (n->parent->right == n) {
            n->parent->right = tmp;
            tmp->parent = n->parent;
            n->parent = tmp;
            tmp->left = n;
        } else if (n->parent->left == n) {
            n->parent->left = tmp;
            tmp->parent = n->parent;
            n->parent = tmp;
            tmp->left = n;
        }
    }
    adjustHeights(n);
    return tmp;
}

int BSTY::findBalance(NodeT* n) {
    if (n->left == NULL && n->right == NULL) {
        return 0;
    } else if (n->right == NULL && n->left != NULL) {
        return n->left->height;
    } else if (n->left == NULL && n->right != NULL) {
        return 0 - n->right->height;
    }
    return n->left->height - n->right->height;
}

/************************************************************************/
