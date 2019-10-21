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
void help_to_insert_value(int);
void add_value_in_binary_tree(int,Node*,Node*);
void display_in_order();
void display_help_in_order(Node*);
void display_pre_order();
void display_help_pre_order(Node*);
void display_post_order();
void display_help_post_order(Node*);
void search(int,Node*);
void search_help(int);
void help_to_remove(int);
void remove_node_at_leaf(int,Node*);
void remove_most_critical_node(Node*);
};
Binary_tree::Binary_tree()
{
        root=NULL;
}
void Binary_tree::help_to_insert_value(int input)
{
        Node *temp=root;
        Node *temp2=new Node(input);
        add_value_in_binary_tree(input,temp,temp2);
}
void Binary_tree::add_value_in_binary_tree(int input,Node *temp,Node *temp2)
{
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
                                add_value_in_binary_tree(input,temp->get_right(),temp2);
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
                                add_value_in_binary_tree(input,temp->get_left(),temp2);
                        }
                }

        }
}
void Binary_tree::display_in_order()
{
        Node *temp=root;
        if(temp==NULL)
        {
                cout << "Binary tree is empty\n";
        }
        else
        {
                display_help_in_order(temp);
        }
}
void Binary_tree::display_help_in_order(Node *temp)
{
        if(temp==NULL)
        {
                return;
        }
        display_help_in_order(temp->get_left());
        cout << temp->get_data() << endl;
        display_help_post_order(temp->get_right());
}



void Binary_tree::display_pre_order()
{
        Node *temp=root;
        if(temp==NULL)
        {
                cout << "Binary tree is empty\n";
        }
        else
        {
                display_help_pre_order(temp);
        }
}
void Binary_tree::display_help_pre_order(Node *temp)
{
        if(temp==NULL)
        {
                return;
        }
        cout << temp->get_data() << endl;
        display_help_pre_order(temp->get_left());
        display_help_pre_order(temp->get_right());
}


