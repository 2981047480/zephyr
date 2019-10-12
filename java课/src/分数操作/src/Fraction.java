public class Fraction {
    public int numerator;  //分子
    public int denominator=1;  //分母

    public void show() {
        //先对分子和分母进行约分
        reduction();
        //根据分母是否为1，决定显示方法
        if(denominator==1)
            System.out.println(numerator);
        else
            System.out.println(numerator+"/"+denominator);
    }

    private void reduction() {
        //先求分子和分母的最大公约数
        int gcd=getGCD(numerator,denominator);
        //分子和分母分别除以最大公约数
        numerator/=gcd;
        denominator/=gcd;
    }

    //求两个数的最大公约数
    private int getGCD(int m, int n) {
        //从m/n遍历到1，找到第一个能同时把m/n整除的数
        for(int x=m;x>=1;x--) {
            if(m%x==0&&n%x==0)
                return x;
        }
        return 1;
    }
}
