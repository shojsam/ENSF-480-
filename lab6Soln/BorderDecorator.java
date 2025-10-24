import java.awt.BasicStroke;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class BorderDecorator extends Decorator {
	public BorderDecorator(Component t, int x, int y, int width, int height) {
		this.cmp = t;
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}
	@Override
	public void draw(Graphics g) {
		super.draw(g);
		Graphics2D g2d = (Graphics2D) g;
		float[] dashPattern = {10, 10};
		BasicStroke dashedStroke = new BasicStroke(3, BasicStroke.CAP_BUTT,
				BasicStroke.JOIN_BEVEL,0, dashPattern,0 );
		g2d.setStroke(dashedStroke);
		g2d.drawRect(x, y, width, height);
	}
}