void Binary_tree::display_post_order()
{
        Node *temp=root;
        if(temp==NULL)
        {
                cout << "Binary tree is empty\n";
        }
        else
        {
                display_help_post_order(temp);
        }
}
void Binary_tree::display_help_post_order(Node *temp)
{
        if(temp==NULL)
        {
                return;
        }
        display_help_post_order(temp->get_left());
        display_help_post_order(temp->get_right());
        cout << temp->get_data() <<endl;
}
void Binary_tree::search_help(int input)
{
        Node *temp=root;
        search(input,temp);
}
void Binary_tree::search(int input,Node *temp)
{
        if(root==NULL)
        {
                cout << "Binary tree is empty\n";
                return;
        }
        else if(temp->get_data()==input)
        {
                cout << "Value is found in binary tree\n";
                return;
        }
        else
        {
                if(temp==NULL)
                {
                        cout << "Value is not found in binary tree\n";
                        return;
                }
                else if(temp->get_data()==input)
                {
                        cout << "Value is found in binary tree\n";
                        return;
                }
                else if(temp->get_data()>input)
                {
                        if(temp->get_left()==NULL)
                        {
                                cout << "Value is not found in binary tree\n";
                                return;
                        }
                        else if(temp->get_left()->get_data()==input)
                        {
                                cout << "Value is found in binary tree\n";
                                return;
                        }
                        else
                        {
                                search(input,temp->get_left());

                        }
                }
                else if(temp->get_data()<input)
                {
                        if(temp->get_right()==NULL)
                        {
                                cout << "Value is not found in binary tree\n";
                                return;
                        }
                        else if(temp->get_right()->get_data()==input)
                        {
                                cout << "Value is found in binary tree\n";
                                return;
                        }
                        else
                        {
                                search(input,temp->get_right());
                        }
                }

        }
}
void Binary_tree::help_to_remove(int input)
{
        Node *temp=root;
        remove_node_at_leaf(input,temp);
}
void Binary_tree::remove_node_at_leaf(int input,Node *temp)
{
        if(root==NULL)
        {
                cout << "Binary tree is empty\n";
                return;
        }
        else if(temp->get_data()==input)
        {
                if(temp->get_left()==NULL&&temp->get_right()==NULL)
                {
                        cout << "Deletion is completed\n";
                        root=NULL;
                        return;
                }
                else
                {
                        remove_most_critical_node(temp);
                        return;
                }
        }
        else
        {
                if(temp==NULL)
                {
                        return;
                }
                else if(temp->get_data()==input)
                {
                        if(temp->get_left()==NULL&&temp->get_right()==NULL)
                        {
                                cout << "Deletion is completed\n";
                                temp=NULL;
                                return;
                        }
                        else
                        {
                                remove_most_critical_node(temp);
                                return;
                        }
                }
                else if(temp->get_data()>input)
                {
                        if(temp->get_left()==NULL)        //Check in advance for search
                        {
                                return;
                        }
                        else if(temp->get_left()->get_data()==input)
                        {
                                Node *temp2=temp->get_left();
                                if(temp2->get_left()==NULL&&temp2->get_right()==NULL)
                                {
                                        cout << "Deletion is completed\n";
                                        temp->set_left(NULL);
                                        return;
                                }
                                else
                                {
                                        remove_most_critical_node(temp->get_left());
                                        return;
                                }
                        }
                        else
                        {
                                remove_node_at_leaf(input,temp->get_left());
                        }
                }
                else if(temp->get_data()<input)
                {
                        if(temp->get_right()==NULL)        //shows no value is found there
                        {
                                return;
                        }
                        else if(temp->get_right()->get_data()==input)
                        {
                                Node *temp2=temp->get_right();
                                if(temp2->get_left()==NULL&&temp2->get_right()==NULL)
                                {
                                        cout << "Deletion is completed\n";
                                        temp->set_right(NULL);
                                        return;
                                }
                                else
                                {
                                        remove_most_critical_node(temp->get_right());
                                        return;
                                }
                        }
                        else
                        {
                                remove_node_at_leaf(input,temp->get_right());
                        }
                }

        }
}
void Binary_tree::remove_most_critical_node(Node* temp)
{
        Node *temp2=temp;
        Node *temp3;
        if(temp2->get_right()==NULL)
        {
                if(temp2->get_left()->get_left()==NULL)
                {
                        temp->set_data(temp2->get_left()->get_data());                 //over write value of node you want to remove with most left of right
                        temp2->set_left(NULL);
                        return;
                }
                remove_most_critical_node(temp2->get_left());
        }
        else if(temp2->get_right()!=NULL)
        {
                temp3=temp2;        //for if left is found null
                temp2=temp2->get_right();
                if(temp2->get_left()==NULL)
                {
                        temp->set_data(temp2->get_data());                 //over write value of node you want to remove with most left of right
                        temp3->set_right(temp2->get_right());
                        return;
                }
                else if(temp2->get_left()->get_left()==NULL)
                {
                        temp->set_data(temp2->get_left()->get_data());                 //over write value of node you want to remove with most left of right
                        temp2->set_left(NULL);
                        return;

                }
                remove_most_critical_node(temp2->get_left());
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
                cout << "Enter 2 for display in order\n";
                cout << "Enter 3 for search value in binary tree\n";
                cout << "Enter 4 for remove value in binary tree\n";
                cout << "Enter 5 for display pre order\n";
                cout << "Enter 6 for display post order\n";
                cout << "****************************************\n";
                cin >> option;
                if(option==1)
                {
                        cout << "Enter value to insert in binary tree\n";
                        cin >> input;
                        object.help_to_insert_value(input);
                }
                else if(option==2)
                {
                        object.display_in_order();
                }
                else if(option==3)
                {
                        cout << "Enter value you want to search\n";
                        cin >> input;
                        object.search_help(input);
                }
                else if(option==4)
                {
                        cout << "Enter value you want to remove\n";
                        cin >> input;
                        object.help_to_remove(input);
                }
                else if(option==5)
                {
                        object.display_pre_order();
                }
                else if(option==6)
                {
                        object.display_post_order();
                }
        }
}
