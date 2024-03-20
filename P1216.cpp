#if 0
#include<iostream>
using namespace std;
struct node 
{
	char value;
	bool flag;
	node* next;
};
class Stack 
{
private:
	node* head;
public:
	Stack() 
    {
		head = nullptr;
	}
	void push(char c) 
    {
		node* tmp = new node;
		tmp->value = c;
		tmp->flag = 0;
		tmp->next = head;
		head = tmp;
		return;
	}
	void pop() 
    {
		if (head == nullptr) return;
		node* tmp = head->next;
		delete head;
		head = tmp;
		return;
	}
	node* top() 
    {
		if (head == nullptr) return 0;
		return head;
	}
	bool empty() 
    {
		return head == nullptr;
	}
	void clear() 
    {
		while (head != nullptr) 
            pop();
		return;
	}
};

int main() 
{
	Stack sign;
	Stack check;
	int n = 0;
	scanf("%d", &n);
	char C = 'a';
	bool Flag = 0;
	int op = 0;
	for (int i = 0; i < n; i++) 
    {
		scanf("%d", &op);
		switch (op) 
        {
		    case 1:
                char c;
                char tool[10];
                scanf("%s", tool);
                c = tool[0];
                sign.push(c);
                //sign 内具有flag值进行后续操作。

                if (check.empty()) 
                {
                    check.push(c);
                    break;
                }
                //检查栈空时push进入。

                if (c == '[' || c == '{' || c == '(') 
                {
                    check.push(c);
                    sign.top()->flag = 0;
                    break;
                }
                //当输入为左括号的时候，进入并将flag设为0.
                switch (c) 
                {
                    case ')':
                        if (check.top()->value == '(') 
                        {
                            check.pop();
                            sign.top()->flag = 1;//成功匹配的，pop出check的栈且设为flag真。
                        }
                        else 
                        {
                            check.push(c);
                            sign.top()->flag = 0;//非成功匹配，设为假。
                        }
                    break;


                    case ']':
                        if (check.top()->value == '[') 
                        {
                            check.pop();
                            sign.top()->flag = 1;
                        }
                        else 
                        {
                            check.push(c);
                            sign.top()->flag = 0;
                        }
                    break;


                    case '}':
                        if (check.top()->value == '{')
                        {
                            check.pop();
                            sign.top()->flag = 1;
                        }
                        else 
                        {
                            check.push(c);
                            sign.top()->flag = 0;
                        }
                    break;
			    }
			break;
		case 2:
			if (sign.empty()) break;
			C = sign.top()->value;
			Flag = sign.top()->flag;
			sign.pop();
			switch (C) 
            {
			    case '{':
			    case '[':
			    case '(':
				    check.pop();//左括号在check中存在，直接pop。
				break;
			    default:
                    if (Flag) 
                    {
                        if (C == ')') check.push('(');
                        if (C == ']') check.push('[');
                        if (C == '}') check.push('{');//最重要的：pop为右括号时，先看是否匹配。如果匹配过的括号，则进行入栈，使得check栈不为空。
                        //空的时候则完全匹配。
                    }
				    else check.pop();//如果是不匹配的右括号，直接pop。
			}
			break;
		case 3:
			if (sign.empty()) break;
			printf("%c\n", sign.top()->value);
			break;
		case 4:
			if (check.empty()) printf("YES\n");//不再重新遍历栈，减少时间消耗。
			else printf("NO\n");
			break;
		}
	}
	sign.clear();
	return 0;
}
#endif