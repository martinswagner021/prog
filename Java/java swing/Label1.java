import javax.swing.JLabel;
import java.awt.Color;
import java.awt.Font;

import javax.swing.ImageIcon;

public class Label1 extends JLabel{
    public Label1(){
        ImageIcon saturn = new ImageIcon("saturn.jpeg");
        this.setText("Hello, mom!");
        this.setIcon(saturn);
        this.setHorizontalAlignment(CENTER);
        this.setVerticalAlignment(CENTER);
        this.setHorizontalTextPosition(CENTER);
        this.setVerticalTextPosition(BOTTOM);
        this.setFont(new Font("Cascadia Code", Font.PLAIN, 28));

        this.setForeground(new Color(200,0,200));
    }
}