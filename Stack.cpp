#include <iostream>
#include <string>
using namespace std;
const int array_size = 10;
struct stack 
{
public:
	int top = -1;
	int stack[array_size];
};
class Implement
{
 public:
	string str;
	bool IsEmpty(struct stack* pointer)
	{
		if (pointer->top == -1)
		{
			cout << "stack underflow";
			return true;
		}
		else { return false; }
	}
	bool IsFull(struct stack* pointer)
	{
		if (pointer->top == array_size)
		{
			cout << "stack overflow";
			return true;
		}
		else
		{
			return false;
		}
	}
	void Push(struct stack* pointer, int value)
	{
		pointer->top++;
		pointer->stack[pointer->top] = value;
	}
int Top(struct stack* pointer)
	{
		if (IsEmpty(pointer))
		{
			return NULL;
		}
		else
			return (pointer->stack[pointer->top]);
	}
	int pop(struct stack* pointer)
	{
		return (pointer->stack[pointer->top--]);
	}
	
	/*void BalanceBrackets(struct stack* p,string exp)
	{
		char ch;
		for (int i = 0; i < exp.length(); i++)
		{

		 if (exp[i] == '(' || exp[i] == '{' || exp[i]== '[')
		 {  ch=exp[i];
			Push(p,ch);}

		 switch (exp[i])
		 { ch = Top(p);
		   case ')':
		   {
			 if (ch == '{' || ch == '[')
			 {
				 cout << "do not matching brackets";
				 break;
			 }
			 if (ch=='(')
			 {
				 pop(p);
				 continue;
			 }
		   }
		 case '}':
		 {

			 if (ch == '[' || ch == '(')
			 {
				 cout << "do not matching brackets";
				 break;
			 }
			 if (ch == '{')
			 {
				 pop(p);
				 continue;
			 }


		 }

		 case']':
		 {
			 pop(p);
			 if (ch == '{' || ch == '(')
			 {
				 cout << "do not matching brackets";
				 break;
			 }
			 if (ch == '[')
			 {
				 continue;
			 }
		 }

		 }
		}
	}
	//Function to return precedence of operators
	/*int prec(char c)
	{
		if (c == '^')
			return 3;
		else if (c == '*' || c == '/')
			return 2;
		else if (c == '+' || c == '-')
			return 1;
		else
			return -1;
	}
	*/
	// The main function to convert infix expression 
	//to postfix expression 
	/*void infixToPostfix(struct stack* pointer, string s)
	{

		Push(pointer,'N');
		int l = s.length();
		string ns;
		for (int i = 0; i < l; i++)
		{

			// If the scanned character is
			// an operand, add it to output string.
			if ((s[i] >= 'a' && s[i] <= 'z') ||
				(s[i] >= 'A' && s[i] <= 'Z'))
				ns += s[i];

			// If the scanned character is an
			// ‘(‘, push it to the stack.
			else if (s[i] == '(')

				Push(pointer,'(');

			// If the scanned character is an ‘)’,
			// pop and to output string from the stack
			// until an ‘(‘ is encountered.
			else if (s[i] == ')')
			{
				while (Top(pointer) != 'N' && Top(pointer) != '(')
				{
					char c = Top(pointer);
					pop(pointer);
					ns += c;
				}
				if (Top(pointer) == '(')
				{
					char c = Top(pointer);
					pop(pointer);
				}
			}

			//If an operator is scanned
			else {
				while (Top(pointer) != 'N' && prec(s[i]) <=
					prec(Top(pointer)))
				{
					char c = Top(pointer);
					pop(pointer);
					ns += c;
				}
				Push(pointer,s[i]);
			}

		}

		// Pop all the remaining elements from the stack
		while (Top(pointer) != 'N')
		{
			char c = Top(pointer);
			pop(pointer);
			ns += c;
		}

		cout << ns << endl;

	}
	int operation(int a, int b, char opr) {
		switch (opr) {
		case '+':return a + b;
		case '-':return a - b;
		case '*':return a * b;
		case '/':return a / b;
		default: return 0;
		}
	}
	int precedence(char op) {
		if (op == '+' || op == '-')
			return 1;
		if (op == '*' || op == '/')
			return 2;
		return 0;
	}

	// Function to perform arithmetic operations.
	int applyOp(int a, int b, char op) {
		switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
		}
	}*/

