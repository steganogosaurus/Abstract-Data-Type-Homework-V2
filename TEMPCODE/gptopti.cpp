#include <iostream>
struct Node {
    char value;
    struct Node* Next;
};

typedef struct Node* Stack;

bool IsEmpty(Stack S);
bool IsMatch(char open, char close);
char Top(Stack S);
void Push(char symbol, Stack S);
void Pop(Stack S);
Stack CreateStack();

int main() {
    char parenthesis;
    Stack openBracket = CreateStack();
    Stack closeBracket = CreateStack();
    std::cout << "Input: ";
    while (std::cin >> parenthesis && parenthesis != '.') {
        if (parenthesis == '{' || parenthesis == '[' || parenthesis == '(' || parenthesis == '<') {
            Push(parenthesis, openBracket);
        } else {
            Push(parenthesis, closeBracket);
        }
    }
    while (!IsEmpty(openBracket) && !IsEmpty(closeBracket)) {
        char open = Top(openBracket);
        char close = Top(closeBracket);
        if (IsMatch(open, close)) {
            Pop(openBracket);
            Pop(closeBracket);
        } else {
            std::cout << "Expected " << close << " ";
            Pop(closeBracket);
        }
    }
    if (IsEmpty(openBracket) && IsEmpty(closeBracket)) {
        std::cout << "Complete!";
    }
    return 0;
}

bool IsMatch(char open, char close) {
    switch (open) {
        case '{': return close == '}';
        case '(': return close == ')';
        case '[': return close == ']';
        case '<': return close == '>';
        default: return false;
    }
}

bool IsEmpty(Stack S) {
    return S->Next == NULL;
}

char Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->Next->value;
    } else {
        std::cout << "Stack Empty!";
        return '\0'; // Return a default value in case of an error
    }
}

void Push(char symbol, Stack S) {
    Stack TmpCell;
    TmpCell = new struct Node;
    if (TmpCell == NULL) {
        std::cout << "Out of space!!";
    } else {
        TmpCell->value = symbol;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

void Pop(Stack S) {
    if (IsEmpty(S)) {
        std::cout << "Empty Stack!";
    } else {
        Stack FirstCell = S->Next;
        S->Next = S->Next->Next;
        delete FirstCell;
    }
}

Stack CreateStack() {
    Stack S = new struct Node;
    S->Next = NULL;
    if (S == NULL) {
        std::cout << "Out of Space!";
    }
    return S;
}

