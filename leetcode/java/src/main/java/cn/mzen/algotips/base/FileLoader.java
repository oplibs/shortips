package cn.mzen.algotips.base;

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

    public boolean loadFile(String filename){
        try {
            this.fr = new FileReader(filename);
            this.br=new BufferedReader(this.fr);
            // System.out.println("Case file load successfully!");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public String loadCase(){
        String line=null;
        try {
            line=this.br.readLine();
            if(line!=null && line.length()>0){
                return line;
            }else {
                return null;
            }
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
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
}
