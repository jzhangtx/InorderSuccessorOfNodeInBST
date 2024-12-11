// SuccessorOfNodeInBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

Node* LeftMost(Node* pNode)
{
    if (pNode == nullptr)
        return nullptr;

    while (pNode->left != nullptr)
        pNode = pNode->left;

    return pNode;
}

Node* Successor(Node* pNode, Node* pParent, Node* p)
{
    if (pNode == nullptr)
        return nullptr;

    if (pNode == p || pNode->right == p)
    {
        return pParent;
    }

    Node* pSuccessor = Successor(pNode->left, pNode, p);
    if (pSuccessor != nullptr)
        return pSuccessor;
    return Successor(pNode->right, pNode, p);
}

Node* FindSuccessor(Node* root, Node* p)
{
    if (p->right != nullptr)
        return LeftMost(p->right);

    Node* pParent = nullptr;
    return Successor(root, pParent, p);
}

Node* FindNode(Node* pNode, int k)
{
    if (pNode == nullptr)
        return nullptr;

    if (pNode->data == k)
        return pNode;

    Node* pFound = FindNode(pNode->left, k);
    if (pFound != nullptr)
        return pFound;

    return FindNode(pNode->right, k);
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in BST: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "The nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
        {
            std::cin >> v[i];
        }

        Node* pRoot = ArrayToTree(v);

        std::cout << "The node to find successor for: ";
        int k = 0;
        std::cin >> k;
        Node* p = FindNode(pRoot, k);

        Node* pSuccessor = FindSuccessor(pRoot, p);
        std::cout << "The successor of " << p->data << " is " << (pSuccessor ? pSuccessor->data : -1) << std::endl;

        FreeTree(pRoot);
    }
}
