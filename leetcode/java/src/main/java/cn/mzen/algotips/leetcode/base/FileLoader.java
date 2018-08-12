package cn.mzen.algotips.leetcode.base;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FileLoader{

    private FileReader fr=null;
    private BufferedReader br=null;

    public FileLoader(){
    }

    @Override
    protected void finalize( )
    {
        if(this.br!=null){
            try {
                this.br.close();
            } catch (IOException e) {
                e.printStackTrace();
                return;
            }
        }
        if(this.fr!=null){
            try {
                this.fr.close();
            } catch (IOException e) {
                e.printStackTrace();
                return;
            }
        }
    }

    private String readLine(){
        String readdata;
        try {
            readdata=this.br.readLine();
            if(!(readdata!=null && readdata.length()>0)){
                return null;
            }
            return readdata;
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    public boolean loadFile(String filename){
        try {
            this.fr = new FileReader(filename);
            this.br=new BufferedReader(this.fr);
            // System.out.println("Case file load successfully!");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return false;
        }
        this.data = this.readLine();
        return true;
    }

    public static List getIntegerArray(String str){
        ArrayList<Integer> intarray = new ArrayList<Integer>();
        String[] valarray = str.split(",");

        for(Integer idx=0;idx<valarray.length;idx++){
           String item = valarray[idx];
           intarray.add(Integer.parseInt(item));
        }
        return intarray;

    }

    private String data=null;

    public boolean loadData() {
        this.data=null;
        return true;
    }
    public boolean hasNext() {
       return this.data!=null;
    }
    public ListNode next(){
        this.data=readLine();
        return null;
    }
}
