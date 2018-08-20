package cn.mzen.common;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.LinkOption;
import java.nio.file.Path;
import java.nio.file.Paths;

public class CaseLoader implements ILoader{
    private String filePath;
    private String caseNum;
    private DataType caseType;
    private DataType resType;

    private boolean bIsFileReady;
    private BufferedReader fileReader;

    public CaseLoader(String path, String casenum) throws IOException {
        this.filePath=path;
        this.caseNum=casenum;
        this.bIsFileReady = false;
        this.fileReader = null;

        Path filePath = Paths.get(path+"\\leetcases\\"+casenum);
        this.bIsFileReady = Files.exists(filePath, new LinkOption[]{ LinkOption.NOFOLLOW_LINKS});
        if(this.bIsFileReady){
            try{
                this.fileReader = Files.newBufferedReader(filePath, Charset.forName("UTF-8"));
                String currentLine = null;
                if((currentLine = this.fileReader.readLine()) != null){
                    this.parseHeader(currentLine);
                }
            }catch(IOException ex){
                this.fileReader.close();
                this.fileReader=null;
                ex.printStackTrace(); //handle an exception here
            }
        }
    }

    protected boolean reset(){
        try {
            this.fileReader.close();
            this.fileReader=null;
            this.bIsFileReady=false;
        }
        catch (IOException ex){
        }
    }

    protected DataType checkDataType(String val) {
        if("string".equals(val)){
            return DataType.STRING;
        }else if("listnode".equals(val)){
            return DataType.LISTNODE;
        }else if("treenode".equals(val)){
            return DataType.TREENODE;
        }else {
            return DataType.NONE;
        }
    }

    @Override
    public boolean hasNext() throws IOException {
        String currentLine = this.fileReader.readLine();
        return false;
    }

    @Override
    public String next() {
        return null;
    }

    @Override
    public DataType getResType() {
        return this.resType;
    }

    @Override
    public DataType getCaseType() {
        return this.caseType;
    }

    @Override
    public boolean parseBoolean(String val) {
        return false;
    }

    @Override
    public ListNode parseListNode(String val) {
        ListNode node = new ListNode(0);
        return null;
    }

    @Override
    public TreeNode parseTreeNode(String val) {
        TreeNode node = new TreeNode(0);
        return null;
    }

    @Override
    public boolean parseHeader(String val) {
        String[] types = val.split(">");
        if(types.length!=2){
            this.reset();
            return false;
        }
        this.caseType=this.checkDataType(types[0]);
        this.resType=this.checkDataType(types[1]);
        return true;
    }
}
