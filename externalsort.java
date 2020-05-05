import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;

public class external
{
    static int N = 2000000; 
    static int M = 100000; 
    

    public static void externalSort(String fileName){
        String tfile = "temp-file-"; 
        int[] buffer = new int[M < N ? M : N]; 

        try{
            FileReader fr = new FileReader(fileName);
            BufferedReader br = new BufferedReader(fr);
            int slices = (int) Math.ceil((double) N/M); 
         

            int i=0;
            int j=0;
             
            for(i=0;i<slices;i++){
               

                for(j=0;j<(M<N ? M : N);j++){
                    String t = br.readLine();
                    if(t!=null) buffer[j] = Integer.parseInt(t);
                    else break;
                }
                Arrays.sort(buffer); 


                
                FileWriter fw = new FileWriter(tfile+Integer.toString(i)+".txt");
                PrintWriter pw = new PrintWriter(fw);

                for(int k=0;k<j;k++){
                    pw.println(buffer[k]);
                }

                //closing filewriter and printwriter
                pw.close();
                fw.close();
            }

            br.close();
            fr.close();

 
            int[] topNums = new int[slices];
            BufferedReader[] brs = new BufferedReader[slices];

            for(i=0;i<slices;i++){
                brs[i] = new BufferedReader(new FileReader(tfile+Integer.toString(i)+".txt"));
                String t = brs[i].readLine();
                if(t!=null) topNums[i] = Integer.parseInt(t);
                else topNums[i] = Integer.MAX_VALUE;
            }

            FileWriter fw = new FileWriter("C:\\Users\\Ayush\\Documents\\externalsort.txt");
            PrintWriter pw = new PrintWriter(fw);

            for(i = 0;i<N;i++){
                int min = topNums[0];
                int minFile = 0;

                for(j=0;j<slices;j++){
                    if(min > topNums[j]){
                        min = topNums[j];
                        minFile = j;
                    }
                }

                pw.println(min);
                String t = brs[minFile].readLine();
                if(t!=null) topNums[minFile] = Integer.parseInt(t);
                else topNums[minFile] = Integer.MAX_VALUE;

            }

            for(i=0;i<slices;i++) brs[i].close();
            pw.close();
            fw.close();
        }
        catch(FileNotFoundException E)
        {
            E.printStackTrace();
        } 
        catch(IOException E)
        {
            E.printStackTrace();
        }
    }
    static String generateInput(int n){
        String fileName = "externalsort.txt";
        Random rand = new Random();

        try{
            FileWriter fw = new FileWriter(fileName);
            PrintWriter pw = new PrintWriter(fw);

            for(int i=0;i<n;i++){
                pw.println(rand.nextInt(101));
            }
            pw.close();
        }
        catch (IOException E){
            E.printStackTrace();
        }
        return fileName;
    }

    public static void main(String[] args) {
        String fileName = generateInput(N);
        externalSort(fileName);
    }
}