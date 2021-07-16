#include<iostream>
#include <math.h>;
using namespace std;
class Node {
public:
	int data;
	Node* leftchild;
	Node* rightchild;
};
class BinarySearchTree {
public:
	Node* root;
	Node* loc = NULL;
	Node* ploc = NULL;
	int Nodeleft=0;
	int Noderight=0;
	int BothNode=0;
	int leaf=0;
	int p = 0;
	Node* ptemp = NULL;
	int i=-1;
	int max_size=0;
	bool isEmpty()
	{//To check wether tree is empty or not
		return(root == NULL);

	}
	void Search(int value)
	{//To search for a value in tree 
		//As a result loc and ploc will be updated
		ploc = NULL;
		loc = root;
		//seraches until value is found or tree ends
		while (loc != NULL && loc->data != value)
		{//ploc points to the previous node of loc
			ploc = loc;
			if (loc->data > value)
			{   //In BST,left side has small values and right side has larger
				loc = loc->leftchild;
			}
			else { loc = loc->rightchild; }
		}

	}
	void Insertion(int value)
	{//To insert values in tree
		Node* nn = new Node();
		//New node is created and assigned a value
		nn->data = value;
		if (isEmpty())
		{//If tree is empty newnode is made as root
			root = nn;
		}
		else {
			//otherwise loc and ploc finds for the logical position and insert it
			ploc = NULL;
			loc = root;
			while (loc != NULL)
			{
				if (loc->data > value)
				{
					ploc = loc;
					loc = loc->leftchild;
				}
				else
				{
					ploc = loc;
					loc = loc->rightchild;
				}
			}
			if (ploc->data > value)
			{
				ploc->leftchild = nn;
			}
			else { ploc->rightchild = nn; }

		}
	}
	void Insertwithoutduplicate(int data)
	{
		//Search is used to find logical position of node
		Search(data);
		if (loc == NULL)
		{
			Node* nn = new Node();
			nn->data = data;
			if (ploc != NULL)
			{
				if (ploc->data > data)
				{
					ploc->leftchild = nn;
				}
				else
				{
					ploc->rightchild = nn;
				}
			}
			else
			{
				root = nn;
			}

		}
		else { cout << "duplicate insertions are not allowed"; }

	}
	void PreOrderTraversal(Node* pointer)
	{   //In this function tree is traversed first its root than left and right subtree
		Node* temp;
		
		if(pointer!=NULL)
		{     cout << pointer->data << endl;
			  PreOrderTraversal(pointer->leftchild);
			  PreOrderTraversal(pointer->rightchild);
			
		}
	}
	void PostOrderTraversal(Node* pointer)
	{ //In this function tree is traversed first its left subtree then root and right subtree
		Node* temp;
		if (pointer == NULL)
		{
			//cout << "tree ends.....";
			return;
		}
		else
		{
			PostOrderTraversal(pointer->rightchild);
			cout << pointer->data;
			PostOrderTraversal(pointer->leftchild);
		}

	}
	void InOrderTraversal(Node* pointer)
	{//In this function tree is traversed first its left subtree  right subtree and then root 
		Node* temp;
		if (pointer == NULL)
		{
			return;
		}
		else
		{
			PreOrderTraversal(pointer->leftchild);
			PreOrderTraversal(pointer->rightchild);
			cout << pointer->data;

		}

	}
	void SmallestValue(Node* pointer)
	{//recursively calls until left leaf node is accessed  
		if (pointer == NULL)
		{
			cout << "The minimum value is " << ploc->data << endl;
			return;
		}
		else
		{
			ploc = pointer;
			SmallestValue(pointer->leftchild);
			//cout << "The minimum value is " << pointer;
		}

	}
	void LargestValue(Node* pointer)
	{//recursively calls until right leaf node is accessed  
		if (pointer == NULL)
		{
			cout << "The largest value is " << ploc->data << endl;
			return;
		}
		else
		{
			ploc = pointer;
			LargestValue(pointer->rightchild);
			//cout << "The largest value is " << pointer->data;
		}

	}
	/*void leftTraversal(Node* pointer)
	{
		if (pointer == NULL)
		{
			cout << lft;
			return;
		}
		else
		{
			lft++;
			leftTraversal(pointer->leftchild);
		}

	}
	void leftTraversal(Node* pointer)
	{
		if (pointer == NULL)
		{
			cout << lft;
			return;
		}
		else
		{
			lft++;
			leftTraversal(pointer->leftchild);
		}

	}*/
	int Height(Node* pointer)
	{//Function to traverse left and right subtree of node to find the height
		if (pointer == NULL)
		{
			return -1;
		}
		else
		{
			/*i++;
			if (max_size < i)
			{
				max_size = i;
			}
			Height(pointer->leftchild);
			i = max_size-1;

			Height(pointer->rightchild);
			//cout << max_size;*/
			return (1 + max(Height(pointer->leftchild), Height(pointer->rightchild)));
		}

	}
	int depth(Node* pointer, int depthoftree)
	{
		if (pointer == NULL)
		{
			return depthoftree;
		}
		else
		{
			int depth_ltree = depth(pointer->leftchild, depthoftree);
			int depth_rtree = depth(pointer->leftchild, depthoftree);
			return  max(depth_ltree, depth_rtree);
		}
	}
	/*void DeleteLeaf(Node* pointer)
	{
		if (pointer->leftchild == NULL && pointer->rightchild == NULL)
		{
			if (pointer == root)
			{
				root = NULL;
			}
			delete pointer;
		}
	}*/
	void DeleteSubTree(int pointer)
	{   
		Search(pointer);
        if (loc!= NULL)
		{//Case1: Delete Leaf Node
		if (loc->leftchild == NULL && loc->rightchild == NULL)
			{//leaf is also the root means tree has only one node
				if (ploc==NULL)
				{
					root = NULL;
				}
			//leaf is right child of parent
				else {
					if (ploc->rightchild == loc)
					{
						ploc->rightchild = NULL;
					}
					//leaf is leftchild of parent
					else { ploc->leftchild = NULL; }
				}
				//delete loc;
			}
		//Case2: Delete Node  with only left subtree
			if (loc->leftchild!= NULL && loc->rightchild == NULL)
			{
				
				if (ploc == NULL)
				{
					root = loc->leftchild;
				}
				else 
				{
					
					if (ploc->rightchild == loc)
					{
						ploc->rightchild = loc->leftchild;
					}
					if (ploc->leftchild == loc)
					{
						
					
						ploc->leftchild = loc->leftchild;
						
					}
				}
			}
		//Case2: Delete Node  with only right subtree
			if (loc->rightchild != NULL && loc->leftchild == NULL)
			{
				if (ploc == NULL)
				{
					root = loc->rightchild;
				}
				else
				{
					if (ploc->rightchild == loc)
					{
						ploc->rightchild = loc->rightchild;
					}
					if (ploc->leftchild == loc)
					{
						ploc->leftchild = loc->leftchild;
					}
				}
			}
		//Case4: Delete Node  with both subtree
			else
			{
				Node* ptemp = NULL;
				Node* temp = root;
				 
				while (temp != NULL)
				{
					 ptemp = temp;
					 temp = temp->rightchild;
				}
				if (ploc->leftchild == loc)
				{
			    ploc->leftchild = ptemp;
				ploc->leftchild->rightchild=loc->rightchild;
				}
				if (ploc->rightchild == loc)
				{
				ploc->rightchild = ptemp;
				ploc->rightchild->leftchild=loc->leftchild;
				}
			}
			delete loc;
		}
		else { cout << "Node is not in the tree"; }
	}
	
