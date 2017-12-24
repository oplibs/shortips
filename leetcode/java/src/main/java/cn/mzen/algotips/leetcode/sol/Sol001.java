package cn.mzen.algotips.leetcode.sol;

import cn.mzen.algotips.base.*;

import org.apache.logging.log4j.Logger;
import org.apache.logging.log4j.LogManager;


// import java.io.StringReader;
// import java.util.ArrayList;
// import java.util.HashMap;
import java.util.HashMap;
import java.util.List;

/**
 * Created by itrek on 12/20/16.
 */
public class Sol001 extends Solution{
    private static Logger logger = LogManager.getLogger(Sol001.class.getName());
    private static String TAG = "Sol 001";

    public Sol001(){
        super();
    }

    public void run(String args){
        super.run(args);
    }

    public void processCase(String data) {
        String[] params = data.split(":");

        Integer target = Integer.parseInt(params[0]);
        List list = FileLoader.getIntegerArray(params[1]);

        //this.execute(list, target);
    }

    private int[] execute(int[] nums, int target){
        int[] result = new int[2];
        HashMap<Integer, Integer> dataset = new HashMap<Integer, Integer>();
        for(Integer nc=0;nc<nums.length;nc++){
            Integer newkey = target-nums[nc];
            if(dataset.containsKey(newkey)){
                result[1]=nc;
                result[0]=dataset.get(newkey);
                return result;
            }
            dataset.put(nums[nc],nc);
        }
        return result;
    }
}
