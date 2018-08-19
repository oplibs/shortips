package cn.mzen.deepj.basic;

public class ClassInstance {
    static class A {
        private Integer number;
        public void setNumber(Integer value){
            number=value;
        }
    }

    static public void RunEqual(){
        A a=new A();
        A b=new A();
        A ashadow = a;
        a.setNumber(1);
        b.setNumber(1);
        System.out.println("a.equals(a):"+a.equals(a));
        System.out.println("a.equals(ashadow):"+a.equals(ashadow));
        System.out.println("a==ashadow:"+(a==ashadow));
        System.out.println("a.equals(b):"+a.equals(b));
        System.out.println("a.hashcCode():"+a.hashCode());
        System.out.println("ashadow.hashcCode():"+ashadow.hashCode());
        System.out.println("b.hashcCode():"+b.hashCode());


        Integer anum=123;
        Integer bnum=123;
        Integer abig=12312;
        Integer bbig=12312;
        System.out.println("123.equals(another 123):"+anum.equals(bnum));
        System.out.println("12312.equals(another 12312):"+abig.equals(bbig));
        System.out.println("123.hashCode():"+anum.hashCode());
        System.out.println("another 123.hashCode():"+bnum.hashCode());
        System.out.println("12312.hashCode():"+abig.hashCode());
        System.out.println("another 12312.hashCode():"+bbig.hashCode());
    }
}
