import java.awt.Graphics;

public class helloWorld extends java.applet.Applet{
    public void init(){
        resize(100,100);
    }
    public void paint(Graphics g){
        g.drawString("Hello World", 5,20);
    }
}