/*  C++ program to Count number of times a function is called  */

#include<iostream>
using namespace std;
class square
{
   public:
        square();

   private:
        int n,r, count;
        float n1,r1;
        public:
                void input();
          void calc();
                void display();
                
};

square::square(){
        count = 1;
}

 void square::input()
{
        cout<<"Enter an integer:";
        cin>>n;
        cout<<"Enter a float no.:";
        cin>>n1;
        count += 1;
        
}
 void square::calc()
{
        r=n*n;
        r1=n1*n1;
        count += 1;

}
void square::display()
{
        cout<<"Square of integer:"<<r;
        cout<<"\nSquare of float:"<<r1;
        cout<<count;
}
        

int main()
{
        square s;
        s.input();
        s.calc();
        s.display();
}