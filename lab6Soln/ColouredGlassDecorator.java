import java.awt.AlphaComposite;
import java.awt.Color;
import java.awt.Composite;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class ColouredGlassDecorator extends Decorator {
    public ColouredGlassDecorator(Component t, int x, int y, int width, int height){
        this.cmp = t;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    @Override
    public void draw(Graphics g){
        super.draw(g);
        Graphics2D g2d = (Graphics2D) g;
        Color oldColor = g2d.getColor();
        Composite oldComposite = g2d.getComposite();
        try {
            g2d.setColor(new Color(0, 255, 0));            // green “glass”
            g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.10f)); // 10% opacity
            g2d.fillRect(x, y, width, height);
        } finally {
            g2d.setColor(oldColor);
            g2d.setComposite(oldComposite);
        }
    }
}
