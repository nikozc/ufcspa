public class ClasseD {
    private int attr1;
    private int attr2;
    private int attr3;
    private int attr4;
    private int attr5;

    public ClasseD ( ){
        this.attr1 = 0;
        this.attr2 = 0;
        this.attr3 = 0;
        this.attr4 = 0;
        this.attr5 = 0;
    }
    public ClasseD ( int attr1 ){
        this.attr1 = attr1;
        this.attr2 = 1;
        this.attr3 = 1;
        this.attr4 = 1;
        this.attr5 = 1;
    }
    public ClasseD (  int attr1, int attr2 ){
        this.attr1 = attr1;
        this.attr2 = attr2;
        this.attr3 = 2;
        this.attr4 = 2;
        this.attr5 = 2;
    }

    public void imprimir(){
        System.out.println("attr1:"+this.attr1);
        System.out.println("attr2:"+this.attr2);
        System.out.println("attr3:"+this.attr3);
        System.out.println("attr4:"+this.attr4);
        System.out.println("attr5:"+this.attr5);
    }
    public int getAttr1() {
        return this.attr1;
    }
    public int getAttr2() {
        return this.attr2;
    }
    public int getAttr3() {
        return this.attr3;
    }
    public int getAttr4() {
        return this.attr4;
    }
    public int getAttr5() {
        return this.attr5;
    }

    public void setAttr1( int attr ) {
        this.attr1 = attr;
    }
    public void setAttr2( int attr ) {
        this.attr2 = attr;
    }
    public void setAttr3( int attr ) {
        this.attr3 = attr;
    }
    public void setAttr4( int attr ) {
        this.attr4 = attr;
    }
    public void setAttr5( int attr ) {
        this.attr5 = attr;
    }
}
