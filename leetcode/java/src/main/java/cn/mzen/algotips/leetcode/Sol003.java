package cn.mzen.algotips.leetcode;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.HashSet;

/**
 * Created by itrek on 12/20/16.
 */
public class Sol003 extends Solution{
    private static Logger logger = LogManager.getLogger(Sol003.class.getName());
    private static String TAG = "Sol 001";

    public Sol003(){
        super();
    }

    public void run(String args){
        super.run(args);
    }

    public void processCase(String data) {
        this.execute(data);
    }

    private Integer execute(String s){
        if(s.length()<2){
            return s.length();
        }
        // 初始化状态的设计尽量考虑统一设计，不要自己设计多种初始化状态，
        // 比如curlen不能直接为1, start=0, cur=1。
        Integer start=0;
        Integer cur=0;
        Integer curlen=0;
        HashSet<Character> set = new HashSet<Character>();
        while(cur<s.length()){
            if(set.contains(s.charAt(cur))){
                curlen=Math.max(curlen, cur-start);
                while(start<=cur){
                    if(s.charAt(start)==s.charAt(cur)){
                        start++;
                        break;
                    }else{
                        set.remove(s.charAt(start++));
                    }
                }
                cur++;
            }else{
                set.add(s.charAt(cur++));
            }
        }
        curlen=Math.max(curlen, cur-start);
        return curlen;
    }
}
