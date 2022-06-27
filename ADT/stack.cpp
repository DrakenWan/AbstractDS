/*
/////////////////// STACK IMPLEMENTATION //////////////////////
Date: 6/18/2019
Author: Kartikay Kaul

////////////////// +++++++++++++++++++++ //////////////////////
 */
#include<iostream>
#include<typeinfo>
#include<vector>

using namespace std;

template <typename S>
class stack {
    vector<S> content;
    int length;
    public:
        stack() {
            this->length = content.size();
        }
        stack(S value)
        {
            this->push(value);
        }

        void push(S value);
        int StackLength() {return this->length;}
        void clear();
        void toString();
        S pop();
        S peek();
};

template <typename S>
void stack<S>::push(S value)
{
    /*
        Push above the top of the stack
     */
    try {
        this->content.push_back(value);
        this->length = content.size();
    } catch(std::exception e)
    {
        cout<<"Error! Memory overflow!";
    }
}

template <typename S>
S stack<S>::pop()
 {
    /*
        Pop the top element of the stack
     */
    if(length != 0)
    {
    S value = this->content.back();
    cout<<"Deleted content value: "<<value;
    this->content.pop_back();
    this->length = content.size(); 
    return value; 
    }
    cout<<"Stack underflow.\n";
}

template <typename S>
 S stack<S>::peek()
 {
     /*
        Peek the top of the stack
      */
     if(this->length != 0)
        {
            S value = this->content.back();
            return value;
        }
     else {
         cout<<"\nStack Empty\n";
         S value;
         return value;
     }
 }

template <typename S>
void stack<S>::clear()
{
    /*
        Clear the stack contents
     */

    if(this->length != 0)
    {
        while(this->length != 0)
        {
            this->pop();
        }
        cout<<"Stack cleared.\n";
    }
    else
    {
        cout<<"Stack is already clear.\n";
    }
    
}

template <typename S>
void stack<S>::toString()
{
    /*
        shows string representation of the internal contents
     */

    cout<<"\n[";
    for(int i=0; i<length; i++)
    {
        if(i != length - 1)
            cout<<this->content[i]<<"->";
        else
            cout<<this->content[i]<<"(top)";
    }
    if(this->length == 0) cout<<"(empty)";
    cout<<"]\n";
}

int main()
{
    /*
        Run a stack implementation of any datatype below: be it string int or an object instance itself
        stack<datatype> instancevariablename
        You can experiment below with different methods of the object instance
     */
    
    stack<int> s1;
    s1.push(1);
    cout<<s1.peek();
    s1.push(10);
    s1.push(-1);
    s1.toString();
    
    stack<string> s2;
    s2.push("neeta");
    s2.push("sahil");
    s2.push("ike");
    s2.push("camila");
    s2.push("noora");
    s2.toString();
    s2.pop();
    s2.toString();
    return 0;
}
