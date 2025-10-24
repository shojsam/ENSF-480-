import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class ColouredFrameDecorator extends Decorator {
	int thickness;
	
	public ColouredFrameDecorator(Component t, int x, int y, int width, int height, int thickness) {
		this.cmp = t;
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		this.thickness = thickness;
	}
	
	public void draw(Graphics g) {
		super.draw(g);
		Graphics2D g2d = (Graphics2D) g;
		g2d.setStroke(new BasicStroke(thickness));
		g2d.setColor(Color.red);
		g2d.drawRect(x, y, width, height);
	}
}