	// Function that returns value of
	// expression after evaluation.
	/*int evaluate(string tokens) {
		int i;

		// stack to store integer values.
		stack <int> values;

		// stack to store operators.
		stack <char> ops;

		for (i = 0; i < tokens.length(); i++) {

			// Current token is a whitespace,
			// skip it.
			if (tokens[i] == ' ')
				continue;

			// Current token is an opening
			// brace, push it to 'ops'
			else if (tokens[i] == '(') {
				ops.push(tokens[i]);
			}

			// Current token is a number, push
			// it to stack for numbers.
			else if (isdigit(tokens[i])) {
				int val = 0;

				// There may be more than one
				// digits in number.
				while (i < tokens.length() &&
					isdigit(tokens[i]))
				{
					val = (val * 10) + (tokens[i] - '0');
					i++;
				}

				values.push(val);

				// right now the i points to
				// the character next to the digit,
				// since the for loop also increases
				// the i, we would skip one
				//  token position; we need to
				// decrease the value of i by 1 to
				// correct the offset.
				i--;
			}

			// Closing brace encountered, solve
			// entire brace.
			else if (tokens[i] == ')')
			{
				while (!ops.empty() && ops.top() != '(')
				{
					int val2 = values.top();
					values.pop();

					int val1 = values.top();
					values.pop();

					char op = ops.top();
					ops.pop();

					values.push(applyOp(val1, val2, op));
				}

				// pop opening brace.
				if (!ops.empty())
					ops.pop();
			}

			// Current token is an operator.
			else
			{
				// While top of 'ops' has same or greater
				// precedence to current token, which
				// is an operator. Apply operator on top
				// of 'ops' to top two elements in values stack.
				while (!ops.empty() && precedence(ops.top())
					>= precedence(tokens[i])) {
					int val2 = values.top();
					values.pop();

					int val1 = values.top();
					values.pop();

					char op = ops.top();
					ops.pop();

					values.push(applyOp(val1, val2, op));
				}

				// Push current token to 'ops'.
				ops.push(tokens[i]);
			}
		}

		// Entire expression has been parsed at this
		// point, apply remaining ops to remaining
		// values.
		while (!ops.empty()) {
			int val2 = values.top();
			values.pop();

			int val1 = values.top();
			values.pop();

			char op = ops.top();
			ops.pop();

			values.push(applyOp(val1, val2, op));
		}

		// Top of 'values' contains result, return it.
		return values.top();
	}*/




