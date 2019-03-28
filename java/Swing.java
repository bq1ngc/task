import javax.swing.*;
import java.awt.*;

class Swing {

    public static void main(String[] args) {
        JFrame jf = new JFrame("登录界面");
        jf.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        JPanel panel01 = new JPanel();
        panel01.add(new JLabel("账号"));
        panel01.add(new JTextField(10));

        JPanel panel02 = new JPanel();
        panel02.add(new JLabel("密码"));
        panel02.add(new JPasswordField(10));

        JPanel panel03 = new JPanel(new FlowLayout(FlowLayout.CENTER));
        panel03.add(new JButton("登录"));
        panel03.add(new JButton("取消"));

        Component vGlue = Box.createVerticalGlue();
        Component hGlue = Box.createHorizontalGlue();

        Box vBox = Box.createVerticalBox();
        vBox.add(vGlue);
        vBox.add(panel01);
        vBox.add(panel02);
        vBox.add(panel03);
        vBox.add(hGlue);

        jf.setContentPane(vBox);

        jf.pack();
        jf.setLocationRelativeTo(null);
        jf.setVisible(true);
        jf.setSize(250, 200);
        jf.setResizable(false);
    }

}