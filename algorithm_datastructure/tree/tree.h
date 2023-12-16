#ifndef AUCOMPUTERSCIENCETEST_TREE_H
#define AUCOMPUTERSCIENCETEST_TREE_H

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结点
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建新结点
struct TreeNode* createNode(int data);

// 插入结点
struct TreeNode* insert(struct TreeNode* root, int data);

// 查找结点
struct TreeNode* search(struct TreeNode* root, int data);

// 中序遍历二叉树
void inorderTraversal(struct TreeNode* root);

#endif