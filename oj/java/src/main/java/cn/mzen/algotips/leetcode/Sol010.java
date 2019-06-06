package cn.mzen.algotips.leetcode;

import cn.mzen.algotips.Main;
import cn.mzen.algotips.leetcode.base.FileLoader;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class Sol010 {
    private static Logger logger = LogManager.getLogger(Sol010.class.getName());

    public static void main(String[] args) {
        System.out.println("I am here!");
        System.out.println(args[0]);
        FileLoader loader = new FileLoader();
        loader.loadFile(args[0]);
        //System.out.println(args[1]);
    }
}