	void calculatePostfix(struct stack* pointer, string exp)
	{
		char ch;
		int op1;
	    int  op2;
		string temp;
		int result;
		for (int i = 0; i < exp.length(); i++)
		{
			ch = exp[i];
			cout << ch << endl;
			if (ch >= '0' && ch <= '9')
			{   while (ch != '|')
				{
				  temp = ch + temp;
				}
			     stoi(temp);
				 cout << stoi(temp);
				 Push(pointer, stoi(temp));
			}
			else
			{
				if (!IsEmpty(pointer))
				{
					if (ch == '+')
					{
						
							op1 = pop(pointer);
							cout << op1 << endl;
							op2 = pop(pointer);
							cout << op2 << endl;
						    result =(op1) + (op2);
						     cout << result << endl;
						     Push(pointer, result);
					}
					/*if (ch == '-')
					{
						for (int i = 0; i < exp.length(); i++)
						{
							while (Top(pointer) != ' ')
							{
								op1 = pop(pointer);
							}
							break;
						}
						for (int i = 0; i < exp.length(); i++)
						{
							while (Top(pointer) != ' ')
							{
								op1 = pop(pointer);
							}
							break;
						}
						result = stoi(op1) - stoi(op2);
						Push(pointer, char(result));
					}
					if (ch == '*')
					{
						for (int i = 0; i < exp.length(); i++)
						{
							while (Top(pointer) != ' ')
							{
								op1 = pop(pointer);
							}
							break;
						}
						for (int i = 0; i < exp.length(); i++)
						{
							while (Top(pointer) != ' ')
							{
								op1 = pop(pointer);
							}
							break;
						}
						result = stoi(op1) * stoi(op2);
						Push(pointer, char(result));
					}
					if (ch == '/')
					{
						for (int i = 0; i < exp.length(); i++)
						{
							while (Top(pointer) != ' ')
							{
								op1 = pop(pointer);
							}
							break;
						}
						for (int i = 0; i < exp.length(); i++)
						{
							while (Top(pointer) != ' ')
							{
								op1 = pop(pointer);
							}
							break;
						}
						result = stoi(op1) / stoi(op2);
						Push(pointer, char(result));
					}
					if (ch == '^')
					{
						for (int i = 0; i < exp.length(); i++)
						{
							while (Top(pointer) != ' ')
							{
								op1 = pop(pointer);
							}
							break;
						}
						for (int i = 0; i < exp.length(); i++)
						{
							while (Top(pointer) != ' ')
							{
								op1 = pop(pointer);
							}
							break;
						}
						result = stoi(op1) ^ stoi(op2);
						Push(pointer, char(result));
					}*/

				}





			}
		}
		/*	int index = 0;
			while (str[index] != '#') {
				if (isdigit(str[index])) {
					Push(pointer,str[index] - '0');
				}
				else {
					int x = pop(pointer);
					int y = pop(pointer);
					int result = operation(x, y, str[index]);
					Push(pointer,result);
				}
				index++;

				*/
				//}
		//This is the function that calculates the result of postfix expression.
			/*void convert_to_postfix(struct stack* pointer,string exp)
			{
				string expression;
				cout << "Enter an infix opression";
				cin >> expression;
				Push(pointer, 'N');
				string ns;
				char ch;
				for (int i = 0; i < expression.length(); i++)

				{ch = exp[i];
				   if ((ch >= 65 && ch <= 90) || (ch >= 98 && ch <= 122) || (ch >= 48 && ch <= 57))
					{if (ns.length() == 0)
						{ns[0] = ch;
						 ns.length()++;
				   }
						else { ns[ns.length()-1] = ch; }
					}
					if (ch == '(')
					{
						Push(pointer, ch);
					}
					if (prec(ch) == 3)
					{Push(pointer, ch);}
					if (prec(ch) == 2 && (Top(pointer) == '(' || Top(pointer) == '^'))
					{
						ns[ns.length()-1]=Top(pointer);
						pop(pointer);
					}
					if (prec(ch) == 2 && !(Top(pointer) == '(' || Top(pointer) == '^')) {ns[(++ns.length())- 1] = ch; }
					if (prec(ch) == 1)
					{
						if (IsEmpty(pointer))
						{
							pointer->stack[pointer->top];
						}
						else
						{
							ns[ns.length() - 1] = ch;
						}
					}

					if (ch == ')')
					{
						while (pointer->stack[pointer->top] != '(')
						{
							ns[ns.length() - 1] = Top(pointer);
							pop(pointer);
						}
						if (pointer->stack[pointer->top] == '(')
						{
							pop(pointer);
						}
					}





					//Function to return precedence of operators
						for (int i = 0; i < l; i++)
						{

							// WRITE CODE TO CHECK IF THE SCANNED CHARACTER IS
							// AN OPERAND, ADD IT TO OUTPUT NEW STRING.
							// if(. . . . .

							// If the scanned character is an
							// ‘(‘, push it to the stack.
				else if (s[i] == '(')

				st.push('(');

				// If the scanned character is an ‘)’,
				// pop and to output string from the stack
				// until an ‘(‘ is encountered.
				else if (s[i] == ')')
				{
				//WRITE CODE TO POP AND TO OUTPUT STRING FROM THE STACK
			 // UNTIL AN ‘(‘ IS ENCOUNTERED.

				}

				//If an operator is scanned
				else {
				while (st.top() != 'N' && prec(s[i]) <=
					prec(st.top()))
				{
					char c = st.top();
					st.pop();
					ns += c;
				}
				st.push(s[i]);
				}

						}

						// Pop all the remaining elements from the stack
						while (st.top() != 'N')
						{
							// WRITE CODE TO STORE TOP ELEMENT IN A VARIABLE, POP IT AND THEN STORE IT IN NEW STRING
						}

						cout << ns << endl;

					}

				}

			}
			int prec(char c)
			{
				if (c == '^')
					return 3;
				else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
			}
		}*/
		//cout<< Top(pointer);
		 //}
	}
    };
	int main()
	{
		stack* p = new stack();
		Implement* I = new Implement();
		string expression;
		cin >> expression;
		//I->infixToPostfix(p,expression);*/
		//I->BalanceBrackets(p, expression);
		I->calculatePostfix(p, expression);
		/*I->Push(p,'p');
		cout << I->Top(p);
		I->Push(p, 'a');
		cout << I->Top(p); I->Push(p, 'k');
		cout << I->Top(p); I->Push(p, 'i');
		cout << I->Top(p); I->Push(p, 's');
		cout << I->Top(p); I->Push(p, 't'); 
		cout << I->Top(p); I->Push(p, 'a');	cout << I->Top(p);
		 I->Push(p, 'n');
		cout << I->Top(p);
		cout << I->IsEmpty(p);
		cout << I->IsFull(p);
		//I->Push(p, 5);
		//I->Push(p, 8);
		//I->Push(p, 10);
		I->pop(p);
		cout << I->Top(p);*/
	}
