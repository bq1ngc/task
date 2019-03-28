import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Timer;
import java.util.TimerTask;

public class Drawing extends JFrame implements KeyListener,ActionListener{
    private static final long serialVersionUID = 1L;

    int Width = 600;                  //定义主体Size
    int Height = 600;                 //
    int rectWidth = 25;               //方格宽度
    int numW = Width-rectWidth-150;   //行长度(px)
    int numH = Height-rectWidth-20;   //
    int numI;     //行总数
    int numJ;     //列总数

    Lmasterpanel Lpanel;
    RFlowLayout Rpanel;

    private int[] nowshape;   //当前图形
    private int nowtype;      //当前图形类型
    private int[] nextshape;  //下一个图形
    private int bigrect[][];  //大数组 0-空(白) 2-固定(黑) 1-活动(蓝)
    private Shape newShape;   //形状操作类对象

    Move newMove;  //移动操作类
    int nowstate;  //0-stop 1-run 2-pause
    Timer timer;   //定时刷新

    private int score; // 分数
    JButton jButtonStart, jButtonPause,jButtonStop,jButtonRestart;  //按钮
    JTextField jTextScore;  //分数显示

    public Drawing(){
        super();
        initRectSize();  //计算行/列总数
        initData();      //初始化数据
        Lpanel = new Lmasterpanel();   //左面板 - 方块显示
        Lpanel.addKeyListener(this);
        Rpanel = new RFlowLayout();    //右面板 - 状态显示、控制
        initFrame();                   //绘制框体
    }


    /**
     * 初始化数据
     */
    private void initData() {
        nowstate=0;
        score=0;
        bigrect = new int[numI][numJ];
        timer = new Timer();
        newShape = new Shape();
        nowshape=newShape.getOne();
        nowtype=newShape.type;
        nextshape= new int[16];//newShape.getOne();
        newMove = new Move();
    }

    /**
     * 初始化界面
     */
    private void initFrame() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Tetris - xinroom.cn");
        setSize(Width, Height);
        setResizable(false);
        setLocationRelativeTo(null);

        setLayout(new BorderLayout());
        Lpanel.setPreferredSize(new Dimension(350,Height));
        add(Lpanel,BorderLayout.CENTER);
        Rpanel.setPreferredSize(new Dimension(150,Height));
        add(Rpanel,BorderLayout.EAST);

