import java.io.File;
import java.util.Scanner;

public class MainClass
{
    public static void main(String[] args)
    {
        File f = new File("asciiart.txt");
        try
        {
            Scanner s = new Scanner(f);
            while (s.hasNext())
            {
                System.out.println("  cout << \"" +  s.nextLine() + "\" << endl;");
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}