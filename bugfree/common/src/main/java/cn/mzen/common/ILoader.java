package cn.mzen.common;

import cn.mzen.common.ListNode;
import cn.mzen.common.TreeNode;

import java.io.IOException;

public interface ILoader {
    boolean hasNext() throws IOException;
    String next();
    DataType getResType();
    DataType getCaseType();
    boolean parseHeader(String val);
    boolean parseBoolean(String val);
    ListNode parseListNode(String val);
    TreeNode parseTreeNode(String val);
    // <T> parseData(String val);
}
