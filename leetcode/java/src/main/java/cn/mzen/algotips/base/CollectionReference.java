package cn.mzen.algotips.base;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

/**
 * Created by itrek on 29/08/2017.
 */
public class CollectionReference {
    private static Logger logger = LogManager.getLogger(CollectionReference.class.getName());

    public CollectionReference(){
        this.refList();
        return;
    }

    private void refList(){
        // List 可以类型混用
        /*
Collection
├List
│├LinkedList
│├ArrayList
│└Vector
│　└Stack
└Set
Map
├Hashtable
├HashMap
└WeakHashMap
*/
        List list = new ArrayList();
        list.add(1);
        list.add('2');
        list.add("speedup");
        logger.info(list);

        // Vector 可以类型混用
        Vector<Integer> vec = new Vector<Integer>();
        vec.add(1);
        vec.add('1');
    }

    private void refListMT(){

    }

    private void refSet(){

    }
}
