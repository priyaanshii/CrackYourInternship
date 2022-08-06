long long  multiplyTwoLists (Node* l1, Node* l2)
{
  long num1=0,num2=0;
  Node *first=l1,*second=l2;
  while(first || second)
  {
      if(first)
      {
          num1 = (num1 * 10 + first->data)%1000000007;;
          first = first->next;
      }
      if(second)
      {
          num2 = (num2 *10 +second->data)%1000000007;;
          second = second->next;
      }
  }
  
  return (num1 * num2)%1000000007;;
}
