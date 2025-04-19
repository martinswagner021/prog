import javax.swing.JFrame;
import javax.swing.ImageIcon;

public class Frame extends JFrame{
    public Frame(){
        this.setSize(640,480);
        this.setTitle("My program");
        
        ImageIcon img = new ImageIcon("program-image.png");
        this.setIconImage(img.getImage());
        
        this.setVisible(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}