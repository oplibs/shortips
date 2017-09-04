package cn.mzen.algotips.leetcode;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.lang.reflect.*;
/**
 * Created by itrek on 11/18/16.
 */
public class LeetCode{
    private static Logger logger = LogManager.getLogger(LeetCode.class.getName());
    public LeetCode(){

    }

    public void callAlgorithm(String[] args) throws ClassNotFoundException, InvocationTargetException, IllegalAccessException {
        String[] params = args[0].split(":");
        String algoindex = params[0];
        String classname = "cn.mzen.algotips.leetcode.sol.Sol"+algoindex;
        Class algoClass = Class.forName(classname);

        Object algoObject = null;
        try {
            algoObject = algoClass.newInstance();
        } catch (InstantiationException e) {
            e.printStackTrace();
            return;
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return;
        }

        try {
            Class[] argsClass = new Class[1];
            argsClass[0] = String.class;
            Method runMethod = algoClass.getDeclaredMethod("run", argsClass);
            runMethod.setAccessible(true);
            runMethod.invoke(algoObject, params[1]);
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
            logger.error("Class init failed!");
            return;
        }
    }
}
