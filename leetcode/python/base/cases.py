#!/usr/bin/env python
# -*- coding: utf-8 -*-

class ListNode(object):
    __slots__ = ['val', 'next']
    def __init__(self,val):
        self.val = val
        self.next = None

    def __repr__(self):
        result = "{0}".format(self.val)
        tmp = self.next
        while tmp!=None:
            result+=("->{0}".format(tmp.val))
            tmp = tmp.next
        return result

class TreeNode(object):
    __slots__ = ['val', 'left', 'right']
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class TrieTree(object):
    __slots__ = ['val', 'children']
    def __init__(self,val):
        self.val = val
        self.children = None

class CaseLoader(object):
    __slots__=['handle']

    def __init__(self, filename):
        self.handle = open(filename)             # 返回一个文件对象

    def __del__(self):
        self.handle.close()

    def loadCase(self):
        line = self.handle.readline()             # 调用文件的 readline()方法
        # line.rstrip('\n');
        return line.strip()

    def getHandle(self):
        return self.handle

def strToIntArray(casedata):
    if casedata=="none":
        return None
    items = casedata.split(',');
    res = []
    for item in items:
        res.append(int(item))
    return res

#  if __name__!="main":
    #  node = ListNode(0);
    #  node2 = ListNode(1);
    #  node.next = node2
    #  print node
