#include <iostream>
#include<stack>
#include<string>
using namespace std;
class Reverse{
    private:
      string str;string rev;
    public:
      stack<char> st;
      void input(){
          cout<<"Enter the string\n";
          cin>>str;
      }
      void reversestring(){
          for(int i=0;i<str.length();i++)
            st.push(str[i]);
          for(int j=0;j<str.length();j++){
              rev+=st.top();
              st.pop();
          }
          cout<<"Reversed string: "<<rev<<endl;
      }
};
int main(){
    Reverse s;
    s.input();
    s.reversestring();
    return 0;
}