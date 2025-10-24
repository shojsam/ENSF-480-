import java.awt.Graphics;

public abstract class Decorator implements Component {
	Component cmp;
	int x;
	int y;
	int width;
	public int height;
	@Override
	public void draw(Graphics g) {
		cmp.draw(g);

	}

}