	//Correct
	void DestroyTree(Node* root)
	{
		if(root!=NULL){
			//ptemp = root;
			DestroyTree(root->leftchild);
			DestroyTree(root->rightchild);
			delete root;

		}
	}
	//Correct
	void PrintOnlyLeaf(Node* root)
	{
		
		if (root == NULL) { return; }
		if (root->leftchild == NULL && root->rightchild == NULL)
		{
			if (ptemp != NULL)
			{
				if (ptemp->rightchild == root)
				{
					cout<<ptemp->rightchild->data;
				}
				else { cout<<ptemp->leftchild->data; }
			}
			return;
		}
		else
		{
			ptemp = root;
			PrintOnlyLeaf(root->leftchild);
			PrintOnlyLeaf(root->rightchild);

		}
		
	}
	//Correct
	void Count(Node* root)
	{
		if (root== NULL)
		{
			return;
		}
		if (root->leftchild == NULL && root->rightchild ==NULL)
		{
			leaf++;	
		}
		if(root->leftchild == NULL && root->rightchild != NULL)
		{
			Noderight++;
		}
		if (root->leftchild != NULL && root->rightchild == NULL)
		{
			Nodeleft++;
		}
		if (root->leftchild != NULL && root->rightchild != NULL)
		{
			BothNode++;
		}
		Count(root->leftchild);
		Count(root->rightchild);
		/*cout << "leaf:"<<leaf;
		cout << "Noderight:" << Noderight; 
		cout << "Nodeleft:" << Nodeleft; 
		cout << "BothNode:" << BothNode;*/
	}
	//Correct
	void DeleteLeaf(Node* root)
	{
		
		if (root == NULL) { return; }
		if (root->leftchild == NULL && root->rightchild == NULL)
		{
			if (ptemp != NULL)
			{
				if (ptemp->rightchild== root)
				{
					ptemp->rightchild = NULL;
				}
				else { ptemp->leftchild = NULL; }
			}
	        delete root;
			return;
		}
		else
		{
			ptemp = root;
			DeleteLeaf(root->leftchild);
			DeleteLeaf(root->rightchild);
			
		}

	}
	void DestroyNode(Node* root) 
	{
		DestroyTree(root);
		root = NULL;
	}
	void OnlyLeftNode(Node* root) 
	{
		Node* temp =root;
		if (root == NULL)
		{
			return;
		}
		if (root->rightchild == NULL && root->leftchild!=NULL)
		{
			if (ptemp->leftchild == root)
			{
				ptemp->leftchild = root->leftchild;
			}
			else 
			{ 
				ptemp->rightchild = root->leftchild;
			}
			delete root;
			OnlyLeftNode(ptemp->leftchild);
			return;
		}
		else {
			ptemp = root;
			OnlyLeftNode(ptemp->leftchild);
			OnlyLeftNode(ptemp->rightchild);
		}
	
	}
};
int main()
{
	BinarySearchTree* bt = new  BinarySearchTree();
	bt->Insertion(8);
	bt->Insertion(4);
	//bt->Insertion(3);
	bt->Insertion(2);
	/*bt->Insertion(1);
	bt->Insertion(13);
	bt->Insertion(9);
	bt->Insertion(14);
	cout << "Before deleting all nodes having left subtree" << endl;
	bt->PreOrderTraversal(bt->root);
	//bt->OnlyLeftNode(bt->root);
	bt->DestroyNode(bt->root);
	cout << "After deleting" << endl;
	bt->PreOrderTraversal(bt->root);
	
}
/*bt->Count(bt->root);
cout << "leaf: " << bt->leaf << endl;
cout << "Noderight: " << bt->Noderight << endl;
cout << "Nodeleft: " << bt->Nodeleft << endl;
cout << "BothNode: " << bt->BothNode << endl;
*/
//cout << "After Destroying Tree" << endl;
	//bt->PreOrderTraversal(bt->root);
	//bt->Insertion(7);
	//bt->Insertion(5);
	//bt->Insertion(6);
	/*cout << "Before deleting node having both subtree which is 13" << endl;
	bt->PreOrderTraversal(bt->root);
	bt->DeleteSubTree(13);
	cout << "After deleting  node 13 " << endl;
	bt->PreOrderTraversal(bt->root);
	cout << "PreOrderTraversal" << endl;
	bt->PreOrderTraversal(bt->root);
	bt->LargestValue(bt->root);
	bt->SmallestValue(bt->root);*/
	//cout<<"The height is:"<<bt->Height(bt->root);
	//bt->DestroyTree(bt->root);
	//bt->root = NULL;
  //  bt->PreOrderTraversal(bt->root);
	//  bt->PrintOnlyLeaf(bt->root);
	/*bt->Count(bt->root);
	cout << "leaf:" <<bt-> leaf;
	cout << "Noderight:" <<bt-> Noderight;
	cout << "Nodeleft:" << bt->Nodeleft;
	cout << "BothNode:" << bt->BothNode;*/
	
    // bt->DeleteSubTree(13);

	/*bt->OnlyLeftNode(bt->root);
	cout << endl;
	bt->PreOrderTraversal(bt->root);
	//bt->PrintOnlyLeaf(bt->root);
	cout << endl;
	//bt->PreOrderTraversal(bt->root);*/
