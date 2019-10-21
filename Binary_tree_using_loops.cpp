#include <iostream>
using namespace std;
class Node
{
private:
int data;
Node *left;
Node *right;
public:
Node(int);
void set_data(int);
int get_data();
void set_left(Node*);
Node* get_left();
void set_right(Node*);
Node* get_right();
};
Node::Node(int data)
{
        this->data=data;
}
void Node::set_data(int data)
{
        this->data=data;
}
int Node::get_data()
{
        return data;
}
void Node::set_left(Node *ptr)
{
        left=ptr;
}
Node* Node::get_left()
{
        return left;
}
void Node::set_right(Node *ptr)
{
        right=ptr;
}
Node* Node::get_right()
{
        return right;
}
class Binary_tree
{
private:
Node *root;
public:
Binary_tree();
void add_value_in_binary_tree(int);
void display();
void display_help(Node*);
int search(int);
Node* remove_value(int);
void help_to_remove(Node*);
};
Binary_tree::Binary_tree()
{
        root=NULL;
}
void Binary_tree::add_value_in_binary_tree(int input)
{
        Node *temp2=new Node(input);
        Node *temp=root;
        if(temp==NULL)
        {
                root=temp2;
                return;
        }
        else if(temp->get_data()==input)
        {
                temp=temp2;
        }
        else
        {
                while(true)
                {
                        if(temp->get_data()==input)
                        {
                                temp=temp2;
                                return;
                        }
                        else if(temp->get_data()<input)
                        {
                                if(temp->get_right()==NULL)
                                {
                                        temp->set_right(temp2);
                                        return;
                                }
                                else
                                {
                                        temp=temp->get_right();
                                }
                        }
                        else if(temp->get_data()>input)
                        {
                                if(temp->get_left()==NULL)
                                {
                                        temp->set_left(temp2);
                                        return;
                                }
                                else
                                {
                                        temp=temp->get_left();
                                }
                        }
                }
        }
}
void Binary_tree::display()
{
        Node *temp=root;
        if(temp==NULL)
        {
                cout << "Binary tree is empty\n";
        }
        else
        {
                display_help(temp);
        }
}
void Binary_tree::display_help(Node *temp)
{
        if(temp->get_left()==NULL)//Look for last last left smaller value
        {
                cout << temp->get_data() << endl;
                if(temp->get_right()!=NULL) //check if there right node also exists
                        display_help(temp->get_right());
                return;//to return if no right node
        }
        display_help(temp->get_left());//move on branch for last left node
        cout << temp->get_data() << endl;//to display parent
        if(temp->get_right()!=NULL) //check if right node exists
                display_help(temp->get_right()); //mov forward on to search again for left
        return;//return if no more right nodes
}
int Binary_tree::search(int input)
{
        Node *temp=root;
        if(root==NULL)
        {
                cout << "Binary tree is empty\n";
                return 0;
        }
        else if(temp->get_data()==input)
        {
                return 1;
        }
        else
        {
                while(true)
                {
                        if(temp==NULL)
                        {
                                return -1;
                        }
                        else if(temp->get_data()==input)
                        {
                                return 1;
                        }
                        else if(temp->get_data()>input)
                        {
                                if(temp->get_left()==NULL)
                                {
                                        return -1;
                                }
                                else if(temp->get_left()->get_data()==input)
                                {
                                        return 1;
                                }
                                else
                                {
                                        temp=temp->get_left();
                                }
                        }
                        else if(temp->get_data()<input)
                        {
                                if(temp->get_right()==NULL)
                                {
                                        return -1;
                                }
                                else if(temp->get_right()->get_data()==input)
                                {
                                        return 1;
                                }
                                else
                                {
                                        temp=temp->get_right();
                                }
                        }
                }
        }
}
Node* Binary_tree::remove_value(int input)
{
        Node *temp=root;
        if(root==NULL)
        {
                cout << "Binary tree is empty\n";
                return NULL;
        }
        else if(temp->get_data()==input)
        {
                if(temp->get_left()==NULL&&temp->get_right()==NULL)
                {
                        cout << "Deletion is completed\n";
                        temp=NULL;
                        return NULL;
                }
                else
                {
                        return temp;
                }
        }
        else
        {
                while(true)
                {
                        if(temp==NULL)
                        {
                                return NULL;
                        }
                        else if(temp->get_data()==input)
                        {
                                if(temp->get_left()==NULL&&temp->get_right()==NULL)
                                {
                                        cout << "Deletion is completed\n";
                                        temp=NULL;
                                        return NULL;
                                }
                                else
                                {
                                        return temp;
                                }
                        }
                        else if(temp->get_data()>input)
                        {
                                if(temp->get_left()==NULL)//Check in advance for search
                                {
                                        return NULL;
                                }
                                else if(temp->get_left()->get_data()==input)
                                {
                                        Node *temp2=temp->get_left();
                                        if(temp2->get_left()==NULL&&temp2->get_right()==NULL)
                                        {
                                                cout << "Deletion is completed\n";
                                                temp->set_left(NULL);
                                                return NULL;
                                        }
                                        else
                                        {
                                                return temp->get_left();
                                        }
                                }
                                else
                                {
                                        temp=temp->get_left();
                                }
                        }
                        else if(temp->get_data()<input)
                        {
                                if(temp->get_right()==NULL)
                                {
                                        return NULL;
                                }
                                else if(temp->get_right()->get_data()==input)
                                {
                                        Node *temp2=temp->get_right();
                                        if(temp2->get_left()==NULL&&temp2->get_right()==NULL)
                                        {
                                                cout << "Deletion is completed\n";
                                                temp->set_right(NULL);
                                                return NULL;
                                        }
                                        else
                                        {
                                                return temp->get_right();
                                        }
                                }
                                else
                                {
                                        temp=temp->get_right();
                                }
                        }
                }
        }
}
void Binary_tree::help_to_remove(Node* temp)
{
        Node *temp2=temp;
        Node *temp3;
        while(true)
        {
                if(temp2->get_right()==NULL)
                {
                        while(true)
                        {
                                if(temp2->get_left()->get_left()==NULL)
                                {
                                        temp->set_data(temp2->get_left()->get_data()); //over write value of node you want to remove with most left of right
                                        temp2->set_left(NULL);
                                        return;

                                }
                                temp2=temp2->get_left();
                        }
                }
                else if(temp2->get_right()!=NULL)
                {
                        temp3=temp2;//for if left is found null
                        temp2=temp2->get_right();
                        while(true)
                        {
                                if(temp2->get_left()==NULL)
                                {
                                        temp->set_data(temp2->get_data()); //over write value of node you want to remove with most left of right
                                        temp3->set_right(temp2->get_right());
                                        return;
                                }
                                else if(temp2->get_left()->get_left()==NULL)
                                {
                                        temp->set_data(temp2->get_left()->get_data()); //over write value of node you want to remove with most left of right
                                        temp2->set_left(NULL);
                                        return;

                                }
                                temp2=temp2->get_left();
                        }
                }

        }
}
int main()
{
        Binary_tree object;
        while(true)
        {
                int option,input;
                cout << "****************************************\n";
                cout << "Enter 1 for insert value in binary tree\n";
                cout << "Enter 2 for display\n";
                cout << "Enter 3 for search value in binary tree\n";
                cout << "Enter 4 for remove value in binary tree\n";
                cout << "****************************************\n";
                cin >> option;
                if(option==1)
                {
                        cout << "Enter value to insert in binary tree\n";
                        cin >> input;
                        object.add_value_in_binary_tree(input);
                }
                else if(option==2)
                {
                        object.display();
                }
                else if(option==3)
                {
                        int check;
                        cout << "Enter value you want to search\n";
                        cin >> input;
                        check=object.search(input);
                        if(check==-1)
                        {
                                cout << "No match value is found in binary tree\n";
                        }
                        else if(check==1)
                        {
                                cout << "Yes value is matched in binary tree\n";
                        }
                }
                else if(option==4)
                {
                        Node *temp;
                        cout << "Enter value you want to remove\n";
                        cin >> input;
                        temp=object.remove_value(input);
                        if(temp!=NULL)
                        {
                                cout << "Here is i found " << temp->get_data() << endl;
                                object.help_to_remove(temp);
                        }
                }
        }
}
