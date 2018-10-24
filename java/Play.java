abstract class Player{
    public abstract void Play();
}

class Avi extends Player{

    public void Play(){
        System.out.println("This is Avi!");
    }
}

class Mp4 extends Player{

    public void Play(){
        System.out.println("This is Mp4!");
    }
}

public class Play{
    public static void main(String[] args) {
        String filename="./test.mp4";
        if(args.length==1){
            filename=args[0];
        }
        filename=filename.toLowerCase();

        int index=filename.lastIndexOf(".");
        String filetype = filename.substring(index + 1);
        
        Player Players;
        switch (filetype){
            case "avi":
                Players=new Avi();
                Players.Play();
                break;
            case "mp4":
                Players=new Mp4();
                Players.Play();
                break;
            default:
                System.out.println("No Support!");
        }
    
    }
} 
