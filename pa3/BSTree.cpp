
#include "BSTree.h"
#include <vector>

// input / output operators


ostream& operator<<(ostream& out, BSTree& tree){
  tree.print_level_by_level(out);
  return out;
};


ostream& operator<<(ostream& out, Node node){
   return out << "( " << node.value << ", "
	     << node.search_time << " )";
};

// read in a tree from a file
istream& operator>>(istream& in, BSTree& tree){
  int next;
  while(in >> next) 
    tree.insert(next);
  return in;
};

///////////// Implementation To Do ////////////////////

// copy constructor
BSTree::BSTree(const BSTree& other)
{
  /*
    complete this copy constructor
    make sure when copying nodes to copy
    the value and left and right children
  */
  if(other.root != nullptr){
    root = new Node(other.root->value);
    root->search_time = 1;
  }
    copy_helper(this->root, other.root);
    cout << "Copy Constructor worked" << endl;
}

// move constructor
BSTree::BSTree(BSTree&& other)
{
 if(other.root !=nullptr){
   root = other.root;
   size =  other.size;
   other.root = nullptr;
   size = 0;
 }

}

//copy assignment 
BSTree& BSTree::operator=(const BSTree& other)
{
  /*
    complete this assignment operator
    make sure when copying nodes to copy
    the value
    and left and right children
    not important for this part but will be used later
  */
 if(this!=&other){
   destory(root);
   if(other.root != nullptr){
    root = new Node(other.root->value);
    root->search_time = 1;
  }
    copy_helper(this->root, other.root);
    cout << "Copy Assgiment worked" << endl;
 }
 return *this;

}

// move assignment
BSTree BSTree::operator=(BSTree&& other)
{
 if(this!=&other){
   destory(root);
   root = other.root;
   size =  other.size;
   other.root = nullptr;
   size = 0;
 }
 return *this;

}
void BSTree::destory(Node *root)
{ 
if (root == nullptr) return; 
if (root->left != nullptr)
  destory(root->left);
if (root->right != nullptr)
  destory(root->right);
delete root;
}

// destructor
BSTree::~BSTree()
{
  destory(root);
  root = nullptr;
}

// recursive
void BSTree::copy_helper(Node* copy_to,
			 const Node* copy_from) const
{
  if(copy_from==nullptr){
    return;
  }
  if(copy_from->left !=nullptr){
    copy_to->left = new Node(*copy_from->left);
    copy_helper(copy_to->left, copy_from->left);
  } else {
    copy_to->left = nullptr;
  }
  if(copy_from->right !=nullptr){
    copy_to->right = new Node(*copy_from->right);
    copy_helper(copy_to->right, copy_from->right);
  } else {
    copy_to->right = nullptr;
  }

}
Node* BSTree::insert(int obj)
{
  /*
    insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node 
  */
 Node*newnode = new Node(obj);
 Node* temp = root;
 Node* y = nullptr;
 int searchCost = 1;
  while(temp!=nullptr){
     y = temp;
    if(obj < temp->value){
      temp = temp->left;
      searchCost++;
    } else{
      temp = temp->right;
      searchCost++;
    }  
  }
  if(y == nullptr){
    root = newnode;
    root->search_time = searchCost;
    size++;
  } else if(obj < y->value){
    y->left = newnode;
    newnode->search_time = searchCost;
    size++;
  } else {
    y->right = newnode;
    newnode->search_time = searchCost; 
    size++;
  }
  return nullptr;
}

Node* BSTree::search(int obj)
{
  /*
    recursivly search down the tree to find the node that contains obj
    if you dont find anything return null
  */
 Node*temp = root;
 while(temp!= nullptr){
   if(obj < temp->value){
     temp = temp->left;
   } else if(obj>temp->value){
     temp = temp->right;
   } else{
     return temp;
   }
 }
 return nullptr;
}
void BSTree::update_helper(Node*node, int depth){
  node->search_time = depth+1;
  depth++;
  if(node->left!=nullptr){
    update_helper(node->left,depth);
  }
  if(node->right!=nullptr){
    update_helper(node->right,depth);
  }

}
void BSTree::update_search_times()
{
    //do a BFS or DFS of your tree and update the searchtimes of all nodes
  update_helper(root,0);
}

void BSTree::inorder(ostream& out, Node*node)
{
  /*
    print your nodes in infix order
    if our tree looks like 

    4
    2 6
    1 3 5 7

    we should get

    1 2 3 4 5 6 7 
  */
  if(node!=nullptr){
  inorder(out,node->left);
  pretty_print_node(out,node);
  inorder(out,node->right);
  }
}

// implemented
void BSTree::pretty_print_node(ostream& out,Node* node)
{
  out << node->value << "["<<node->search_time<<"] ";
}

// implemented
ostream& BSTree::print_level_by_level(ostream& out)
{
  /*
    print the tree using a BFS 
    output should look like this if we dont have a full tree

    4
    2 6
    1 X 5 7
    X X X X X X X 9

    it will be helpfull to do this part iterativly, 
    so do the BFS with the std stack data structure.

    it may also be helpfull to put the entire tree into a vector 
    (probably google this if you dont know how to do it)
  */

  if(root == nullptr)
    return out;

  bool hasNodes = true;
  vector<Node*> current_level;
  vector<Node*> next_level;
  current_level.push_back(root);
  while(hasNodes) {
    hasNodes = false;
    for(auto node : current_level) {
      if(node != nullptr) {
        pretty_print_node(out, node);
        if(node->left != nullptr)
          hasNodes = true;
        if(node->right != nullptr)
          hasNodes = true;
        next_level.push_back(node->left);
        next_level.push_back(node->right);
      } else {
          out << "X ";
          next_level.push_back(nullptr);
          next_level.push_back(nullptr);
        }
    }
    out << endl;
    current_level.clear();
    current_level = next_level;
    next_level.clear();
  }

  return out;
}

// implemented
int BSTree::get_total_search_time(Node* node)
{
  if(node == nullptr)
    return 0;

  return get_total_search_time(node->left) + 
    get_total_search_time(node->right) +  node->search_time;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return -1;
	
  return ((float)total_search_time)/size;
}


