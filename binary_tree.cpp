/*
 *  ┌─────────────────────────────────────────────────────────────┐
 *  │┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐│
 *  ││Esc│!1 │@2 │#3 │$4 │%5 │^6 │&7 │*8 │(9 │)0 │_- │+= │|\ │`~ ││
 *  │├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤│
 *  ││ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{[ │}] │ BS  ││
 *  │├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤│
 *  ││ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  ││
 *  │├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤│
 *  ││ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│Shift │Fn ││
 *  │└─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘│
 *  │      │Fn │ Alt │         Space         │ Alt │Win│   HHKB   │
 *  │      └───┴─────┴───────────────────────┴─────┴───┘          │
 *  └─────────────────────────────────────────────────────────────┘
 * 
 * @Author      : shunshun 786174502@qq.com
 * @Date        : 2023-01-30 23:08:10
 * @LastEditors : shunshun 786174502@qq.com
 * @LastEditTime: 2023-01-31 00:00:50
 * @FilePath    : /Downloads/cartoon_algorithm/binary_tree.cpp
 * 
 * @Description : 实现二叉树的先序、中序、后序遍历
 * 
 * If you have any problem, please contact:
 *     QQ    : 786174502
 *     WeChat: 19121765520
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#include <iostream>
#include <vector>
#include <string>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value, TreeNode* leftPtr, TreeNode* rightPtr)
        : val(value), left(leftPtr), right(rightPtr) {}
};


class BinaryTree
{
public:
    BinaryTree()
    {
        _root = nullptr;
    }

    ~BinaryTree()
    {
        destroy(_root);
        _root = nullptr;
    }

    /**
     * @description: 从先序序列中构造二叉树
     */
    void build_tree(const std::vector<std::string>& arr)
    {
        int left = 0;
        _root = buildTree(arr, left);
    }

    /**
     * @description: 先序遍历
     */
    void pre_traverse()
    {
        preTraverse(_root);
    }

    /**
     * @description: 中序遍历
     */
    void in_traverse()
    {
        inTraverse(_root);
    }

    /**
     * @description: 后序遍历
     */
    void post_traverse()
    {
        postTraverse(_root);
    }


private:
    TreeNode* _root;    // 根节点

    TreeNode* buildTree(const std::vector<std::string>& arr, int& left)
    {
        if (left >= arr.size() || arr[left] == "null")
        {
            left++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(std::stoi(arr[left]), nullptr, nullptr);    // 构建根节点
        left++;
        node->left = buildTree(arr, left);    // 构建左子树
        node->right = buildTree(arr, left);    // 构建右子树
        return node;
    }

    void preTraverse(TreeNode* root)
    {
        if (root == nullptr)
            return;
        std::cout << root->val << " ";
        preTraverse(root->left);
        preTraverse(root->right);
    }

    void inTraverse(TreeNode* root)
    {
        if (root == nullptr)
            return;
        inTraverse(root->left);
        std::cout << root->val << " ";
        inTraverse(root->right);
    }

    void postTraverse(TreeNode* root)
    {
        if (root == nullptr)
            return;
        postTraverse(root->left);
        postTraverse(root->right);
        std::cout << root->val << " ";
    }

    void destroy(TreeNode* root)
    {
        if (root == nullptr)
            return;
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
};

int main()
{
    std::vector<std::string> arr = {"3", "2", "9", "null", "null", "10", "null", "null", "8", "null", "4"};
    BinaryTree tree;
    tree.build_tree(arr);

    tree.pre_traverse();
    std::cout << "\n";
    tree.in_traverse();
    std::cout << "\n";
    tree.post_traverse();
    std::cout << "\n";

    return 0;
}