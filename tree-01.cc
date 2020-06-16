#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct BitNode {
  struct BitNode *lchild, *rchild;
  char data;
}BitNode, *BitTree;

void CreateBitTree(BitTree &T) {
  char ch;
  cin >> ch;
  if (ch == '#') {
    T = nullptr;
  } else {
    T = new BitNode;
    T->data = ch;
    CreateBitTree(T->lchild);
    CreateBitTree(T->rchild);
  }
}

void PreOrderTraverse(BitTree T) {
  if (!T) {
    return;
  }
  cout << T->data;
  PreOrderTraverse(T->lchild);
  PreOrderTraverse(T->rchild);

}

void InOrderTraverse(BitTree T) {
  if (!T) {
    return;
  }
  PreOrderTraverse(T->lchild);
  cout << T->data;
  PreOrderTraverse(T->rchild);
}

void PostOrderTraverse(BitTree T) {
  if (!T) {
    return;
  }
  PostOrderTraverse(T->rchild);
  PostOrderTraverse(T->lchild);
  cout << T->data;
}


// input ABDH#K###E##CFI###G#J##

int main() {
  BitTree T;
  CreateBitTree(T);
  cout << endl;
  PreOrderTraverse(T);
  cout << endl;
  InOrderTraverse(T);
  cout << endl;
  PostOrderTraverse(T);
  return 0;
}
