import javax.swing.JLabel;
import java.awt.Color;
import java.awt.Font;
import java.net.MalformedURLException;
import java.net.URL;

import javax.swing.ImageIcon;

public class Label1 extends JLabel{
    public Label1() throws MalformedURLException{
        ImageIcon saturn = new ImageIcon(new URL("https://lh3.googleusercontent.com/u/0/drive-viewer/AFGJ81rMjfJr0QSBqkhz7YsJOVWFBZqgfGVBYTkP86yifS4Bx4MpmEP_oyfy24rOPUSJ7mwwXjMPfXrWoBiMj0YZJKISVg-4kw=w1280-h953"));
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