public class Shape{

    public int type;   //类型
    public int direction;  //方向

    /**
     * 图形数据
     */
    private final int cell[][][]=new int[][][] {
        {
            {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
            {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}
        },
        {
            {0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0},
            {1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
            {0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0},
            {1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0}
        },
        {
            {1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
            {0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0},
            {1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
            {0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0}
        },
        {
            {0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0},
            {1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
            {1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0},
            {1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0}
        },
        {
            {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
            {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
            {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
            {1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0}
        },
        {
            {1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0},
            {1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
            {1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
            {0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0}
        },
        {
            {0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
            {0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
            {1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0},
            {0,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0}
        }
    };

    /*
    *   随机获取一个
    */
    public int[] getOne() {
        type = (int)(Math.random()*1000)%7;
        direction = (int)(Math.random()*1000)%4;
        return cell[type][direction];
    }

    /**
     * 当次图形旋转变化
     * @param type 定义图形类型
     * @return
     */
    public int[] getDeform(int type) {
        direction = (direction+1)%4;
        return cell[type][direction];
    }

}