import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class DemoDecoratorPattern extends JPanel {
    Component t;

    public DemoDecoratorPattern() {
        t = new Text("Hello World", 60, 80);
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        int fontSize = 10;
        g.setFont(new Font("TimesRoman", Font.PLAIN, fontSize));

        // Build the decorator chain
        // Border: dashed black 100x100 at (30,30)
        // Frame: thick red 110x110 at (25,25) with thickness 10
        // Glass: translucent overlay 110x110 at (25,25)
        t = new ColouredGlassDecorator(
                new ColouredFrameDecorator(
                        new BorderDecorator(t, 30, 30, 100, 100),
                        25, 25, 110, 110, 10),
                25, 25, 110, 110);

        // Draw the final composed component
        t.draw(g);
    }

    public static void main(String[] args) {
        DemoDecoratorPattern panel = new DemoDecoratorPattern();
        JFrame frame = new JFrame("Learning Decorator Pattern");
        frame.getContentPane().add(panel);
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