        addKeyListener(this);
        jButtonStart.addActionListener(this);
        jButtonPause.addActionListener(this);
        jButtonStop.addActionListener(this);
        jButtonRestart.addActionListener(this);
        setVisible(true);
    }



    /**
     * 右面板
     */
    public class RFlowLayout extends JPanel{
        
        private static final long serialVersionUID = 1L;
        public NextshapeP nextpanel= new NextshapeP();

        public RFlowLayout() {
            jButtonStart = new JButton("Start");
            jButtonPause = new JButton("Pause");
            jButtonStop = new JButton("Stop");
            jButtonRestart = new JButton("Restart");

            jTextScore = new JTextField(String.valueOf(score));
            jTextScore.setFont(new Font("arial", Font.BOLD, 20));
            jTextScore.setEditable(false);
            jTextScore.setHorizontalAlignment(JTextField.CENTER);

            String readmeText = "<html>  ↑	—— Revolve<br>  ↓	—— DownMove<br>  ←	—— LeftMove<br>  →	—— RightMove<br>  Spack —— Pause</html>";

            JLabel readmeLabel = new JLabel(readmeText,JLabel.CENTER);
            readmeLabel.setPreferredSize(new Dimension(150,100));
            
            nextpanel.setPreferredSize(new Dimension(125,125));
            jTextScore.setPreferredSize(new Dimension(100,30));
            jButtonStart.setPreferredSize(new Dimension(100,30));
            jButtonPause.setPreferredSize(new Dimension(100,30));
            jButtonStop.setPreferredSize(new Dimension(100,30));
            jButtonRestart.setPreferredSize(new Dimension(100,30));
            
            add(nextpanel);
            add(jTextScore);
            add(jButtonStart);
            add(jButtonPause);
            add(jButtonStop);
            add(jButtonRestart);
            add(readmeLabel);
        }

        /**
         * 画下一个图形
         */
        public class NextshapeP extends JPanel{
            private static final long serialVersionUID = 1L;
    
            @Override
            public void paintComponent(Graphics g) {
                int i=0;int j=0;
                for(int a=10; a<rectWidth*4+10; a+=rectWidth){
                    j=0;
                    for(int b=10; b<rectWidth*4+10; b+=rectWidth){
                        if(nextshape[j*4+i]==1) {
                            g.setColor(Color.BLUE);
                        }
                        if(nextshape[j*4+i]==0) {
                            g.setColor(Color.WHITE);
                        }
                        g.fill3DRect(a, b, rectWidth, rectWidth,true);
                        g.setColor(Color.gray);
                        g.drawRect(a, b, rectWidth, rectWidth);
                        j++;
                    }
                    i++;
                }
            }
        }
    }


    /**
     * 状态控制
     * @param prestate 想要的状态
     */
    public void myaction(int prestate)
    {   
        /**定时任务 */
        TimerTask timertask = new TimerTask() {
            public void run() {
                if(newMove.isDone()==1){
                    bigrect = new int[numI][numJ];
                    repaint();
                    System.out.println("Done:"+String.valueOf(score));
                    cancel();
                    return;
                }
                if(nowstate==2)return;
                if(nowstate == 1){
                    newMove.down();
                    score++;
                    jTextScore.setText(String.valueOf(score));
                }
                repaint();
            }
        };

        if(prestate==nowstate)return;

        if(nowstate==0){
            if(prestate==1){
                nextshape=newShape.getOne();
                timer = new Timer();
                timer.schedule(timertask, 500, 500);
                nowstate=1;
            }
        }else if(nowstate==1){
            if(prestate==0){
                timer.cancel();
                initData();
                repaint();
            }else if(prestate==2)nowstate=2;
        }else if(nowstate==2){
            if(prestate==0){
                timer.cancel();
                initData();
                repaint();
            }
            if(prestate==1)nowstate=1;
        }
    
    }

    /**
     * 计算行列方块个数
     */
    private void initRectSize() {

        int i=0;int j=0;
        int a,b;
        for(a=10; a<=numW; a+=rectWidth){
            j=0;
            for(b=10; b<=numH; b+=rectWidth){
                j++;
            }
            i++;
        }
        numI=j; numJ=i;
    }


    /**
     * 移动方法类
     */
    public class Move {

        int initJ = numJ/2 - 4;   //从中间开始
        int nowJ = initJ;
        int nowI = -3;       //从-3行位置开始
        int[][] prebigrect;  //形状移动后的数组

        /**
         * 新一轮的图形下降
         */
        private void init(){
            initJ = numJ/2 - 4;
            nowJ = initJ;
            nowI = -3;
            for(int i=0; i<numI; i++){ //固化为2
                for(int j=0; j<numJ; j++){
                    if(bigrect[i][j]==1) bigrect[i][j]=2;
                }
            }

            //消除判断
            int has;
            do{
                has=-1;
                int numone;
                for (int i=numI-1; i>=0; i--){
                    numone=0;
                    for (int j=0; j<numJ; j++){
                        if(bigrect[i][j]==2){
                            numone++;
                        }
                    }
                    if(numone==numJ) {
                        has=i;break;
                    }
                }
                if(has!=-1){
                    for(int i=has; i>= 1; i--){
                        for(int j=0; j<numJ; j++){
                            bigrect[i][j]=bigrect[i-1][j];
                        }
                    }
                    for(int j=0; j<numJ; j++){
                           bigrect[0][j]=0;
                    }
                }
            }while(has!=-1);
            
            nowshape=nextshape;
            nowtype=newShape.type;
            nextshape=newShape.getOne();
        }

        /**
         * 下移方法
         */
        void down(){
            if(nowstate!=1)return;
            //边缘判断
            for(int j=0; j<numJ; j++){
                if (bigrect[numI-1][j]==1) {
                    init();
                }
            }

            nowI++;
            prebigrect = new int[numI][numJ];
            for (int i=0; i<4; i++){
                for (int j=0;j<4; j++){
                    if(0 <= i+nowI && i+nowI < numI   &&   0 <= j+nowJ && j+nowJ < numJ){
                        if(nowshape[i*4+j]==1)prebigrect[i+nowI][j+nowJ]=nowshape[i*4+j]=1;
                    }
                }
            }
            CoverCheck(1);
        }

        /**
         * 左移方法
         */
        void left(){
            if(nowstate!=1)return;
            //边缘判断
            for(int i=0; i<numI; i++){
                if (bigrect[i][0]==1) {
                    return;
                }
            }
            int ok=0;
            for(int i=0; i<numI; i++){
                for(int j=0; j<numJ; j++){
                    if(bigrect[i][j]==1) ok=1;
                }
                if(ok==1)break;
            }
            if(ok==0)return;

            nowJ--;
            prebigrect = new int[numI][numJ];
            for (int i=0; i<4; i++){
                for (int j=0;j<4; j++){
                    if(0 <= i+nowI && i+nowI < numI   &&   0 <= j+nowJ && j+nowJ < numJ){
                        if(nowshape[i*4+j]==1)prebigrect[i+nowI][j+nowJ]=nowshape[i*4+j]=1;
                    }
                }
            }
            if(CoverCheck(0)==0)nowJ++; //还原
            
        }

        void right(){
            if(nowstate!=1)return;
            //边缘判断
            for(int i=0; i<numI; i++){
                if (bigrect[i][numJ-1]==1) {
                    return;
                }
            }
            int ok=0;
            for(int i=0; i<numI; i++){
                for(int j=0; j<numJ; j++){
                    if(bigrect[i][j]==1) ok=1;
                }
                if(ok==1)break;
            }
            if(ok==0)return;


            nowJ++;
            prebigrect = new int[numI][numJ];
            for (int i=0; i<4; i++){
                for (int j=0;j<4; j++){
                    if(0 <= i+nowI && i+nowI < numI   &&   0 <= j+nowJ && j+nowJ < numJ){
                        if(nowshape[i*4+j]==1)prebigrect[i+nowI][j+nowJ]=nowshape[i*4+j]=1;
                    }
                }
            }
            if(CoverCheck(0)==0)nowJ--; //还原
        }

        /**
         * 方向变换方法
         */
        private void Deform(){
            if(nowstate!=1)return;
            int[] preshape=newShape.getDeform(nowtype);
            prebigrect = new int[numI][numJ];
            for (int i=0; i<4; i++){
                for (int j=0;j<4; j++){
                    if(0 <= i+nowI && i+nowI < numI   &&   0 <= j+nowJ && j+nowJ < numJ){
                        if(preshape[i*4+j]==1)prebigrect[i+nowI][j+nowJ]=preshape[i*4+j]=1;
                    }else if(i+nowI >= numI || j+nowJ >= numJ || 0 > j+nowJ){
                        if(preshape[i*4+j]==1)return;
                    }
                }
            }
            if(CoverCheck(0)==1)nowshape=preshape;
        }

        /**
         * 判断是否覆盖（1覆盖了2的位置）
         * @param init  是否需要直接进入下一轮下降
         * @return      是否可以提交到大数组
         */
        private int CoverCheck(int init) {
            int can=1;
            for(int i=0; i<numI;i++){
                for(int j=0;j<numJ;j++){
                    if(prebigrect[i][j]==1 && bigrect[i][j]==2){
                        can=0;
                    }
                }
            }
            if(can==1){
                for(int i=0; i<numI;i++){
                    for(int j=0;j<numJ;j++){
                        if(bigrect[i][j]==1) bigrect[i][j]=0;
                        if(prebigrect[i][j]==1) bigrect[i][j]=1;
                    }
                }
            }else if(init==1){
                init();
            }else{
                return 0;
            }
            return 1;
        }

        /**
         * 到顶判断
         */
        public int isDone() {
            if(nowstate==0)return 1;
            for(int j=0; j<numJ; j++){  //第一行
                if (bigrect[0][j]==2) {
                    nowstate=0;
                    JOptionPane.showMessageDialog(null, "本次分数为："+String.valueOf(score), "游戏结束", JOptionPane.INFORMATION_MESSAGE);
                    return 1;
                }
            }
            return 0;
        }

    }
    

    /**
     *  绘制左面板
     */
    public class Lmasterpanel extends JPanel{
        private static final long serialVersionUID = 1L;

        @Override
        public void paintComponent(Graphics g) {
            this.requestFocus();

            int i=0;int j=0;
            for(int a=10; a<=numW; a+=rectWidth){
                i=0;
                for(int b=10; b<=numH; b+=rectWidth){
                    if(bigrect[i][j]==1) {
                        g.setColor(Color.BLUE);
                    }
                    if(bigrect[i][j]==0) {
                        g.setColor(Color.WHITE);
                    }
                    
                    if(bigrect[i][j]==2) {
                        g.setColor(Color.BLACK);
                    }
                    g.fill3DRect(a, b, rectWidth, rectWidth,true);
                    g.setColor(Color.gray);
                    g.drawRect(a, b, rectWidth, rectWidth);
                    i++;
                }
                j++;
            }
        }
    }


    /**
     * 键盘方法
     */
    @Override
    public void keyPressed(KeyEvent e) {
        if(newMove.isDone()==1)return;
        int key = e.getKeyCode();
        switch (key) {
            case KeyEvent.VK_DOWN:
                newMove.down();
                break;
            case KeyEvent.VK_RIGHT:
                newMove.right();
                break;
            case KeyEvent.VK_LEFT:
                newMove.left();
                break;
            case KeyEvent.VK_SPACE:
                if(nowstate==1){
                    nowstate=2;
                }else if(nowstate==2){
                    nowstate=1;
                }
                break;
            case KeyEvent.VK_UP:
                newMove.Deform();
                break;
            default:
                return;
        }
        Lpanel.repaint();
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    /**
     * 按钮方法
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        String comm = e.getActionCommand();
        System.out.println(comm);
        switch(comm){
            case "Start":
                myaction(1);
                break;
            case "Stop":
                myaction(0);
                break;
            case "Pause":
                if(nowstate==2){
                    myaction(1);
                }else{
                    myaction(2);
                }
                
                break;
            case "Restart":
                myaction(0);
                myaction(1);
                break;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        
    }
}