package cn.mzen.algotips.tips;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Vector;

/**
 * Created by itrek on 12/15/16.
 */
public class WordTips {
    public WordTips(){
        System.out.println("Init the WordTips");
    }

    public void TraverseIterator() {
        ArrayList<Integer> intarray = new ArrayList<Integer>();
        Iterator<Integer> itrInit = intarray.iterator();
        intarray.add(1);
        intarray.add(2);
        intarray.add(3);
        intarray.add(4);
        Iterator<Integer> itr = intarray.iterator();
        // System.out.println(itrInit);
        while(itr.hasNext()){
            System.out.println("iterator:");
            Integer val = itr.next();
            itr.remove();
            System.out.println(val);
        }
    }
    public void TraverseBasic(){
        ArrayList<Integer> intarray = new ArrayList<Integer>();
        Vector<Integer> intvec = new Vector<Integer>();

        intarray.add(1);
        intarray.add(2);
        intarray.add(3);
        intarray.add(4);

        intvec.add(1);
        intvec.add(2);
        intvec.add(3);
        intvec.add(4);

        System.out.println("Traverse Arrary >>>>>>>>>>>>>>>>");
        for(Integer item:intarray){
            item = 2;
            //  System.out.println(item);
        }
        for(Integer item:intarray){
            System.out.println(item);
        }
        System.out.println("<<<<<<<<<<<<<<<<<Traverse Arrary");

        System.out.println("Traverse Vector >>>>>>>>>>>>>>>>");
        for(Integer item:intvec){
            System.out.println(item);
        }
        System.out.println("<<<<<<<<<<<<<<<<<Traverse Vector");
    }
}
