public classe Point{
    private int posx,posy;
    public Point(int abs,int ord){
        posx=abs;
        posy=ord;
    }
    public Point(){
        this(1,1);
    }
    public setPosx(int a){
        posx=a;
    }
    public setPosy(int a){
        posy=a;
    }
    public getPosx(){
        return posx;
    }
    public getPosy(){
        return posy;
    }
}
