#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#define MAXIMUM_SIZE 100
class Stack{  
  private:
  int* arr;
  int top;
  public:
  Stack(){
    arr = NULL;
    top = -1;
  }
  ~Stack(){
    delete[] arr;
  }
  void push(int a){
    if(top == -1){
      arr = new int[100];
    }
    top += 1;
    arr[top] = a;
  }
  int pop(){
    int oprand = arr[top--];
    return oprand;
  }
  bool enough_operands(){
    if(top < 1) return false;
    else return true;
  }
  bool push_peek(){
    //if (top == -1) return false;
    if(top == MAXIMUM_SIZE) return false;
    else return true;
  }
  int is_operator(int a,int b,char* c){
    switch(*c){
      case '+':
      return b + a;
      case '-':
      return b-a;
      case '*':
      return b*a;
      case '/':
      if (a == 0) break;
      return b/a;
    }
  }
  void printer(){
    for(int i = 0; i < top; i++){
      cout << arr[i] << endl;
    }
  }
}
int main(){
  Stack stacky;
  char c;
  while(std::cin.get(c)){
    int num = 0;
    if(std::isdigit(c)){
      while(std::isdigit(c)){
        num = num * 10 + c - '0';
        std::cin.get(c);
      }
      std::cin.unget();
      if(stacky.push_peek()) stacky.push(num);
      else return -1;
}
else if (strchr("+-*/",c)!=  NULL){
  if(stacky.top < 1){
    return -1
  }
  int op1 = stacky.pop();
  int op2 = stack.pop();
  char op = c;
  int result = stacky.is_operator(op1,op2,&c);
  if(stacky.push_peek()) push(result);
}
}
return 0;
}
