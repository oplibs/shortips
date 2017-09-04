package cn.mzen.algotips;

import cn.mzen.algotips.leetcode.LeetCode;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.lang.reflect.InvocationTargetException;

/**
 * Created by itrek on 11/18/16.
 */
public class Main {
    private static Logger logger = LogManager.getLogger(Main.class.getName());

    public static void main(String[] args) {
        LeetCode leetCode = new LeetCode();
        try {
            leetCode.callAlgorithm(args);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            // System.out.println("Could not find the class");
            logger.error("Could not find the class");
        } catch (InvocationTargetException e) {
            e.printStackTrace();
            logger.error("Could not call the function");
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            logger.error("Could not access the object");
        }
    }
}
